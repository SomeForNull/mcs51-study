#include "Dri_Timer0.h"
#include "Com_Util.h"
#include <STC89C5xRC.H>
#define LED1 P00

void Dri_Timer0_Init()
{
    //1.启用中断
    EA = 1;
    ET0 = 1; //打开定时器0中断开关


    //2.配置定时器模式 C/T:0 M1=0 M0=1 方式1 16位定时器
    TMOD &= 0xF0; //清除定时器0的控制位
    TMOD |= 0x01; //设置定时器0为方式1

    //3.设置定时初值
    TL0=64614; //设置定时器0初值 1ms@11.0592MHz
    TH0=64614 >> 8;

    //4.启动定时器0
    TR0 = 1;
}

void Timer0_Handler() interrupt 1
{
    static u16 count=0;
    //重新装载定时初值
    TL0=64614; //设置定时器0初值 1ms@11.0592MHz
    TH0=64614 >> 8;

    //控制LED反转
    count++;
    if(count>=500){
        count=0;
        LED1 = ~LED1; 
    }

} 