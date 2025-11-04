#ifndef __INT_KEY_H__
#define __INT_KEY_H__
#include <STC89C5xRC.H>
#include "Com_Util.h"
/**
 * @brief 检测按键 SW1 是否被按下
 *
 * @return bit 按下返回 1，否则返回 0
 */
bit Int_Key_IsSw1_Pressed();

/**
 * @brief 检测按键 SW2 是否被按下
 *
 * @return bit 按下返回 1，否则返回 0
 */
bit Int_Key_IsSw2_Pressed();

/**
 * @brief 检测按键 SW3 是否被按下
 *
 * @return bit 按下返回 1，否则返回 0
 */
bit Int_Key_IsSw3_Pressed();

/**
 * @brief 检测按键 SW4 是否被按下
 *
 * @return bit 按下返回 1，否则返回 0
 */
bit Int_Key_IsSw4_Pressed();

#endif /* __INT_KEY_H__ */