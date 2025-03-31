/*
 * File:   newmain.c
 * Author: aakas
 *
 * Created on 19 December, 2024, 1:03 PM
 */


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
#include <stdio.h>;
void display(int RS, int DC);


void main() 
{
    TRISC=TRISD=0;
    PORTC=PORTD=0;
    ADCON0=0x01;
    ADCON1=0x80;
    int low_bit,high_bit,bits;
    char arr[10];
    display(0, 0x0e);
while(1)
    {   
        GO_nDONE = 1;//start the ADC conversion 
        while(GO_nDONE==1){}//wait for state change
        low_bit = ADRESL;//1024
        high_bit = ADRESH;
        
        bits = low_bit | high_bit<<8;
        sprintf(arr,"%04d",bits);//int to char in string
        display(0, 0x80);
        
        for(int i=0;arr[i]!='\0';i++)
        {
            display(1, arr[i]);
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
