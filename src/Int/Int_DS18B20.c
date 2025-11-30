#include "Int_DS18B20.h"
#include "Dri_1wire.h"
#include "Com_Util.h"
char Int_DS18B20_GetTemperature()
{
    u8 ls_byte, ms_byte;
    //初始化
    Dri_1wire_Init();
    //发送跳过ROM命令
    Dri_1wire_writeByte(0xCC);
    //发送转换温度命令
    Dri_1wire_writeByte(0x44);

    //初始化
    Dri_1wire_Init();
    //发送跳过ROM命令
    Dri_1wire_writeByte(0xCC);
    //发送读取温度命令
    Dri_1wire_writeByte(0xBE);
    //读取温度字节
    ls_byte=Dri_1wire_readByte();
    ms_byte=Dri_1wire_readByte();
   return (ls_byte>>4)|(ms_byte<<4);
}