#ifndef __DRI_1WIRE_H__
#define __DRI_1WIRE_H__

#include "Com_Util.h"
/**
 * @brief 初始化1-Wire总线
 * 
 * @return bit 1表示初始化成功 0表示初始化失败
 */
bit Dri_1wire_Init();

/**
 * @brief 写一个字节
 * 
 * @param byte 
 */
void Dri_1wire_writeByte(u8 byte);


/**
 * @brief 读一个字节
 * 
 * @return u8 
 */
u8 Dri_1wire_readByte();

#endif /* __DRI_1WIRE_H__ */