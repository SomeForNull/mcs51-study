#include "Int_DigitalTube.h"
#include "Int_MatrixKey.h"
#include "Dri_Interrupt_Open.h"
#include "Dri_Timer0.h"
#define LED0   P00
int main()
{
    
    // 初始化数码管显示和按键扫描
    u8 key_pressed = 0;
    Init_INT0();
    Dri_Timer0_Init();
    while (1);

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
    //如果延迟后还在低位则是正常 就算后延抖动下降延触发的时候 延迟10ms后 会在高电位
    if(P32==0){
        // 中断控制定时器
       ET0=!ET0;
    }

}
