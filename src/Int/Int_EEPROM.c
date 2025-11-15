#include "Int_EEPROM.h"

bit Int_EEPROM_WritePage(u8 addr, u8 *bytes, u8 len)
{
    u8 i;
    bit ack = 0;
    // 发送起始信号
    Dri_IIC_Start();

    // 发送设备地址
    Dri_IIC_SendByte(DEV_ADDR);
    ack |= Dri_IIC_ReceiveAck();

    // 发送字地址
    Dri_IIC_SendByte(addr);
    ack |= Dri_IIC_ReceiveAck();

    // 发送数据
    for (i = 0; i < len; i++) {
        Dri_IIC_SendByte(bytes[i]);
        ack |= Dri_IIC_ReceiveAck();
    }

    // 发送结束信号
    Dri_IIC_Stop();
    // 等待EEPROM内部写入完成
    Com_Util_Delay_Ms(5);
    return ack;
}

bit Int_EEPROM_WriteBytes(u8 addr, u8 *bytes, u8 len)
{
    // 当前页剩余空间
    u8 page_remain;
    bit ack = 0;
    while (len > 0) {
        page_remain = PAGE_SIZE - (addr % PAGE_SIZE);
        if (len > page_remain) {
            // 当前页空间不足，先写满当前页
            ack |= Int_EEPROM_WritePage(addr, bytes, page_remain);
            // 剩余内容写到下一页
            len -= page_remain;
            bytes += page_remain;
            addr += page_remain;

        } else {
            // 当前页空间足够，直接写入剩余内容
            ack |= Int_EEPROM_WritePage(addr, bytes, len);
            len = 0;
        }
    }
    return ack;
}

bit Int_EEPROM_ReadBytes(u8 addr, u8 *bytes, u8 len)
{
    bit ack = 0;
    u8 i;
    // 发送起始信号
    Dri_IIC_Start();
    // 发送设备地址
    Dri_IIC_SendByte(DEV_ADDR);
    ack |= Dri_IIC_ReceiveAck();
    // 发送字地址
    Dri_IIC_SendByte(addr);
    ack |= Dri_IIC_ReceiveAck();
    // 再次发送起始信号
    Dri_IIC_Start();
    // 发送设备地址
    Dri_IIC_SendByte(DEV_ADDR + 1);
    ack |= Dri_IIC_ReceiveAck();
    // 读取数据
    for (i = 0; i < len; i++) {
        bytes[i] = Dri_IIC_ReceiveByte();
        Dri_IIC_SendAck(i == len - 1 ? 1 : 0);
    }
    // 发送结束信号
    Dri_IIC_Stop();

    return ack;
}
