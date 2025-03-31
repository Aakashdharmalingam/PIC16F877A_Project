/*
 * File:   newmain.c
 * Author: aakas
 *
 * Created on 29 December, 2024, 6:29 PM
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
    char b[10];
    char a[]={"HLO"};
    TXIE=1;
    RCIE=1;
    
    TXSTA=0x24;
    RCSTA=0x90;
    SPBRG=64; // 9600 baud rate High;
    
    for(int i=0;i<3;i++)
    {
        TXREG=a[i];
        while(TXIF==0); //  Wait for State change;
        TXIF=0;
    }
    
    for(int i=0;i<3;i++)
    {
        while(RCIF==0);
        b[i]=RCREG;
        RCIF=0;
    }
    for(int i=0;i<3;i++)
    {
        TXREG=b[i];
        while(TXIF==0);
        TXIF=0;
    }

    
    while(1)
    {
        
    }
}
