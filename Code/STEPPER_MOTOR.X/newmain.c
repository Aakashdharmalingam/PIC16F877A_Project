/*
 * File:   newmain.c
 * Author: aakas
 *
 * Created on 23 December, 2024, 12:59 PM
 */
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF 


#include <xc.h>
#define _XTAL_FREQ 10000000
void main() 
{
    TRISC=0;
    PORTC=0;
    while(1)
    {
        // ONE PHASE 90 increases
        
        PORTC=1; //RC0=1
        __delay_ms(1000);
        PORTC=2; //RC1=1
        __delay_ms(1000);
        PORTC=4;  //RC2=1
        __delay_ms(1000);
        PORTC=8; //RC3=1
        __delay_ms(1000);
        
        // Double Phase 45 increase
        
        PORTC=1;
        __delay_ms(1000);
        PORTC=0x03;
        __delay_ms(1000);
        PORTC=0x02;
        __delay_ms(1000);
        PORTC=0x06;
        __delay_ms(1000);
        PORTC=0x04;
        __delay_ms(1000);
        PORTC=0x0c;
        __delay_ms(1000);
        PORTC=0x08;
        __delay_ms(1000);
        PORTC=0x09;
        __delay_ms(1000);
    }
}
