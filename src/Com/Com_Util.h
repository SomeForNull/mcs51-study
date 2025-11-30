#ifndef _COM_UTIL_H
#define _COM_UTIL_H
#include <INTRINS.H>
typedef unsigned char u8;
typedef unsigned int u16;
typedef unsigned long u32;

void Com_Util_Delay_Ms(u16 ms);

void Com_Util_Delay480us(void);	//@11.0592MHz

void Com_Util_Delay60us(void);	//@11.0592MHz

void Com_Util_Delay420us(void);	//@11.0592MHz

void Com_Util_Delay10us(void);	//@11.0592MHz

void Com_Util_Delay50us(void);	//@11.0592MHz
#endif // !_COM_UTIL_H
