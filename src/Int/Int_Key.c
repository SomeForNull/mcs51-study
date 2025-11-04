#include "Int_key.h"
#define SW1 P42
#define SW2 P43
#define SW3 P32
#define SW4 P33

bit Int_Key_IsSw1_Pressed()
{
    if (SW1 == 0) {
        Com_Util_Delay_Ms(10);
        if (SW1 == 0) {
            while (SW1 == 0);
            return 1;
        }
    }
    return 0;
}

bit Int_Key_IsSw2_Pressed()
{

    if (SW2 == 0) {
        Com_Util_Delay_Ms(10);
        if (SW2 == 0) {
            while (SW2 == 0);
            return 1;
        }
    }
    return 0;
}

bit Int_Key_IsSw3_Pressed()
{
    if (SW3 == 0) {
        Com_Util_Delay_Ms(10);
        if (SW3 == 0) {
            while (SW3 == 0);
            return 1;
        }
    }
    return 0;
}
bit Int_Key_IsSw4_Pressed()
{
    if (SW4 == 0) {
        Com_Util_Delay_Ms(10);
        if (SW4 == 0) {
            while (SW4 == 0);
            return 1;
        }
    }
    return 0;
}