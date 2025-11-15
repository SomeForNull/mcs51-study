#ifndef __INT_EEPROM_H__
#define __INT_EEPROM_H__
#include <STC89C5xRC.H>
#define DEV_ADDR  0xA0
#define PAGE_SIZE 16
#include "Dri_IIC.h"
#include "Com_Util.h"

/**
 * @brief 向EEPROM指定位置写入多个字节
 *
 * @param addr 起始地址
 * @param bytes 要写入的字节
 * @param len 要写入的字节个数
 * @return bit 0:写入成功 1:写入失败
 */
bit Int_EEPROM_WriteBytes(u8 addr, u8 *bytes, u8 len);

/**
 * @brief  从EEPROM指定位置读取多个字节
 *
 * @param addr 起始地址
 * @param bytes 存储读取的字节用的数组指针
 * @param len 要读取的字节个数
 * @return bit 0:读取成功 1:读取失败
 */
bit Int_EEPROM_ReadBytes(u8 addr, u8 *bytes, u8 len);

#endif /* __INT_EEPROM_H__ */
