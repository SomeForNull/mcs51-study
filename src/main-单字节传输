#include <STC89C5xRC.H>
#include "Dri_UART.h"

void main()
{
    char command;
    Dri_UART_Init();
    while (1) {
        if (Dri_UART_RecvChar(&command)) {
            if (command == 'A') {
                // 点亮LED
                P0 = 0x00;
                Dri_UART_SendStr("Ok:LED is on");
            } else if (command == 'B') {
                // 熄灭LED
                P0 = 0xFF;
                Dri_UART_SendStr("Ok:LED is off");
            } else {
                // 报错
                Dri_UART_SendStr("Error:Unknown command");
            }
        }
    }
}
