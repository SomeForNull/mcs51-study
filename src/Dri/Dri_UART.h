#ifndef __DRI_UART_H__
#define __DRI_UART_H__

/**
 * @brief 串口初始化
 * 
 */
void Dri_UART_Init();

/**
 * @brief 通过串口发送一个字符串
 *
 * @param ch 要发送的字符串
 */
void Dri_UART_SendStr(char *str);

/**
 * @brief 通过串口接收一个字符
 *
 * @param p_ch 要接收的字符指针
 *
 * @return 0为读取失败，1为读取成功
 */
bit Dri_UART_RecvChar(char *p_ch);


#endif /* __DRI_UART_H__ */