#include "Int_DigitalTube.h"
#define SMG_EN P36
#define LED_EN P34

static char s_digital_codes[10] = {
    0x3F, // 0
    0x06, // 1
    0x5B, // 2
    0x4F, // 3
    0x66, // 4
    0x6D, // 5
    0x7D, // 6
    0x07, // 7
    0x7F, // 8
    0x6F  // 9
};
static u8 s_digital_buffer[8];


/**
 * @brief 让数码管的某一位显示特定的组合
 *
 * @param dig 位选，取值范围[0-7]
 * @param dat 段选信�?
 */
static void Int_DigitalTube_DisplaySingle(u8 dig, u8 dat)
{
    // 关掉当前数码�?
    P0 = 0;
    // 完成位�?
    // 置零
    P1 &= 0xC7;
    // 左移
    dig <<= 3;
    P1 |= dig;

    // 段�?
    P0 = dat;
}

void Int_DigitalTube_Refresh()
{
    u8 i;
    // 依次刷新8位数码管
    for (i = 0; i < 8; i++) {
        Int_DigitalTube_DisplaySingle(i, s_digital_buffer[i]);
        // 延时增加占空�?
        Delay1ms(1);
    }
}

void Int_DigitalTube_Init()
{
    // 关闭LED
    LED_EN = 0;

    // 打开数码�?
    SMG_EN = 0;
}

void Int_DigitalTube_DisplayNum(u32 num)
{
    u8 i;
    // 将显存清�?
    for (i = 0; i < 8; i++) {
        s_digital_buffer[i] = 0;
    }

    // 如果待展示的数字�?0，直接展�?
    if (!num) {
        s_digital_buffer[7] = s_digital_codes[0];
        return;
    }

    // 赋值显�?
    i = 7;
    while (num > 0) {
        // 对显存赋�?
        s_digital_buffer[i] = s_digital_codes[num % 10];
        i--;
        num /= 10;
    }
    
}