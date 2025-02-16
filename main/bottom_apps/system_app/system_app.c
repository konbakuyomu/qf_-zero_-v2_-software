#include "system_app.h"
#include "peripheral_interface.h"
#include "hc32_trans_interface.h"
#include "lcd_driver_interface.h"
#include "device_interfaces.h"

#include "usb_trans_app.h"
#include "hc32_trans_app.h"
#include "system_app.h"
#include "btn_event_app.h"

#include "desktop.h"

/**
 * @brief 系统参数
 */
typedef struct
{
    uint8_t lcd_blk;            // 背光亮度
    clock_time_t time;          // 时间
    uint32_t screen_rest_count; // 休眠计数
    cw2015_bat_info_t bat_info; // 电池信息
    uint8_t soft_version[3];    // 固件版本号
} system_data_t;

/**
 * @brief eeprom参数
 */
typedef struct
{
    uint32_t screen_rest_sec; // 休眠时长
} system_eeprom_t;

/**
 * @brief 系统参数
 */
typedef struct
{
    system_data_t data;
    system_eeprom_t eeprom;
} system_paras_t;

static system_paras_t sys_paras;
static RTC_FAST_ATTR uint8_t blk_save = 50;
static RTC_FAST_ATTR uint8_t wake_mode = power_on;
static RTC_FAST_ATTR uint32_t rest_secont_save = system_rest_sec_default;
static uint8_t low_blk_en = 0;

extern void app_startup_list();
static void system_power_off_cb(void *value, size_t lenth);

// static void load_desktop_cb(lv_timer_t *e)
// {
// }

void system_get_soft_version(uint8_t *ver)
{
    memcpy(ver, sys_paras.data.soft_version, sizeof(sys_paras.data.soft_version));
}

void system_init()
{
    device_interface_init(); // 初始化接口程序

    trans_packer_handle_t *hanlde;
    key_value_msg("hc32_handle", &hanlde, 0);
    trans_packer_send_pack(hanlde, "wake", NULL, 0); // 下发指令给副处理器通知ESP已唤醒

    system_app_install();     // 安装系统APP
    hc32_trans_app_install(); // 安装协处理器通信APP
    usb_trans_app_install();  // 安装串口驱动程序
    btn_event_app_install();  // 安装按键事件管理APP

    system_take_gui_key();
    app_startup_list(); // 初始化应用程序

    desktop_app_install();                      // 安装桌面APP,放在最后
    app_load("desktop", app_handle_none, NULL); // 加载桌面
    system_give_gui_key();
}

static void system_data_init()
{
    memset(&sys_paras, 0, sizeof(system_paras_t));
    sys_paras.data.lcd_blk = blk_save;
    sys_paras.eeprom.screen_rest_sec = rest_secont_save;
    const uint8_t version_tmp[3] = {software_version};
    memcpy(sys_paras.data.soft_version, version_tmp, sizeof(version_tmp));
}

static void system_data_save()
{
    // printf("here\n");
    // if (low_blk_en == 0)
    //    blk_save = sys_paras.data.lcd_blk;
}

static void clock_run_tsak(void *arg) // 时间运行任务
{
    static uint8_t usb_sta = 0;
    sys_paras.data.time.sec++;
    if (sys_paras.data.time.sec == 60)
    {
        sys_paras.data.time.sec = 0;
        sys_paras.data.time.min++;
        if (sys_paras.data.time.min == 60)
        {
            sys_paras.data.time.min = 0;
            sys_paras.data.time.hour++;
            if (sys_paras.data.time.hour == 24) // 到新的一天
            {
                sys_paras.data.time.hour = 0;
                trans_packer_handle_t *hanlde;
                key_value_msg("hc32_handle", &hanlde, 0);
                trans_packer_send_pack(hanlde, "get_time", NULL, 0); // 下发指令给副处理器上传时间信息进行同步
            }
        }
    }

    if (usb_sta != per_get_usb_online_sta())
    {
        usb_sta = !usb_sta;
        sys_paras.data.screen_rest_count = 0;
    }

    sys_paras.data.screen_rest_count++;
    static uint8_t low_blk_cnt = 0;

    if (sys_paras.data.screen_rest_count >= sys_paras.eeprom.screen_rest_sec)
    {
        if (low_blk_cnt == 0)
        {
            if (blk_save < 5)
                sys_paras.data.lcd_blk = 1;
            else
                sys_paras.data.lcd_blk = 5;
        }
        low_blk_cnt++;
        if (low_blk_cnt == 5)
            system_deep_sleep_start();
    }
    else
    {
        if (low_blk_cnt)
            sys_paras.data.lcd_blk = blk_save;
        low_blk_cnt = 0;
        low_blk_en = 0;
    }
    cw2015_get_info(&sys_paras.data.bat_info);
}

static void lcd_blk_task(void *arg)
{
    uint8_t now_blk = 0;
    for (;;)
    {
        vTaskDelay(10);
        if (now_blk == sys_paras.data.lcd_blk)
            continue;
        if (now_blk < sys_paras.data.lcd_blk)
            now_blk++;
        else if (now_blk > sys_paras.data.lcd_blk)
            now_blk--;
        lcd_set_blk(now_blk);
    }
}

// static void per_info_updata_task(btask_event_t *arg)
// {

// }

void system_upload_time(clock_time_t time)
{
    time.week = system_day_count_week(time.year, time.month, time.day);
    sys_paras.data.time = time;
}

static void system_upload_time_cb(void *value, size_t lenth)
{
    system_upload_time(*(clock_time_t *)value);
}

void system_set_time(clock_time_t time)
{
    system_upload_time(time);
    uint8_t tmp[6] = {
        time.year,
        time.month,
        time.day,
        time.hour,
        time.min,
        time.sec};
    hc32_trans_send_pack("set_time", tmp, sizeof(tmp));
}

static void system_set_time_cb(void *value, size_t lenth)
{
    system_set_time(*(clock_time_t *)value);
}

void system_get_time(clock_time_t *time)
{
    *time = sys_paras.data.time;
}

static void system_get_time_cb(void *value, size_t lenth)
{
    *(clock_time_t *)value = sys_paras.data.time;
}

void system_screen_rest_clr()
{
    sys_paras.data.screen_rest_count = 0;
}

static void system_screen_rest_clr_cb(void *value, size_t lenth)
{
    sys_paras.data.screen_rest_count = 0;
}

void system_set_screen_rest(uint32_t rest_sec)
{
    if (rest_sec < 3)
        return;
    sys_paras.eeprom.screen_rest_sec = rest_sec;
    sys_paras.data.screen_rest_count = 0;
    if (rest_sec != screen_always_on)
        rest_secont_save = rest_sec;
}

static void system_set_screen_rest_cb(void *value, size_t lenth)
{
    system_set_screen_rest(*(uint32_t *)value);
}

uint32_t system_get_screen_rest()
{
    return (sys_paras.eeprom.screen_rest_sec);
}

void system_screen_keep_on(uint8_t en)
{
    static uint32_t blk_save_rec = 0;
    static size_t _en = 0;
    static uint8_t _busy = 0;

    while (_busy)
        ;
    _busy = 1;

    if (en == 0 && _en == 0) // all false
    {
        _busy = 0;
        return;
    }

    if (_en && en) // all true
    {
        _en++;
        _busy = 0;
        return;
    }
    if (_en > 1 && en == 0)
    {
        _en--;
        _busy = 0;
        return;
    }

    if (en)
        _en++;
    else
        _en--;

    if (en)
    {
        blk_save_rec = system_get_screen_rest();
        system_set_screen_rest(screen_always_on);
    }
    else
    {
        system_screen_rest_clr();
        system_set_screen_rest(blk_save_rec);
    }
    _busy = 0;
}

static void system_screen_keep_on_cb(void *value, size_t lenth)
{
    system_screen_keep_on(*(uint8_t *)value);
}

static void system_get_screen_rest_cb(void *value, size_t lenth)
{
    *(uint32_t *)value = system_get_screen_rest();
}

void system_set_blk(uint8_t blk)
{
    if (blk < 1)
        blk = 1;
    sys_paras.data.lcd_blk = blk;
    blk_save = blk;
}

static void system_set_blk_cb(void *value, size_t lenth)
{
    system_set_blk(*(uint8_t *)value);
}

uint8_t system_get_blk()
{
    return sys_paras.data.lcd_blk;
}

static void system_get_blk_cb(void *value, size_t lenth)
{
    *(uint8_t *)value = system_get_blk();
}

void system_upload_bat(cw2015_bat_info_t *info)
{
    sys_paras.data.bat_info = *info;
}

static void system_upload_bat_cb(void *value, size_t lenth)
{
    system_upload_bat((cw2015_bat_info_t *)value);
}

void system_set_bat(uint8_t low_soc)
{
    if (low_soc > 30 || low_soc < 1)
        return;

    sys_paras.data.bat_info.low_soc = low_soc;

    hc32_trans_send_pack("low_soc", &low_soc, sizeof(low_soc));
}

static void system_set_bat_cb(void *value, size_t lenth)
{
    system_set_bat(*(uint8_t *)value);
}

void system_get_bat(cw2015_bat_info_t *info)
{
    *info = sys_paras.data.bat_info;
}

static void system_get_bat_cb(void *value, size_t lenth)
{
    *(cw2015_bat_info_t *)value = sys_paras.data.bat_info;
}

void system_set_motor(uint8_t var)
{
    per_motor_set(var);
}

static void system_set_motor_cb(void *value, size_t lenth)
{
    per_motor_set(*(uint8_t *)value);
}

uint8_t system_get_usb_sta()
{
    return per_get_usb_online_sta();
}

static void system_get_usb_sta_cb(void *value, size_t lenth)
{
    *(uint8_t *)value = system_get_usb_sta();
}

void system_deep_sleep_start()
{
    hc32_trans_send_pack("hc_sleep", NULL, 0);
    wake_mode = wake_up;
    app_close(app_get_loaded()->name, app_handle_none, NULL);
    app_kill_all();
    printf("sleep start\n");
    vTaskDelay(5);
    esp_deep_sleep_start();
}

static void system_sleep_cb(void *value, size_t lenth)
{
    system_deep_sleep_start();
}

void system_restart()
{
    app_kill_all();
    app_power_off_all();
    esp_restart();
}

static void system_restart_cb(void *value, size_t lenth)
{
    system_restart();
}

system_wake_t system_get_power_on_mode()
{
    return wake_mode;
}

static void system_get_power_on_mode_cb(void *value, size_t lenth)
{
    *(system_wake_t *)value = wake_mode;
}

static void system_take_gui_key_cb(void *value, size_t lenth)
{
    system_take_gui_key();
}

static void system_give_gui_key_cb(void *value, size_t lenth)
{
    system_give_gui_key();
}

uint8_t system_get_tp_type()
{
    if (cst816_read_slide_type() == cst816_slided)
        return 1;
    else
        return 0;
}

static void system_get_tp_type_cb(void *value, size_t lenth)
{
    *(uint8_t *)value = system_get_tp_type();
}

static void sys_app_init(void *arg)
{
    system_data_init();

    const esp_timer_create_args_t ms_tick_timer_args = {// 心跳定时器
                                                        .callback = &clock_run_tsak,
                                                        .name = "clock"};
    esp_timer_handle_t ms_tick_timer = NULL;
    esp_timer_create(&ms_tick_timer_args, &ms_tick_timer);
    esp_timer_start_periodic(ms_tick_timer, 1000 * 1000);

    xTaskCreate(lcd_blk_task, "blk_task", 1024 * 2, NULL, configMAX_PRIORITIES, NULL); // 背光管理任务

    key_value_register(NULL, "tp_type", system_get_tp_type_cb); // 订阅获取TP操作类型事件

    key_value_register(NULL, "take_gui_key", system_take_gui_key_cb); // 订阅获取GUI增删权限事件
    key_value_register(NULL, "give_gui_key", system_give_gui_key_cb); // 订阅归还GUI增删权限事件

    key_value_register(NULL, "sys_always_on", system_screen_keep_on_cb); // 订阅背光常亮事件
    key_value_register(NULL, "sys_set_rest", system_set_screen_rest_cb); // 订阅设置息屏时间事件
    key_value_register(NULL, "sys_get_rest", system_get_screen_rest_cb); // 订阅设置息屏时间事件
    key_value_register(NULL, "sys_clr_rest", system_screen_rest_clr_cb); // 订阅重置息屏时间事件

    key_value_register(NULL, "sys_set_blk", system_set_blk_cb); // 订阅设置背光事件
    key_value_register(NULL, "sys_get_blk", system_get_blk_cb); // 订阅获取背光事件

    key_value_register(NULL, "sys_up_time", system_upload_time_cb); // 订阅更新时间事件
    key_value_register(NULL, "sys_set_time", system_set_time_cb);   // 订阅设置时间事件
    key_value_register(NULL, "sys_get_time", system_get_time_cb);   // 订阅获取时间事件

    key_value_register(NULL, "sys_up_bat", system_upload_bat_cb); // 订阅更新电池信息事件
    key_value_register(NULL, "sys_set_bat", system_set_bat_cb);   // 订阅设置电池报警值事件
    key_value_register(NULL, "sys_get_bat", system_get_bat_cb);   // 订阅获取电池信息事件

    key_value_register(NULL, "sys_set_motor", system_set_motor_cb);         // 订阅设置振动器强度事件
    key_value_register(NULL, "sys_usb_sta", system_get_usb_sta_cb);         // 订阅获取USB连接状态事件
    key_value_register(NULL, "sys_wake_mode", system_get_power_on_mode_cb); // 订阅获取唤醒模式事件

    key_value_register(NULL, "sys_power_off", system_power_off_cb); // 订阅关机事件
    key_value_register(NULL, "sys_restart", system_restart_cb);     // 订阅重启事件
    key_value_register(NULL, "sys_sleep", system_sleep_cb);         // 订阅休眠 事件

    cw2015_get_info(&sys_paras.data.bat_info); // 同步一次电池信息
}

static void system_app_kill(void *arg)
{
    system_data_save();
}

void system_power_off(void *arg)
{
    hc32_trans_send_pack("hc_sleep", NULL, 0);
    vTaskDelay(5);
    app_close(app_get_loaded()->name, app_handle_none, NULL);
    wake_mode = power_on;
    app_kill_all();
    app_power_off_all();
    printf("power off\n");
    esp_deep_sleep_start();
}

static void system_power_off_cb(void *value, size_t lenth)
{
    system_power_off(NULL);
}

void system_app_install()
{
    app_config_t cfg = {
        .app_close = NULL,
        .app_init = sys_app_init,
        .app_kill = system_app_kill,
        .app_load = NULL,
        .app_power_off = system_power_off,
        .has_gui = 0,
        .icon = NULL,
        .name = "system"};
    app_install(&cfg, NULL);
}
