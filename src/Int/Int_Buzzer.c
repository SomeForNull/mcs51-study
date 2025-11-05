#include "Int_Buzzer.h"
#include "Com_Util.h"

void Int_Buzzer_Buzz()
{
    unsigned char counter = 100;

    while (counter) {
        BUZZ = ~BUZZ;
        Com_Util_Delay_Ms(1);
        --counter;
    }
}
