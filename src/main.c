#include "Int_LEDMartrix.h"

void main()
{
    u8 pic[8] = {0x1,
                 0x2,
                 0x4,
                 0x8,
                 0x10,
                 0x20,
                 0x40,
                 0x80};

    Int_LEDMartrix_Int();
    Int_LEDMartrix_SetPic(pic);
    while (1) {
        //调用函数也会有汇编指令
        Int_LEDMartrix_Refrensh();
    }
}