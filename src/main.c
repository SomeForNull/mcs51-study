#include "Dri_Timer0.h"
#include "Int_LEDMartrix.h"
#include "Int_EEPROM.h"
//孔
u8 picture[15] = {0x10, 0x11, 0x91, 0x91, 0xFD, 0x0B,
                  0x0B, 0x00, 0x7F, 0x80, 0x80, 0x80,
                  0x80, 0xE0, 0x00};
u8 buffer[15];
void main()
{
    u8 i;
    Dri_Timer0_Init();
    Int_LEDMartrix_Int();
    Int_EEPROM_WriteBytes(0, picture, 15);
    Int_EEPROM_ReadBytes(0, buffer, 15);

    for (i = 0; i < 15; i++) {
        Int_LEDMartrix_Shift(buffer[i]);
        Com_Util_Delay_Ms(200);
    }
}
