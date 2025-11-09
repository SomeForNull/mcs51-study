#include "Dri_UART.h"
#include <STC89C5xRC.H>
char buffer;

// 发送状态,1:正在发送,0:未在发送
static bit is_sending;

void Dri_UART_Init()
{
    //1.设置串口的工作模式
    SM0 = 0; 
    SM1 = 1;

    //2.设置波特率
    //2.1 SMOD
    PCON &= 0x7F; //SMOD = 0;
    //2.2 定时器1
    //2.2.1 设置定时器工作模式
    TMOD &= 0x0F; //设置定时器1为模式2
    TMOD |= 0x20;
    //2.2.2 设置定时初值
    TL1=0xFD;//253
    TH1=0xFD;
    //2.2.3 启动定时器1
    TR1=1;

    //3.允许串口接收
    REN=1;
    SM2=0;

    //4.串口中断相关配置
    EA=1;   //总中断使能
    ES=1;   //串口中断使能

    //5.清除串口中断标志
    TI=0;
    RI=0;
}

void Dri_UART_SendChar(char ch)
{
    // 如果有数据在发送，等待发送完成
    while (is_sending);
    is_sending = 1;
    SBUF       = ch;
}

void Dri_UART_SendStr(char *str)
{
    while (*str) {
        Dri_UART_SendChar(*str);
        str++;
    }
}

bit Dri_UART_RecvChar(char *p_ch)
{
    // 如果缓冲区有数据,则将值符传给p_ch,并清空缓冲区
    if (buffer) {
        *p_ch  = buffer;
        buffer = 0;
        return 1;
    } else {
        return 0;
    }
}
/**
 * @brief 串口中断函数，进入这个函数有两个触发条件：发送完成和接收完成
 *
 */
void Dri_UART_Func() interrupt 4
{
    // 收到命令,将数据放入缓冲区
    if (RI == 1) {
        buffer = SBUF;
        RI     = 0;
    }

    // 发送完成,将发送状态置为0
    if (TI == 1) {
        is_sending = 0;
        TI         = 0;
    }
}
