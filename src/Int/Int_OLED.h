#ifndef __INT_OLED_H__
#define __INT_OLED_H__

#include "Com_Util.h"
/**
 * @brief 发送多字节数据到OLED
 *
 * @param bytes
 * @param length
 */
void Int_OLED_WriteData(u8 bytes[], u8 length);

/**
 * @brief 发送多字节命令到OLED
 *
 * @param bytes
 * @param length
 */
void Int_OLED_WriteCmd(u8 bytes[], u8 length);

/**
 * @brief 初始化OLED显示屏
 *
 */
void Int_OLED_Init();
/**
 * @brief 在指定位置（x,y）显示字符串
 *
 * @param x 横坐标
 * @param y 纵坐标
 * @param str 待展示字符串
 */
void Int_OLED_ShowStr(u8 x, u8 y, u8 *str);

/**
 * @brief 在指定位置(x,y)显示数字
 *
 * @param x 横坐标
 * @param y 纵坐标
 * @param num 待展示数字
 */
void Int_OLED_ShowNum(u8 x, u8 y, long int num);

/**
 * @brief 清屏OLED显示屏
 *
 */
void Int_OLED_Clear();

#endif /* __INT_OLED_H__ */