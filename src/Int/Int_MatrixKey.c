#include "Int_MatrixKey.h"
#include <STC89C5xRC.H>
/**
 * @brief 检测0-3行的按键状态
 *
 * @param row 0-3行
 * @return u8 返回按键编号 0表示该行没有按键被按下
 */
static u8 Int_MatrixKey_check_row(u8 row)
{
    /* 将指定行拉低（其他位拉高）。P20..P23 对应 P2 的 bit0..bit3 */
    P2   = (u8) ~(1u << row);
    u8 p = P2;

    /* 列对应 P24..P27 -> bit4..bit7 */
    const u8 col_bit_offset = 4;
    for (u8 ci = 0; ci < 4; ++ci) {
        u8 bit = (u8)(1u << (col_bit_offset + ci));
        if ((p & bit) == 0)
        { /* 该列被拉低，按下 */
            Com_Util_Delay_Ms(10);
            if ((P2 & bit) == 0) {
                /* 等待释放 */
                while ((P2 & bit) == 0);
                return (u8)(5 + row * 4 + ci); /* 键号映射 5..20 */
            }
        }
    }

    return 0;
}

u8 Int_MatrixKey_CheckKey()
{
    for (u8 r = 0; r < 4; ++r) {
        u8 k = Int_MatrixKey_check_row(r);
        if (k != 0) return k;
    }
    return 0;
}
