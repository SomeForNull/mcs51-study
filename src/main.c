#include "Int_DS1302.h"
#include "Int_OLED.h"
#include "Int_DS18B20.h"
#include <STDIO.H>
code char *WEEK_NAME[] = {
    "Mon",
    "Tue",
    "Wed",
    "Thu",
    "Fri",
    "Sat",
    "Sun"};
void main()
{
    u8 str[17];
    u8 temperature;
    Struct_Date st_date;
    st_date.year        = 25;
    st_date.month       = 11;
    st_date.day         = 30;
    st_date.day_of_week = 7;
    st_date.hour        = 18;
    st_date.minute      = 0;
    st_date.second      = 0;
    // 初始化时钟并设置时间
    Int_DS1302_Init();
    Int_OLED_Init();
    Int_DS1302_SetDate(&st_date);

    Int_OLED_Clear();
    while (1) {
        Int_DS1302_GetDate(&st_date);
        temperature = Int_DS18B20_GetTemperature();

        sprintf(str, "20%02d/%02d/%02d %s",
                (int)st_date.year,
                (int)st_date.month,
                (int)st_date.day,
                WEEK_NAME[st_date.day_of_week - 1]);

        Int_OLED_ShowStr(0, 0, str);

        sprintf(str, "%02d:%02d:%02d Temp:%d",
                (int)st_date.hour,
                (int)st_date.minute,
                (int)st_date.second,
                (int)temperature);

        Int_OLED_ShowStr(0, 1, str);
        Com_Util_Delay_Ms(50);
    }
}
