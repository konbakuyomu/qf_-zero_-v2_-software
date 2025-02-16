#include "button.h"
#if BUTTON_NUM

static uint8_t button_io_num[BUTTON_NUM] = {255};   // 按键数字
static uint8_t button_trig_level[BUTTON_NUM] = {0}; // 按键触发电平
static uint8_t button_now_level[BUTTON_NUM] = {0};  // 按键当前电平
static uint8_t button_low_count[BUTTON_NUM] = {0};
static uint8_t button_high_count[BUTTON_NUM] = {0};

#if btn_long_press_en
static uint8_t long_flg[BUTTON_NUM] = {0};
static uint16_t button_long_t[BUTTON_NUM] = {0}; // 长按扫描计时
#endif
#if btn_double_click_en
static uint8_t double_flg[BUTTON_NUM] = {0};
static uint16_t button_double_t[BUTTON_NUM] = {0}; // 双击扫描计时
#endif

static btn_event_t button_event_ret[BUTTON_BUFFER_NUM] = {btn_not_press}; // 缓冲区事件
static uint8_t button_event_io[BUTTON_BUFFER_NUM] = {0};                  // 缓冲区io口数字

static uint8_t (*_func_cb)(uint8_t io_num) = NULL; // 读取IO回调函数指针
static uint8_t button_event_num = 0;               // 缓冲区事件数
static uint8_t button_event_write_ptr = 0;         // 缓冲区写入移动指针
static uint8_t button_event_read_ptr = 0;          // 缓冲区读取移动指针

static uint8_t button_event_en_state = 0xff;

// static uint8_t init_flg = 1;

#if btn_long_press_trig_en
static uint8_t long_trig_flg = 0;
static btn_event_t long_trig_type = btn_click;
static uint16_t long_trig_time = btn_long_press_trig_interval_time;
static uint16_t long_trig_count = 0;
static uint16_t long_trig_long_count = 0;
static uint16_t long_trig_long_time = btn_long_press_continuous_trig_time / 5;
static long_press_trig_cb_t long_trig_cb = NULL;
static void *long_trig_userdata = NULL;

void btn_long_press_trig_event(btn_event_t type)
{
    if (type == btn_event_all)
        return;
    long_trig_type = type;
}

// void btn_long_press_trig_enable(uint8_t en)
// {
//     if (en > 1)
//         return;
//     long_trig_flg = en;
// }

void btn_long_press_trig_time(uint16_t ms)
{
    long_trig_time = ms;
}

void btn_attach_long_press_trig_cb(long_press_trig_cb_t cb, void *userdata)
{
    long_trig_cb = cb;
    long_trig_userdata = userdata;
}

void btn_detach_long_press_trig_cb()
{
    long_trig_cb = NULL;
    long_trig_userdata = NULL;
}

#endif

uint8_t btn_available(void)
{
    return button_event_num;
}

uint8_t btn_attach(uint8_t io_num, uint8_t level)
{
    uint8_t i;
    if (level != 0 && level != 1)
        return 0;
    for (i = 0; i < BUTTON_NUM; i++)
    {
        if (button_io_num[i] == 0xff)
        {
            button_io_num[i] = io_num;
            button_trig_level[i] = level;
            button_now_level[i] = !level;
            return 1;
        }
    }
    return 0;
}

void btn_detach(uint8_t io_num)
{
    uint8_t i;
    for (i = 0; i < BUTTON_NUM; i++)
    {
        if (button_io_num[i] == io_num)
        {
            button_io_num[i] = 0xff;
            return;
        }
    }
}

static void button_write_buffer(uint8_t io_num, btn_event_t ret)
{
    if ((button_event_en_state & ret) == 0)
        return;
    button_event_ret[button_event_write_ptr] = ret;
    button_event_io[button_event_write_ptr++] = io_num;
    if (button_event_write_ptr == BUTTON_BUFFER_NUM)
        button_event_write_ptr = 0;
    if (button_event_num < BUTTON_BUFFER_NUM)
        button_event_num++;
}

void btn_tic_ms(uint8_t _ms)
{
    static uint8_t i;
    static uint8_t change_flg = 0;
    if (_func_cb == NULL)
        return;

    for (i = 0; i < BUTTON_NUM; i++)
    {
        if (button_io_num[i] == 0xff)
            continue;
        if (_func_cb(button_io_num[i])) // 高电平
        {
            button_low_count[i] = 0;                 // 清空低计数
            if (button_high_count[i] < btn_shake_ms) // 消抖计数
                button_high_count[i] += _ms;
            else if (button_now_level[i] == 0) // 消抖时间达到且上一次为低电平
            {
                change_flg = 1;          // 事件标志
                button_now_level[i] = 1; // 翻转电平
            }
        }
        else // 低电平
        {
            button_high_count[i] = 0;
            if (button_low_count[i] < btn_shake_ms)
                button_low_count[i] += _ms;
            else if (button_now_level[i] == 1)
            {
                change_flg = 1;
                button_now_level[i] = 0;
            }
        }

        ////////////////////////////////////////////////////////////

        if (button_now_level[i] == button_trig_level[i]) // 按键按下
        {
            if (change_flg == 1) // 按键翻转
            {
                change_flg = 0;
#if btn_down_en
                button_write_buffer(button_io_num[i], btn_down);
#endif
#if btn_long_press_en
                if ((button_event_en_state & btn_long_press) != 0)
                {
                    long_flg[i] = 1; // 长按预备标志
                    button_long_t[i] = 0;
                }
#endif
#if btn_double_click_en
                if ((button_event_en_state & btn_double_click) != 0)
                {
                    if (double_flg[i] == 0)
                    {
                        double_flg[i] = 1;
                        button_double_t[i] = 0;
                    }
                    else if (double_flg[i] == 1)
                    {
                        button_write_buffer(button_io_num[i], btn_double_click);
                        double_flg[i] = 2;
                    }
                }
#endif
            }
            //////////////////////////////////////////////////////////////////////////
#if btn_long_press_en             // 使能长按
            if (long_flg[i] == 1) // 长按计时中
            {
                button_long_t[i] += _ms;
                if (button_long_t[i] >= btn_long_press_time_default)
                {
                    button_write_buffer(button_io_num[i], btn_long_press);
                    long_flg[i] = 0;
                }
            }
#endif
#if btn_long_press_trig_en // 长按触发事件
            if (button_event_en_state & btn_long_press_trig)
            {
                if (long_trig_long_count < long_trig_long_time)
                    long_trig_long_count++;
                else
                {
                    long_trig_count += _ms;
                    if (long_trig_count >= long_trig_time)
                    {
                        if (long_trig_flg == 0)
                        {
                            if (long_trig_cb != NULL)
                                long_trig_cb(long_trig_userdata);
                            long_trig_flg = 1;
                        }
                        long_trig_count -= long_trig_time;
                        button_write_buffer(button_io_num[i], long_trig_type);
                    }
                }
            }
#endif
        }                         ///////////////////////////////////////////////////////////////////
        else if (change_flg == 1) // 弹起
        {
#if btn_long_press_trig_en // 长按触发事件
            long_trig_count = 0;
            long_trig_long_count = 0;
            long_trig_flg = 0;
#endif
            change_flg = 0;
            ///////////////////////////////////////////
#if btn_long_press_en // 长按开启
            {
                if (long_flg[i] == 1) // 按键时间短于长按
                {
                    long_flg[i] = 0;       // 清除标志89
#if (!btn_double_click_en && btn_click_en) // 未启用双击//启用了单击
                    button_write_buffer(button_io_num[i], btn_click);
#endif
#if btn_double_click_en && btn_click_en
                    if ((button_event_en_state & btn_double_click) == 0) // 关闭双击使能
                        button_write_buffer(button_io_num[i], btn_click);
#endif
                }
#if btn_double_click_en && btn_click_en
                if ((button_event_en_state & btn_long_press) == 0) // 长按动态关闭
                {
                    if ((button_event_en_state & btn_double_click) == 0) // 关闭双击使能
                        button_write_buffer(button_io_num[i], btn_click);
                }
#endif
            }
#else
#if btn_double_click_en && btn_click_en
            if ((button_event_en_state & btn_double_click) == 0) // 关闭双击使能
                button_write_buffer(button_io_num[i], btn_click);
            else if (double_flg[i] == 0)
                button_write_buffer(button_io_num[i], btn_click);
#endif
#endif
            ///////////////////////////////////////////

#if btn_up_en // 弹起编译使能
            button_write_buffer(button_io_num[i], btn_up);
#endif
#if (btn_long_press_en == 0 && btn_double_click_en == 0 && btn_click_en) // 未启用长按、双击，启用单击时
            button_write_buffer(button_io_num[i], btn_click);
#endif
#if btn_double_click_en
            if (double_flg[i] == 2)
                double_flg[i] = 0;
#endif
        }
/////////////////////////////////////////////////////////////////////////////////////////////////////////
#if btn_double_click_en         // 启用双击
        if (double_flg[i] == 1) // 启用双击且在计时
        {
            button_double_t[i] += _ms;
            if (button_double_t[i] >= btn_double_click_time_default)
            {
#if (btn_long_press_en && btn_click_en)
                if (long_flg[i] == 0)
                {
#endif
#if btn_click_en
                    if (button_now_level[i] != button_trig_level[i])
                        button_write_buffer(button_io_num[i], btn_click);

#endif
#if (btn_long_press_en && btn_click_en)
                }
#endif
                double_flg[i] = 0;
            }
        }
#endif
    }
}

void btn_attach_read_io_func(uint8_t (*func)(uint8_t io_num))
{
    _func_cb = func;
    memset(button_io_num, 255, BUTTON_NUM);
#if btn_long_press_en
    memset(long_flg, 0, BUTTON_NUM);
#endif
#if btn_double_click_en
    memset(double_flg, 0, BUTTON_NUM);
#endif
    button_event_write_ptr = 0;
    button_event_read_ptr = 0;
    button_event_num = 0;
    button_event_en_state = 0;
    button_event_en_state |= btn_down_en;
    button_event_en_state |= btn_up_en << 1;
    button_event_en_state |= btn_long_press_en << 2;
    button_event_en_state |= btn_click_en << 3;
    button_event_en_state |= btn_double_click_en << 4;
    button_event_en_state |= btn_long_press_trig_en << 5;
}

void btn_read_event(uint8_t *io_num, btn_event_t *ret)
{
    if (button_event_num == 0)
    {
        if (io_num != NULL)
            *io_num = 255;
        if (ret != NULL)
            *ret = btn_not_press;
        return;
    }
    if (io_num != NULL)
        *io_num = button_event_io[button_event_read_ptr];
    if (ret != NULL)
        *ret = button_event_ret[button_event_read_ptr];
    button_event_read_ptr++;
    if (button_event_read_ptr == BUTTON_BUFFER_NUM)
        button_event_read_ptr = 0;
    button_event_num--;
}

void btn_enable_event(uint8_t cfg_t)
{
    button_event_en_state |= cfg_t;
}

void btn_disable_event(uint8_t cfg_t)
{
    button_event_en_state &= ~cfg_t;
}

#endif
