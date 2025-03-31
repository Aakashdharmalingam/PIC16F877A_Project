// CONFIG
#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
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
void display(int rs, int data);

void main() 
{
    int data;
    TRISB=0;
    TRISC=0;
    EEADR=0x02; // WRITE PROTOCAL
    EEDATA='S';
    EECON1=0X00;
    WREN=1;
    EECON2=0X55;
    EECON2=0XAA;
    WR=1;
    WREN=0;
    while(WR==1){}//wait for WR bit cleared
    
    EEADR=0x02; // READ PROTOCAL
    EECON1=0X00;
    RD=1;
    data = EEDATA;
    
    display(0, 0x0e);
    display(1, 'A');
    display(1, data);
    while(1){
        
    }
}
void display(int rs, int data)
{
    RC0=rs;
    PORTB=data;
    RC1=1;
    __delay_ms(10);
    RC1=0;
    __delay_ms(10);
}