#ifndef __DRI_IIC_H__
#define __DRI_IIC_H__

#include "Com_Util.h"
#define SCL P17
#define SDA P16
/**
 * @brief 开始信号
 * 
 */
void Dri_IIC_Start();

/**
 * @brief 发送一个字节
 * 
 * @param byte 
 */
void Dri_IIC_SendByte(u8 byte);

/**
 * @brief 接收确认信号
 * 
 * @return bit 
 */
bit Dri_IIC_ReceiveAck();

/**
 * @brief 接受一个字节
 * 
 * @return u8 
 */
u8 Dri_IIC_ReceiveByte();

/**
 * @brief 发送确认信号
 * 
 * @param ack 
 */
void Dri_IIC_SendAck(bit ack);

/**
 * @brief 发送停止信号
 * 
 */
void Dri_IIC_Stop();
#endif /* __DRI_IIC_H__ */