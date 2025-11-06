#include "Int_DigitalTube.h"
#include "Int_MatrixKey.h"
#define LED0   P00
int main()
{
    
    // 初始化数码管显示和按键扫描
    u8 key_pressed = 0;
    Init_INT0();
    Int_DigitalTube_Init();
    Int_DigitalTube_DisplayNum(key_pressed);
    while (1) {
        key_pressed = Int_MatrixKey_CheckKey();
        if (key_pressed) {
            Int_DigitalTube_DisplayNum(key_pressed);
            Int_Buzzer_Buzz();
        }
        Int_DigitalTube_Refresh();
    }
}


/**
 * @brief 中断函数中打开LED0，代表当触发中断时，LED0会打开。
 *        根据我们之前的设置，当按下SW3时，P32为低电平，此时LED0打开。
 *
 *        interrupt 0表示0号中断触发时执行该函数的逻辑
 *        如果用C语言编程，中断查询次序就是中断号
 */
void INT0_Func() interrupt 0
{
    //延时消抖
    Com_Util_Delay_Ms(10);
    // 中断中打开LED0
    LED0 = ~LED0;
}
