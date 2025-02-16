#include "system_app.h"
#include "desktop.h"
#include "weather_app.h"

static const char *ui_name = "qf_watch_01"; // 表盘名称

LV_IMG_DECLARE(watch_01_img_bg);
LV_IMG_DECLARE(watch_01_img_hour);
LV_IMG_DECLARE(watch_01_img_min);
LV_IMG_DECLARE(watch_01_img_sec);
LV_IMG_DECLARE(watch_01_img_week);
LV_IMG_DECLARE(watch_01_img_bat_line);
LV_IMG_DECLARE(watch_01_img_char_temp);
LV_IMG_DECLARE(watch_01_img_weather_icon);
LV_IMG_DECLARE(watch_01_img_num_time);
LV_IMG_DECLARE(watch_01_img_altitude);
LV_IMG_DECLARE(watch_01_img_flash_red);
LV_IMG_DECLARE(watch_01_img_flash_green);

LV_FONT_DECLARE(watch_01_font);

typedef struct
{
    lv_obj_t *label_bat_dig;
    lv_obj_t *img_bat_bg[2];
    lv_obj_t *label_day;
    lv_obj_t *img_time[5];

    lv_obj_t *img_week;
    lv_obj_t *img_wea_icon;
    lv_obj_t *label_wea_temp;
    lv_obj_t *label_step_ka;
    lv_obj_t *label_step;
    lv_obj_t *label_altitude;

    lv_obj_t *img_flash;

    lv_obj_t *img_hour;
    lv_obj_t *img_min;
    lv_obj_t *img_sec;

} ref_objs_t;

typedef enum
{
    anim_over,
    anim_ready,
    anim_doing
} time_anim_t;

static lv_timer_t *data_ref_timer = NULL;
static ref_objs_t *ref_objs = NULL;
static time_anim_t anim_flg = anim_over;
static lv_anim_t *sec_anim = NULL;
static lv_anim_t *sec_run_anim = NULL;
static lv_anim_t *min_anim = NULL;
static lv_anim_t *hour_anim = NULL;
static uint8_t data_ref_flg = 2;
////////////////////////////////////

static void _ui_anim_callback_set_image_angle(lv_anim_t *a, int32_t v)
{
    lv_img_set_angle((lv_obj_t *)a->user_data, v);
}
static int32_t _ui_anim_callback_get_image_angle(lv_anim_t *a)
{
    return lv_img_get_angle((lv_obj_t *)a->user_data);
}

static void scr_load_cb(lv_event_t *e)
{
    data_ref_flg++;
    lv_timer_resume(data_ref_timer);
    if (anim_flg == anim_over)
        anim_flg = anim_ready;
}

static void scr_unload_cb(lv_event_t *e)
{
    lv_timer_pause(data_ref_timer);
    if (sec_anim != NULL)
    {
        lv_anim_del(sec_anim, NULL);
        sec_anim = NULL;
    }

    if (sec_run_anim != NULL)
    {
        lv_anim_del(sec_run_anim, NULL);
        sec_run_anim = NULL;
    }

    if (min_anim != NULL)
    {
        lv_anim_del(min_anim, NULL);
        min_anim = NULL;
    }
    if (hour_anim != NULL)
    {
        lv_anim_del(hour_anim, NULL);
        hour_anim = NULL;
    }
}

static void _sec_anim_over_cb(lv_anim_t *a)
{
    anim_flg = anim_over;
}

static void _sec_anim_cb(lv_anim_t *a)
{
    if (sec_run_anim != NULL)
        return;
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_image_angle);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
    lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_image_angle);

    lv_anim_set_repeat_count(&PropertyAnimation_0, LV_ANIM_REPEAT_INFINITE);

    lv_anim_set_time(&PropertyAnimation_0, 60 * 1000); // 60000
    lv_anim_set_user_data(&PropertyAnimation_0, ref_objs->img_sec);
    lv_anim_set_values(&PropertyAnimation_0, 0, 3600);
    sec_run_anim = lv_anim_start(&PropertyAnimation_0);
}

//////////////////////////////////////

static void _ref_bat()
{
    static uint8_t last_usb_sta = 255;
    uint8_t usb_sta = 0;

    key_value_msg("sys_usb_sta", &usb_sta, sizeof(usb_sta));
    if (last_usb_sta != usb_sta)
    {
        last_usb_sta = usb_sta;
        if (last_usb_sta)
            lv_img_set_src(ref_objs->img_flash, &watch_01_img_flash_green);
        else
            lv_img_set_src(ref_objs->img_flash, &watch_01_img_flash_red);
    }

    uint8_t last_soc = 255;
    cw2015_bat_info_t bat_info;
    key_value_msg("sys_get_bat", &bat_info, sizeof(bat_info));

    if (last_soc == bat_info.soc && data_ref_flg == 0)
        return;

    last_soc = bat_info.soc;

    lv_label_set_text_fmt(ref_objs->label_bat_dig, "%d%%", last_soc);

    uint8_t bat_y_offset[2];
    bat_y_offset[0] = last_soc / 10;
    bat_y_offset[1] = 10 - bat_y_offset[0];
    lv_obj_set_width(ref_objs->img_bat_bg[0], bat_y_offset[1] * 7);
    lv_obj_set_width(ref_objs->img_bat_bg[1], bat_y_offset[0] * 7);

    lv_obj_align_to(ref_objs->img_bat_bg[1], ref_objs->img_bat_bg[0], LV_ALIGN_OUT_RIGHT_MID, 0, 0);
}

static void _ref_day_time()
{
    clock_time_t time;
    key_value_msg("sys_get_time", &time, sizeof(time));

    static clock_time_t last_time = {0, 0, 0, 0, 0, 0, 0};

    if (memcmp(&time, &last_time, sizeof(last_time)) == 0 && data_ref_flg == 0)
        return;

    if (anim_flg == anim_ready)
    {
        anim_flg = anim_doing;

        lv_anim_t PropertyAnimation_0;
        lv_anim_init(&PropertyAnimation_0);
        lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_image_angle);
        lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
        lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_image_angle);

        lv_anim_set_repeat_count(&PropertyAnimation_0, 0); // LV_ANIM_REPEAT_INFINITE;

        int16_t angle = time.sec * 60;
        int16_t angle_start = angle - 2200;
        if (angle_start < 0)
            angle_start += 3600;

        lv_anim_set_deleted_cb(&PropertyAnimation_0, _sec_anim_cb);
        lv_anim_set_time(&PropertyAnimation_0, 500); // 60000
        lv_img_set_angle(ref_objs->img_sec, angle_start);
        lv_anim_set_user_data(&PropertyAnimation_0, ref_objs->img_sec);
        lv_anim_set_values(&PropertyAnimation_0, 0, 2200);
        sec_anim = lv_anim_start(&PropertyAnimation_0);

        lv_anim_set_deleted_cb(&PropertyAnimation_0, NULL);

        angle = time.min * 60 + time.sec;
        angle_start = angle - 1800;
        if (angle_start < 0)
            angle_start += 3600;

        lv_anim_set_time(&PropertyAnimation_0, 750); // 60000
        lv_img_set_angle(ref_objs->img_min, angle_start);
        lv_anim_set_values(&PropertyAnimation_0, 0, 1800);
        lv_anim_set_user_data(&PropertyAnimation_0, ref_objs->img_min);
        min_anim = lv_anim_start(&PropertyAnimation_0);

        uint8_t tmp = time.hour;
        if (tmp >= 12)
            tmp -= 12;

        angle = tmp * 300 + time.min * 5;
        angle_start = angle - 1400;
        if (angle_start < 0)
            angle_start += 3600;

        lv_anim_set_time(&PropertyAnimation_0, 1000); // 60000
        lv_img_set_angle(ref_objs->img_hour, angle_start);
        lv_anim_set_values(&PropertyAnimation_0, 0, 1400);
        lv_anim_set_user_data(&PropertyAnimation_0, ref_objs->img_hour);
        lv_anim_set_deleted_cb(&PropertyAnimation_0, _sec_anim_over_cb);
        hour_anim = lv_anim_start(&PropertyAnimation_0);
    }

    if ((time.month != last_time.month || time.day != last_time.day) || data_ref_flg)
    {

        last_time.month = time.month;
        last_time.day = time.day;
        lv_label_set_text_fmt(ref_objs->label_day, "%d/%d", last_time.month, last_time.day);
    }

    if (time.week != last_time.week || data_ref_flg)
    {
        last_time.week = time.week;
        uint16_t angle;
        if (last_time.week < 5)
            angle = (float)last_time.week * 514.3;
        else
            angle = (float)last_time.week * 505.0;
        lv_img_set_angle(ref_objs->img_week, angle);
    }

    if (time.hour != last_time.hour || data_ref_flg)
    {
        last_time.hour = time.hour;
        uint8_t dat[2] = {time.hour / 10, time.hour % 10};
        for (size_t i = 0; i < 2; i++)
        {
            lv_img_set_offset_y(ref_objs->img_time[i], (-dat[i]) * 19);
        }
    }

    if (time.min != last_time.min || data_ref_flg)
    {
        last_time.min = time.min;
        uint8_t dat[2] = {time.min / 10, time.min % 10};
        for (size_t i = 0; i < 2; i++)
        {
            lv_img_set_offset_y(ref_objs->img_time[i + 2], (-dat[i]) * 19);
        }
        if (anim_flg == anim_over)
        {
            uint8_t tmp = time.hour;
            if (tmp >= 12)
                tmp -= 12;
            lv_img_set_angle(ref_objs->img_hour, tmp * 300 + time.min * 5);
        }
    }

    if (time.sec != last_time.sec || data_ref_flg)
    {
        last_time.sec = time.sec;
        if (lv_obj_has_flag(ref_objs->img_time[4], LV_OBJ_FLAG_HIDDEN))
            lv_obj_clear_flag(ref_objs->img_time[4], LV_OBJ_FLAG_HIDDEN);
        else
            lv_obj_add_flag(ref_objs->img_time[4], LV_OBJ_FLAG_HIDDEN);

        if (anim_flg == anim_over)
        {
            lv_img_set_angle(ref_objs->img_min, time.min * 60 + time.sec);
            // lv_img_set_angle(ref_objs->img_sec, time.sec * 60);
        }
    }
}

static void _ref_step()
{
    static uint32_t last_step = 0;
    uint32_t step;

    key_value_msg("mems_get_step", &step, sizeof(uint32_t));

    if (last_step == step && data_ref_flg == 0)
        return;
    last_step = step;

    if (last_step > 99999)
        last_step = 99999;

    lv_label_set_text_fmt(ref_objs->label_step, "%d", last_step);

    uint16_t ka = last_step * 0.045;

    lv_label_set_text_fmt(ref_objs->label_step_ka, "%d", ka);
}

static void _ref_weather()
{
    static weather_info_t last_weather;
    weather_info_t weather;
    key_value_msg("weather_get", &weather, sizeof(weather));

    if (weather.icon != last_weather.icon || data_ref_flg)
    {
        last_weather.icon = weather.icon;
        lv_img_set_offset_y(ref_objs->img_wea_icon, (-last_weather.icon) * 25);
    }

    if (weather.low_temp == last_weather.low_temp && weather.high_temp == last_weather.high_temp && data_ref_flg == 0)
        return;

    last_weather.low_temp = weather.low_temp;
    last_weather.high_temp = weather.high_temp;

    lv_label_set_text_fmt(ref_objs->label_wea_temp, "%d~%d", last_weather.low_temp, last_weather.high_temp);
}

static void _ref_altitude()
{
    static int16_t last_altitude = 32767;
    int16_t altitude = 0;

    key_value_msg("altitude_get", &altitude, sizeof(altitude));

    if (last_altitude == altitude && data_ref_flg == 0)
        return;
    last_altitude = altitude;

    lv_label_set_text_fmt(ref_objs->label_altitude, "%dm", last_altitude);
}

static void _scr_info_ref_cb(lv_timer_t *e)
{
    _ref_bat();
    _ref_day_time();
    _ref_step();
    _ref_weather();
    _ref_altitude();
    if (data_ref_flg)
    {
        data_ref_flg--;
        if (data_ref_flg == 0)
            lv_timer_set_period(data_ref_timer, 500);
    }
}

////////////////////////////////////////////////////////////////////////////////////////

static lv_obj_t *scr_load() // 表盘加载函数，返回表盘对象
{
    ref_objs = lv_mem_alloc(sizeof(ref_objs_t));

    lv_obj_t *scr = lv_obj_create(NULL);
    lv_obj_clear_flag(scr, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_add_event_cb(scr, scr_load_cb, LV_EVENT_SCREEN_LOAD_START, NULL);
    lv_obj_add_event_cb(scr, scr_unload_cb, LV_EVENT_SCREEN_UNLOAD_START, NULL);

    lv_obj_t *bg = lv_img_create(scr);
    lv_img_set_src(bg, &watch_01_img_bg);

    ////////////////////////海拔/////////////////////////////////////
    ref_objs->label_altitude = lv_label_create(scr);
    lv_obj_center(ref_objs->label_altitude);
    lv_obj_set_pos(ref_objs->label_altitude, 62, 57);
    lv_obj_set_style_text_color(ref_objs->label_altitude, lv_color_hex(0xffffff), LV_PART_MAIN);
    lv_obj_set_style_text_font(ref_objs->label_altitude, &watch_01_font, LV_PART_MAIN);
    ////////////////////////////天气//////////////////////////////

    ref_objs->label_wea_temp = lv_label_create(scr);
    lv_obj_center(ref_objs->label_wea_temp);
    lv_obj_set_pos(ref_objs->label_wea_temp, 3, -57);
    lv_obj_set_style_text_color(ref_objs->label_wea_temp, lv_color_hex(0xafafaf), LV_PART_MAIN);
    lv_obj_set_style_text_font(ref_objs->label_wea_temp, &watch_01_font, LV_PART_MAIN);

    lv_obj_t *temp_char = lv_img_create(scr);
    lv_img_set_src(temp_char, &watch_01_img_char_temp);
    lv_obj_set_height(temp_char, 9);
    lv_obj_center(temp_char);
    lv_obj_set_y(temp_char, -45);

    ref_objs->img_wea_icon = lv_img_create(scr);
    lv_img_set_src(ref_objs->img_wea_icon, &watch_01_img_weather_icon);
    lv_obj_set_height(ref_objs->img_wea_icon, 25);
    lv_obj_center(ref_objs->img_wea_icon);
    lv_obj_set_pos(ref_objs->img_wea_icon, 2, -76);

    ///////////////////////////////////////////////////////////

    ///////////////////////////时间日期///////////////////

    ref_objs->label_day = lv_label_create(scr);
    lv_obj_set_style_text_color(ref_objs->label_day, lv_color_hex(0xffffff), LV_PART_MAIN);
    lv_obj_set_style_text_font(ref_objs->label_day, &watch_01_font, LV_PART_MAIN);
    lv_obj_center(ref_objs->label_day);
    lv_obj_set_pos(ref_objs->label_day, 78, 20);

    ref_objs->img_time[4] = lv_img_create(scr); // 冒号
    lv_img_set_src(ref_objs->img_time[4], &watch_01_img_num_time);
    lv_img_set_offset_y(ref_objs->img_time[4], -19 * 10);
    lv_obj_set_height(ref_objs->img_time[4], 19);

    for (size_t i = 0; i < 4; i++) // 数字
    {
        ref_objs->img_time[i] = lv_img_create(scr);
        lv_img_set_src(ref_objs->img_time[i], &watch_01_img_num_time);
        lv_obj_set_height(ref_objs->img_time[i], 19);
    }
    lv_obj_center(ref_objs->img_time[0]); // 对齐最左边
    lv_obj_set_pos(ref_objs->img_time[0], 52, -5);

    lv_obj_align_to(ref_objs->img_time[1], ref_objs->img_time[0], LV_ALIGN_OUT_RIGHT_MID, -2, 0);
    lv_obj_align_to(ref_objs->img_time[4], ref_objs->img_time[1], LV_ALIGN_OUT_RIGHT_MID, -6, 0);
    lv_obj_align_to(ref_objs->img_time[2], ref_objs->img_time[4], LV_ALIGN_OUT_RIGHT_MID, -6, 0);
    lv_obj_align_to(ref_objs->img_time[3], ref_objs->img_time[2], LV_ALIGN_OUT_RIGHT_MID, -2, 0);
    ////////////////////////////////

    ///////////////////////////步数///////////////////

    ref_objs->label_step = lv_label_create(scr);
    lv_obj_set_style_text_color(ref_objs->label_step, lv_color_hex(0xffffff), LV_PART_MAIN);
    lv_obj_set_style_text_font(ref_objs->label_step, &watch_01_font, LV_PART_MAIN);
    lv_obj_center(ref_objs->label_step);
    lv_obj_set_pos(ref_objs->label_step, -82, 21);

    ref_objs->label_step_ka = lv_label_create(scr);
    lv_obj_center(ref_objs->label_step_ka);
    lv_obj_set_pos(ref_objs->label_step_ka, -52, -47);
    lv_obj_set_style_text_color(ref_objs->label_step_ka, lv_color_hex(0xffffff), LV_PART_MAIN);
    lv_obj_set_style_text_font(ref_objs->label_step_ka, &watch_01_font, LV_PART_MAIN);

    ////////////////////////////////

    ///////////////////////////电池/////////////////////////////

    ref_objs->img_flash = lv_img_create(scr);
    lv_obj_center(ref_objs->img_flash);
    lv_obj_set_pos(ref_objs->img_flash, 65, -63);

    ref_objs->label_bat_dig = lv_label_create(scr);
    lv_obj_set_style_text_color(ref_objs->label_bat_dig, lv_color_hex(0xafafaf), LV_PART_MAIN);
    lv_obj_set_style_text_font(ref_objs->label_bat_dig, &watch_01_font, LV_PART_MAIN);
    lv_obj_center(ref_objs->label_bat_dig);
    lv_obj_set_pos(ref_objs->label_bat_dig, 63, -47);

    for (size_t i = 0; i < 2; i++)
    {
        ref_objs->img_bat_bg[i] = lv_img_create(scr);
        lv_img_set_src(ref_objs->img_bat_bg[i], &watch_01_img_bat_line);
        lv_obj_set_height(ref_objs->img_bat_bg[i], 9);
    }
    lv_img_set_offset_y(ref_objs->img_bat_bg[0], -9);
    lv_obj_set_pos(ref_objs->img_bat_bg[0], 155, 83);
    ///////////////////////////////////////////////////////////////

    ref_objs->img_week = lv_img_create(scr);
    lv_img_set_src(ref_objs->img_week, &watch_01_img_week);
    lv_obj_center(ref_objs->img_week);
    lv_obj_set_pos(ref_objs->img_week, -4, 55);
    lv_img_set_pivot(ref_objs->img_week, 11, 29);

    ref_objs->img_hour = lv_img_create(scr);
    lv_img_set_src(ref_objs->img_hour, &watch_01_img_hour);
    lv_obj_set_y(ref_objs->img_hour, -69 / 2);
    lv_obj_set_align(ref_objs->img_hour, LV_ALIGN_CENTER);
    lv_img_set_pivot(ref_objs->img_hour, 6, 69);

    ref_objs->img_min = lv_img_create(scr);
    lv_img_set_src(ref_objs->img_min, &watch_01_img_min);
    lv_obj_set_y(ref_objs->img_min, -110 / 2);
    lv_obj_set_align(ref_objs->img_min, LV_ALIGN_CENTER);
    lv_img_set_pivot(ref_objs->img_min, 6, 110);

    ref_objs->img_sec = lv_img_create(scr);
    lv_img_set_src(ref_objs->img_sec, &watch_01_img_sec);
    lv_obj_set_y(ref_objs->img_sec, -125 / 2 + 31);
    lv_obj_set_align(ref_objs->img_sec, LV_ALIGN_CENTER);
    lv_img_set_pivot(ref_objs->img_sec, 9, 125 - 32);

    data_ref_flg = 2;
    data_ref_timer = lv_timer_create(_scr_info_ref_cb, 20, NULL);
    lv_timer_ready(data_ref_timer);
    
    return scr;
}

static void scr_close() // 表盘切换到后台函数
{
    lv_timer_del(data_ref_timer);
    data_ref_timer = NULL;
    lv_mem_free(ref_objs);
    ref_objs = NULL;
}

void watch_01_install() // 安装表盘
{
    desktop_ui_t cfg = {
        .name = ui_name,
        .ui_close = scr_close,
        .ui_load = scr_load};
    desktop_add_ui(&cfg);
}
