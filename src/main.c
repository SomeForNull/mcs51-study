#include "Int_DigitalTube.h"
#include "Dri_Interrupt_Open.h"
#include "Dri_Timer0.h"
#define LED0 P00
/**
 * @brief 定时器任务-控制LED 0.5s闪烁
 * 
 */
void LED_Blink()
{
    static u16 count = 0;
    count++;
    if(count>=500){
        LED0 = ~LED0;
        count=0;
    }
}

int main()
{
    
    //初始化外部中断0
    Init_INT0();
    //初始化定时器0
    Dri_Timer0_Init();
    //注册定时器回调函数
    Dri_Timer0_RegisterCallback(LED_Blink);
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
