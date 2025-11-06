#include "Dri_Interrupt_Open.h"
#include <STC89C5xRC.H>
void Init_INT0()
{
        // 打开中断总开关
    EA = 1;

    // 打开外部中断0开关
    EX0 = 1;

    // 配置外部中断为下降沿触发
    IT0 = 1;

}