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

void spi_write(int msb_add, int lsb_add, int data);
void display(int rs, int data);

void main(){
    int data;
    TRISC=0x10;
    TRISB=0;
    TRISD=0;
    
    SSPSTAT=0;
    SSPCON=0x20;
    
    display(0, 0x0e);
    display(1, 'A');
    
    RB0=1;
    __delay_ms(1000);

// THIS STATEMENTS HAS BOTH WRITE AND READ CONCEPTS READ SLOWLY>..    
//    RB0=0;//START  CS PIN
//    SSPBUF=0X06;//WREN 
//    while(SSPIF==0);//SSPIF=1
//    SSPIF=0;
//    RB0=1;//STOP  CS PIN
//    __delay_ms(100);
//    
//    spi_write(0x00, 0x00, 'A');
    
    RB0=0;//START  CS PIN
    SSPBUF=0x03;//read enable
    while(SSPIF==0);//SSPIF=1
    SSPIF=0;
    __delay_ms(100);
    
    SSPBUF=0x00;//8 bit
    while(SSPIF==0);//SSPIF=1
    SSPIF=0;
    __delay_ms(100);
    
    SSPBUF=0x00;// 8 bit
    while(SSPIF==0);//SSPIF=1
    SSPIF=0;
    __delay_ms(100);
    
    SSPBUF=0xFF;//dummy
    while(SSPIF==0);//SSPIF=1
    SSPIF=0;
    data = SSPBUF;//full duplex
    __delay_ms(100);
    RB0=1;//Stop  CS PIN
    
    display(1, data);
    while(1){
    
    }
}

void spi_write(int msb_add, int lsb_add, int data)
{ 
    RB0=0;//START  CS PIN
    SSPBUF=0X02;//write sequence
    while(SSPIF==0);//SSPIF=1
    SSPIF=0;
    __delay_ms(100);
    
    SSPBUF=msb_add;//write sequence
    while(SSPIF==0);//SSPIF=1
    SSPIF=0;
    
    SSPBUF=lsb_add;//write sequence
    while(SSPIF==0);//SSPIF=1
    SSPIF=0;
    __delay_ms(100);
    
    SSPBUF=data;
    while(SSPIF==0);//SSPIF=1
    SSPIF=0;
    __delay_ms(100);
    RB0=1;//STOP CS PIN
    
    RB0=0;//START  CS PIN
    SSPBUF=0X04;//WRDI
    while(SSPIF==0);//SSPIF=1
    SSPIF=0;
    RB0=1;//STOP  CS PIN
    __delay_ms(100);

}
void display(int rs, int data)
{
    RB6=rs;
    PORTD=data;
    RB7=1;
    __delay_ms(10);
    RB7=0;
    __delay_ms(10);
}