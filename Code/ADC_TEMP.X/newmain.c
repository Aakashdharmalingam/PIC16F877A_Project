/*
 * File:   led.c
 * Author: harish
 *
 * Created on 17 November, 2024, 9:55 PM
 */


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
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (All program memory code-protected)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include <stdio.h>


#define _XTAL_FREQ 10000000 //3.278 KHz to 20 MHz-> 10^6

void display_string(char a[]);
void display(int RS, int DC);

void main() {
    char arr[10];
    int low_bit;
    int high_bit;
    int bits;
    char cold[]={"COLD"};
    char very[]={"VERY_TEMP"};
    char high[]={"HIGH_TEMP"};
    char extrem[]={"EXTREM_HOT"};
    ADCON0 =0x01;//adc on
    ADCON1 =0x80;//right justified
    
    TRISD=TRISC=0;
    PORTD=PORTC=0;
    PORTB=0;
   
    display(0, 0x0e);//display on
    display(0, 0x38);
    
    while(1)
    {   
        GO_nDONE = 1;//start the ADC conversion 
        while(GO_nDONE==1){}//wait for state change
        low_bit = ADRESL;//1024
        high_bit = ADRESH;
        
        bits = low_bit | high_bit<<8;
        int actual = (bits-102)/2;

        sprintf(arr, "%04d", actual);//int to char in string
        display(0,0x80);
        for(int i=0;arr[i]!='\0';i++)
        {
            display(1, arr[i]);
        }
        
        if(actual <= 0)
        {
            display(0, 0xc0);
            display_string(cold);
        }
        else if(actual >= 0 && actual <=20)
        {
            display(0, 0xc0);
            display_string(cold);
        }
        else if(actual >= 21 && actual <=40)
        {
            display(0, 0xc0);
            display_string(high);
        }
        else if(actual >= 41 && actual <= 60)
        {
            display(0,0xc0);
            display_string(very);
        }
        else if(actual >=61)
        {
            display(0,0xc0);
            display_string(extrem);
        }

    } 
} 

void display_string(char a[])//pointer have power like to store address of other variable
{
    for(int i=0;a[i]!='\0';i++)
    {
        display(1, a[i]);
    }
}

void display(int RS, int DC)
{
    RD0=RS;//CMD
    PORTC=DC;//DISPLAY ON
    RD1=1;
    __delay_ms(10);
    RD1=0;
    __delay_ms(10);
}