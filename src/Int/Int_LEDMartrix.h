#ifndef __INT_LEDMARTRIX_H__
#define __INT_LEDMARTRIX_H__
#include "Com_Util.h"
/**
 * @brief LED点阵初始化
 * 
 */
void Int_LEDMartrix_Int();

/**
 * @brief 静态设置设置LED点阵显示图案
 * 
 * @param Pic 图案数据数组
 */
void Int_LEDMartrix_SetPic(u8 Pic[]);
/**
 * @brief 动态加入显示数组
 * 
 * @param pic 每一行字模
 */
void Int_LEDMartrix_Shift(u8 pic);

/**
 * @brief 手动刷新LED点阵显示
 * 
 */
void Int_LEDMartrix_Refrensh();


#endif /* __INT_LEDMARTRIX_H__ */