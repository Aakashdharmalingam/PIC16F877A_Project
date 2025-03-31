/*
 * File:   newmain.c
 * Author: aakas
 *
 * Created on 25 December, 2024, 10:10 AM
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
#include<stdio.h>
#include<stdlib.h>
void display(int RS, int DC);
void display_string(char *s);

void main() 
{
    TRISD=0;
    TRISC=0;
    PORTD=0;
    PORTC=0;
    OPTION_REG=0x07;
    TRISB=0x07;
    PORTB=0x07;
    display(0, 0x0e);
    char a[15]={"45"},b[15]={"90*"}, c[15]={"135*"}, d[15]={"180*"}, e[15]={"225*"};
    char f[15]={"270*"}, g[15]={"315*"}, h[15]={"360*"}, i[15]={"0*"}; 
//    char name[]={"hello"};
    
    while(1)
    {
        RB3=0,RB4=1,RB5=1;
            
            if(RB0==0)
            {
                while(RB0==0){}
                display(0, 0x01);
                display(0, 0x80);
                display_string(a);
                display(1, 0xDF);
                RC2=1,RC3=0,RC4=0,RC5=0,RC6=0;
            }
            else if(RB1==0)
            {
                while(RB1==0){}
                display(0, 0x01);
                display_string(b);
                RC2=1,RC3=1,RC4=0,RC5=0,RC6=0;
            }
            else if(RB2==0)
            {
                while(RB2==0){}
                display(0, 0x01);    
                display_string(c);
                RC3=1,RC2=0,RC4=0,RC5=0,RC6=0;
            }
        
        
        RB3=1,RB4=0,RB5=1;
            
            if(RB0==0)
            {
                while(RB0==0){}
                display(0, 0x01);
                display_string(d);
                RC3=1,RC4=1,RC6=0,RC2=0,RC5=0;
            }
            else if(RB1==0)
            {
                while(RB1==0){}
                display(0, 0x01);
                display_string(e);
                RC4=1,RC3=0,RC2=0,RC5=0,RC6=0;
            }
            else if(RB2==0)
            {
                while(RB2==0){}
                display(0, 0x01);
                display_string(f);
                RC4=1,RC5=1,RC2=0,RC3=0,RC6=0;
            }
        
        
        RB3=1,RB4=1,RB5=0;
            
            if(RB0==0)
            {
                while(RB0==0){}
                display(0, 0x01);
                display_string(g);
                RC5=1,RC4=0,RC2=0,RC3=0,RC6=0;
            }
            else if(RB1==0)
            {
                while(RB1==0){}
                display(0, 0x01);
                display_string(h);
                RC5=1,RC6=0,RC2=1,RC3=0,RC4=0;
            }
            else if(RB2==0)
            {
                while(RB2==0){}
                display(0, 0x01);
                display_string(i);
                RC2=0,RC3=0,RC4=0,RC5=0,RC6=0;
            }
        

    }
    
}
void display_string(char *s)
{
    for(int i=0;s[i]!='\0';i++)
    {
        display(1, s[i]);
    }
}
void display(int RS, int DC)
{
    RC0=RS;
    PORTD=DC;
    RC1=1;
    __delay_ms(10);
    RC1=0;
    __delay_ms(10);
}