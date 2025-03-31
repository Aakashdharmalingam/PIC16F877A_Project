/*
 * File:   newmain.c
 * Author: aakas
 *
 * Created on 5 January, 2025, 10:36 AM
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
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define _XTAL_FREQ 10000000
void display(int RS, int DC);
void display_string(char *s);

void main() 
{
    char a[]={"LOCK"};
    char b[]={"UNLOCK"};
    char c[10];
    char e[]={"1234"};
    
    TRISB=0;
    TRISC=0;
    PORTB=0;
    PORTC=0;
    
//    TXIE=1;
//    RCIE=1;
    
    TXSTA=0x24;
    RCSTA=0x90;
    SPBRG=64;
    display(0, 0x0e);
    display_string(a);
    for(int i=0;i<4;i++)
    {
        while(RCIF==0);
        c[i]=RCREG;
        RCIF=0;
        display(1, c[i]);
    }

}
void display(int RS, int DC)
{
    RC0=RS;
    PORTB=DC;
    RC1=1;
    __delay_ms(10);
    RC1=0;
    __delay_ms(10);
}
void display_string(char *s)
{
    for(int i=0; s[i]!='\0'; i++)
        display(1, s[i]);
}