#include "Dri_Timer0.h"
#include "Com_Util.h"
#include <STC89C5xRC.H>
#include <STDIO.H>
#define LED1 P00
#define MAX_CALLBACK_COUNT 4
static Timer0_Callback s_callbacks[MAX_CALLBACK_COUNT];

void Dri_Timer0_Init()
{
    u8 i;
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
    //5.初始化函数指针数组
    for ( i = 0; i < MAX_CALLBACK_COUNT; i++)
    {
        s_callbacks[i] = NULL;
    }
}

bit Dri_Timer0_RegisterCallback(Timer0_Callback callback)
{
    u8 i;
    //重复注册
    for ( i = 0; i < MAX_CALLBACK_COUNT; i++)
    {
       if (s_callbacks[i] == callback)
        {
            return 1;
        }
    }
    //找到空位注册
    for ( i = 0; i < MAX_CALLBACK_COUNT; i++)
    {
        if (s_callbacks[i] == NULL)
        {
            s_callbacks[i] = callback;
            return 1;
        }
    }
    return 0;
}

bit Dri_Timer0_DeRegisterCallback(Timer0_Callback callback)
{
    u8 i;
    for ( i = 0; i < MAX_CALLBACK_COUNT; i++)
    {
        if (s_callbacks[i] == callback)
        {
            s_callbacks[i] = NULL;
            return 1;
        }
    }
    return 0;
}

void Timer0_Handler() interrupt 1
{
    u8 i;
    //1.重新装载定时初值
    TL0=64614; //设置定时器0初值 1ms@11.0592MHz
    TH0=64614 >> 8;
    //2.轮询函数指针数组
    for ( i = 0; i < MAX_CALLBACK_COUNT; i++)
    {
        if (s_callbacks[i] != NULL)
        {
            s_callbacks[i]();
        }
    }
    

} 