/*
 * File:   newmain.c
 * Author: aakas
 *
 * Created on 24 December, 2024, 10:30 PM
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
    TRISB=0;
    PORTB=0;
    OPTION_REG=0x07;
    TMR0=60;
    TMR0IE=1;
    GIE=1;
    int a=0;
    while(1)
    {
        a=10;
         

    }
    
}
void __interrupt()ISR()
{
    static int count=0;
    if(TMR0IF==1)
    {
        count++;
       
        if(count<50)
        {
            PORTB=0x02;
        }
        else if(count==50)
        {
            PORTB=0x06;
            
        }
        else if(count==100)
        {
            PORTB=0x04;
        }
        else if(count==150)
        {
            PORTB=0x0c;
        }
        else if(count==200)
        {
            PORTB=0x08;
        }
        else if(count==250)
        {
            PORTB=0x09;
  
        }
        else if(count==300)
        {
            PORTB=0x01;
        }
        else if(count==350)
        {
            PORTB=0x03;
            count=0;
        }
        TMR0=60;
        TMR0IF=0;
    }
}