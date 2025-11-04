#include "Com_Util.h"

/**
 * @brief 延迟指定的毫秒数
 *
 * @param ms 延迟毫秒
 */
void Com_Util_Delay_Ms(u16 ms)
{
    u8 i, j;
    while (ms > 0) {
        ms--;
        _nop_();
        i = 2;
        j = 199;
        do {
            while (--j);

        } while (--i);
    }
}