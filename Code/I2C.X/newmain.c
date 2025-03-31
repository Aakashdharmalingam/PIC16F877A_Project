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

void display(unsigned char rs, unsigned char data);
void I2C_write(unsigned char msb_add, unsigned char lsb_add, unsigned char data1, 
        unsigned char data2, unsigned char data3,unsigned char data4, 
        unsigned char data5);
unsigned char I2C_read(unsigned char msb_add, unsigned char lsb_add);

void main()
{
    unsigned char data;
    TRISD=0;
    TRISB=0;
    SSPCON = 0x28;
    //SSPADD = (FOSC/(4*CLOCK))-1
    SSPADD = 24;//100Khz
//    I2C_write(0x00, 0x05, 'F', 'G', 'H', 'I', 'J');
    
    
    __delay_ms(1000);
    display(0, 0x0e);
    
    data = I2C_read(0x00, 0x05);
    display(1, data);
    
    data = I2C_read(0x00, 0x06);
    display(1, data);
    
    data = I2C_read(0x00, 0x07);
    display(1, data);
    
    data = I2C_read(0x00, 0x08);
    display(1, data);
    
    data = I2C_read(0x00, 0x09);
    display(1, data);
    
//    data = I2C_read(0x00, 0xa0);
//    display(1, data);
    while(1){
    
    }
}

unsigned char I2C_read(unsigned char msb_add, unsigned char lsb_add)///4 byte 1 byte
{
    unsigned char data;
    SEN=1;//START
    while(SSPIF==0);
    SSPIF=0;
    
    SSPBUF=0xA0;//7 bit address along with r/w bit
    while(SSPIF==0);
    SSPIF=0;
    
    SSPBUF=msb_add;//7 bit address along with r/w bit
    while(SSPIF==0);
    SSPIF=0;
    
    SSPBUF=lsb_add;//7 bit address along with r/w bit
    while(SSPIF==0);
    SSPIF=0;
    
    RSEN=1;//Repeat START
    while(SSPIF==0);
    SSPIF=0;
    
    SSPBUF=0xA1;//7 bit address along with r/w bit
    while(SSPIF==0);
    SSPIF=0;
    
    RCEN=1;//wait for slave data enable receiver 
    while(SSPIF==0);
    SSPIF=0;
    data=SSPBUF;
    ACKDT=1;// no acknowledgement
    ACKEN=1;// no acknowmledgement
    while(SSPIF==0);
    SSPIF=0;
    
    PEN=1;//STOP
    while(SSPIF==0);
    SSPIF=0;
    
    return data;
}

void I2C_write(unsigned char msb_add, unsigned char lsb_add, unsigned char data1, 
        unsigned char data2, unsigned char data3,unsigned char data4, 
        unsigned char data5)
{
    //send the data to slave
    SEN=1;//START
    while(SSPIF==0);
    SSPIF=0;
    
    SSPBUF=0xA0;//7 bit address along with r/w bit
    while(SSPIF==0);
    SSPIF=0;
    
    SSPBUF=msb_add;//7 bit address along with r/w bit
    while(SSPIF==0);
    SSPIF=0;
    
    SSPBUF=lsb_add;//7 bit address along with r/w bit
    while(SSPIF==0);
    SSPIF=0;
    
    SSPBUF=data1;//7 bit address along with r/w bit
    while(SSPIF==0);
    SSPIF=0;
    
    SSPBUF=data2;//7 bit address along with r/w bit
    while(SSPIF==0);
    SSPIF=0;
    
    SSPBUF=data3;//7 bit address along with r/w bit
    while(SSPIF==0);
    SSPIF=0;
    
    SSPBUF=data4;//7 bit address along with r/w bit
    while(SSPIF==0);
    SSPIF=0;
    
    SSPBUF=data5;//7 bit address along with r/w bit
    while(SSPIF==0);
    SSPIF=0;
    
    PEN=1;//STOP
    while(SSPIF==0);
    SSPIF=0;
}

void display(unsigned char rs, unsigned char data)
{
    RB0=rs;//8 bit - >1 bit
    PORTD=data;//// 1 byte
    RB1=1;
    __delay_ms(10);
    RB1=0;
    __delay_ms(10);
}