/*
 * File:   newmain.c
 * Author: aakas
 *
 * Created on 23 December, 2024, 8:10 PM
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
void display(int RS, int DC);

void main() 
{
    TRISD=TRISC=0;
    PORTC=PORTD=0;
    OPTION_REG=0;
    TRISB=0x0F;
    display(0, 0x0e);
    
    while(1)
    {    
        RB4=0;
        RB5=1;
        RB6=1;
        RB7=1;
        if(RB0==0)
        {
            while(RB0==0){}
                display(1, '1');

        }
        RB4=0;
        RB5=1;
        RB6=1;
        RB7=1;
        if(RB1==0)
        {
            while(RB1==0){}
                display(1, '2');

        }
        RB4=0;
        RB5=1;
        RB6=1;
        RB7=1;
        if(RB2==0)
        {
            while(RB2==0){}
                display(1, '3');

        }
        RB4=1;
        RB5=0;
        RB6=1;
        RB7=1;
        if(RB0==0)
        {
            while(RB0==0){}
                display(1, '4');

        }
        RB4=1;
        RB5=0;
        RB6=1;
        RB7=1;
        if(RB1==0)
        {
            while(RB1==0){}
                display(1, '5');

        }
        RB4=1;
        RB5=0;
        RB6=1;
        RB7=1;
        if(RB2==0)
        {
            while(RB2==0){}
                display(1, '6');

        }
        RB4=1;
        RB5=1;
        RB6=0;
        RB7=1;
        if(RB0==0)
        {
            while(RB0==0){}
                display(1, '7');

        }
        RB4=1;
        RB5=1;
        RB6=0;
        RB7=1;
        if(RB1==0)
        {
            while(RB1==0){}
                display(1, '8');

        }
        RB4=1;
        RB5=1;
        RB6=0;
        RB7=1;
        if(RB2==0)
        {
            while(RB2==0){}
                display(1, '9');

        }
        RB4=1;
        RB5=1;
        RB6=1;
        RB7=0;
        if(RB0==0)
        {
            while(RB0==0){}
                display(1, '*');

        }
        RB4=1;
        RB5=1;
        RB6=1;
        RB7=0;
        if(RB1==0)
        {
            while(RB1==0){}
                display(1, '0');

        }
        RB4=1;
        RB5=1;
        RB6=1;
        RB7=0;
        if(RB2==0)
        {
            while(RB2==0){}
                display(1, '#');

        }
    }
}

void display(int RS, int DC)
{
    RD0=RS;
    PORTC=DC;
    RD1=1;
    __delay_ms(10);
    RD1=0;
    __delay_ms(10);
}
