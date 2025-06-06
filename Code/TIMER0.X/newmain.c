/*
 * File:   newmain.c
 * Author: aakas
 *
 * Created on 24 December, 2024, 12:04 PM
 */

// PIC16LF877A Configuration Bit Settings

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
    TRISB=0;

    PORTB=0;

    OPTION_REG=0x07;
    TMR0=60; // for 20ms 158 for 10ms
    while(1)
    {
        RB0=RB0^1;
        TMR0=60; // for 20ms 158 for 10ms
        while(TMR0IF==0){}
        TMR0IF=0;
            
    }    
}
