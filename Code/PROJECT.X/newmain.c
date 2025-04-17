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

void write_data(unsigned char address, unsigned char data);
unsigned char read_data(unsigned char address);
void display(unsigned char rs, unsigned char data);

void main() {
    unsigned char angle[4] = {0x01, 0x02, 0x04, 0x08};
    unsigned char resume=0;
    OPTION_REG = 0X07;
    
    TRISB = 0xff;
    TRISC = 0;
    PORTC=0;
    
    resume = read_data(0x00);//READ THE 0x00 address -> 3
    if(resume!=0)
    {
        for(unsigned char i=resume;i<4;i++)//2 to 4
        { 
            write_data(0, i);//3
            PORTC = angle[i];
            __delay_ms(1000);
        }
        write_data(0, 0);//complete
    }

    display(0, 0x0e);
    while (1) {
        if(RB0==0)//button press
        {
            while(RB0==0);//release
            for(unsigned char i=0;i<4;i++)
            { 
                write_data(0, i);///update the status in EEPROM
                PORTC = angle[i];
                __delay_ms(1000);
            }
            write_data(0, 0);///MOTOR ROTATE COMPLETY
        }
    }
}

void display(unsigned char rs, unsigned char data) {
    RB6 = 1&rs;
    PORTD = data;
    RB7 = 1;
    __delay_ms(10);
    RB7 = 0;
    __delay_ms(10);
}

void write_data(unsigned char address, unsigned char data) {
    EEADR = address;
    EEDATA = data;
    EECON1 = 0X00;
    WREN = 1;
    EECON2 = 0X55;
    EECON2 = 0XAA;
    WR = 1;
    WREN = 0;
    while (WR == 1);
}

unsigned char read_data(unsigned char address) {
    unsigned char data;
    EEADR = address;
    EECON1 = 0X00;
    RD = 1;
    data = EEDATA;
    return data;
}
