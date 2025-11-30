#include "Int_DS1302.h"
#include <STC89C5xRC.H>
#include "Com_Util.h"
#define CE          P41
#define IO          P40
#define SCLK        P37

#define SECOND      0x80
#define MINUTE      0x82
#define HOUR        0x84
#define DAY         0x86
#define MONTH       0x88
#define DAY_OF_WEEK 0x8A
#define YEAR        0x8C
#define WP          0x8E

void Int_DS1302_Init()
{
    SCLK = 0;
    CE   = 0;
    IO   = 0;
}

/**
 * @brief 向DS1302写入一个字节
 *
 * @param cmd_byte
 * @param data_byte
 */
void Int_DS1302_WriteByte(u8 cmd_byte, u8 data_byte)
{
    u8 i;
    CE = 1;
    for (i = 0; i < 8; i++) {
        IO = cmd_byte & 0x01;
        cmd_byte >>= 1;
        SCLK = 1;
        SCLK = 0;
    }
    for (i = 0; i < 8; i++) {
        IO = data_byte & 0x01;
        data_byte >>= 1;
        SCLK = 1;
        SCLK = 0;
    }
    CE = 0;
}

/**
 * @brief 从DS1302读取一个字节
 *
 * @param cmd_byte
 * @return u8
 */
u8 Int_DS1302_ReadByte(u8 cmd_byte)
{
    u8 i;
    u8 byte = 0x00;
    CE      = 1;
    for (i = 0; i < 8; i++) {
        IO = cmd_byte & 0x01;
        cmd_byte >>= 1;
        SCLK = 1;
        SCLK = 0;
    }

    if (IO == 1) {
        byte |= 0x80;
    }

    for (i = 0; i < 7; i++) {
        SCLK = 1;
        SCLK = 0;
        byte >>= 1;
        if (IO == 1) {
            byte |= 0x80;
        }
    }
    CE = 0;
    return byte;
}

void Int_DS1302_SetDate(Struct_Date *p_stdate)
{
    u8 byte;
    // 关闭写保护
    Int_DS1302_WriteByte(WP, 0x00);

    // 设置秒
    byte = ((p_stdate->second / 10) << 4) | p_stdate->second % 10;
    Int_DS1302_WriteByte(SECOND, byte);
    // 设置分
    byte = ((p_stdate->minute / 10) << 4) | p_stdate->minute % 10;
    Int_DS1302_WriteByte(MINUTE, byte);
    // 设置时
    byte = ((p_stdate->hour / 10) << 4) | p_stdate->hour % 10;
    Int_DS1302_WriteByte(HOUR, byte);
    // 设置日
    byte = ((p_stdate->day / 10) << 4) | p_stdate->day % 10;
    Int_DS1302_WriteByte(DAY, byte);
    // 设置月
    byte = ((p_stdate->month / 10) << 4) | p_stdate->month % 10;
    Int_DS1302_WriteByte(MONTH, byte);
    // 设置年
    byte = ((p_stdate->year / 10) << 4) | p_stdate->year % 10;
    Int_DS1302_WriteByte(YEAR, byte);
    // 设置星期
    byte = p_stdate->day_of_week;
    Int_DS1302_WriteByte(DAY_OF_WEEK, byte);
    // 开启写保护
    Int_DS1302_WriteByte(WP, 0x80);
}

void Int_DS1302_GetDate(Struct_Date *p_st_date)
{
    u8 byte;
    // 读取秒
    byte              = Int_DS1302_ReadByte(SECOND + 1);
    p_st_date->second = (byte >> 4) * 10 + (byte & 0x0F);
    // 读取分
    byte              = Int_DS1302_ReadByte(MINUTE + 1);
    p_st_date->minute = (byte >> 4) * 10 + (byte & 0x0F);
    // 读取时
    byte            = Int_DS1302_ReadByte(HOUR + 1);
    p_st_date->hour = (byte >> 4) * 10 + (byte & 0x0F);
    // 读取日
    byte           = Int_DS1302_ReadByte(DAY + 1);
    p_st_date->day = (byte >> 4) * 10 + (byte & 0x0F);
    // 读取月
    byte             = Int_DS1302_ReadByte(MONTH + 1);
    p_st_date->month = (byte >> 4) * 10 + (byte & 0x0F);
    // 读取年
    byte            = Int_DS1302_ReadByte(YEAR + 1);
    p_st_date->year = (byte >> 4) * 10 + (byte & 0x0F);
    // 读取星期
    byte                   = Int_DS1302_ReadByte(DAY_OF_WEEK + 1);
    p_st_date->day_of_week = byte;
}