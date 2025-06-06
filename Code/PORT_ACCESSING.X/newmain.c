// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#define _XTAL_FREQ 10000000


void main() 
{
    TRISB=0; // 0 is output
    TRISC=0;
    PORTB=0;
    while(1)
    {
        PORTB=0xFF; // 0x is hexadecimal f = 15
        PORTC=0x03;
        __delay_ms(1000);
        
        PORTB= 0xFF;
        PORTC= 0x01;
        __delay_ms(1000);
        
        PORTB= 0xFF;
        PORTC= 0;
        __delay_ms(1000);
        
        PORTB= 0x7Fl;
        __delay_ms(1000);
        
        PORTB= 0x3F;
        __delay_ms(1000);
        
        PORTB= 0x1F;
        __delay_ms(1000);
        
        PORTB= 0x0F;
        __delay_ms(1000);
        
        PORTB= 0x07;
        __delay_ms(1000);
        
        PORTB= 0x03;
        __delay_ms(1000);
        
        PORTB= 0x01;
        __delay_ms(1000);
        
        PORTB= 0x00;
        __delay_ms(1000);
    }
}
