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
#include <stdio.h>
#define _XTAL_FREQ 10000000
void display(int RS, int DC);

void main() 
{
    TRISB=TRISC=0;
    PORTB=PORTC=0;
    char name[]={"Hello"};
    int i;
    display(0,0x0e);
    display(0, 0x38);
    for(i=0;name[i]!='\0';i++)
        display(1, name[i]);
    while(1)
        
    {
        
    }


}
void display(int RS, int DC)
{
    RB2=RS;
    PORTC=DC;
    RB4=1;
    __delay_ms(10);
    RB4=0;
    __delay_ms(10);
}
