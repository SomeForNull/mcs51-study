#ifndef __INT_DS1302_H__
#define __INT_DS1302_H__
#include "Com_Util.h"
typedef struct
{
    u8 second;
    u8 minute;
    u8 hour;
    u8 day;
    u8 month;
    u8 day_of_week;
    u8 year;
} Struct_Date;

/**
 * @brief 初始化DS1302
 * 
 */
void Int_DS1302_Init();

/**
 * @brief 设置初始日期
 * 
 * @param p_stdate 
 */
void Int_DS1302_SetDate(Struct_Date * p_stdate);

/**
 * @brief 获取当前日期
 * 
 * @param p_stdate 
 */
void Int_DS1302_GetDate(Struct_Date * p_stdate);

#endif /* __INT_DS1302_H__ */