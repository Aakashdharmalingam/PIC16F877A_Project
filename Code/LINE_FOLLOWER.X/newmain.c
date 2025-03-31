/*
 * File:   newmain.c
 * Author: aakas
 *
 * Created on 20 December, 2024, 8:11 PM
 */

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
void back();
void forward();
void right();
void left();

void main() 
{   
    OPTION_REG=0;
    TRISB=0x0f;
    TRISD=0;
    PORTD=0;
    
    
   while(1)
   {   
    if(RB0==1 && RB1==1)
    {
        while(RB0==1 && RB1==1)
        {
            forward();
        }
        
    }
    else if(RB0==0 && RB1==1)
      while(RB0==0 && RB1==1)
        {
            left();
        }
    else if(RB0==1 && RB1==0)
      while(RB0==1 && RB1==0)
        {
            right();
        }
    else if(RB0==0 && RB1==0)
      while(RB0==0 && RB1==0)
        {
            back();
        }
   }
}
void back()
{
    RD1=0;
    RD2=1;
    RD3=0;
    RD4=1;
}
void forward()
{
    RD1=1;
    RD2=0;
    RD3=1;
    RD4=0;
}
void left()
{
    RD1=0;
    RD2=0;
    RD3=1;
    RD4=0;
}
void right()
{
    RD1=1;
    RD2=0;
    RD3=0;
    RD4=0;
}