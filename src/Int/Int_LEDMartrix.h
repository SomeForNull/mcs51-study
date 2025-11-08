#ifndef __INT_LEDMARTRIX_H__
#define __INT_LEDMARTRIX_H__
#include "Com_Util.h"
/**
 * @brief LED点阵初始化
 * 
 */
void Int_LEDMartrix_Int();

/**
 * @brief 设置LED点阵显示图案
 * 
 * @param Pic 图案数据数组
 */
void Int_LEDMartrix_SetPic(u8 Pic[]);

/**
 * @brief 刷新LED点阵显示
 * 
 */
void Int_LEDMartrix_Refrensh();

#endif /* __INT_LEDMARTRIX_H__ */