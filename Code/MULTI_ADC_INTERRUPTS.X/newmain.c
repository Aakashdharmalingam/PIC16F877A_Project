#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (All program memory code-protected)
#include <xc.h>
#include <stdio.h>
#define _XTAL_FREQ 10000000 //3.278 KHz to 20 MHz-> 10^6
void display_string(char *a);
void display(int RS, int DC);
int count=0;
int main() {
    char arr[10];
    int low_bit;
    int high_bit;
    int bits;
    
    
    ADCON0 =0x01;//adc on/ channel 0 
    ADCON1 =0x80;//right justified -> vref + and - 
    TRISD=TRISC=0;
    PORTD=PORTC=0;
    PORTB=0;
    OPTION_REG=0X00;
    INTE=1;
    GIE=1;

   
    display(0, 0x0C);//display on
    display(0, 0x38);
    
    while(1)
    {   
        ADCON0 =0x01;//adc on/ channel 0 
        __delay_ms(10);
        GO_nDONE = 1;//start the ADC conversion 
        while(GO_nDONE==1){}//wait for state change
        low_bit = ADRESL;//1024
        high_bit = ADRESH;
        
        bits = low_bit | high_bit<<8;
        sprintf(arr, "%04d", bits);//int to char in string
        display(0, 0x80);
        
        for(int i=0;arr[i]!='\0';i++)  {
            display(1, arr[i]);
        }
        __delay_ms(300);      
        ADCON0 =0x09;//adc on/ channel 1
        __delay_ms(10);
        GO_nDONE = 1;//start the ADC conversion 
        while(GO_nDONE==1){}//wait for state change
        low_bit = ADRESL;//1024
        high_bit = ADRESH;
        
        bits = low_bit | high_bit<<8;
        sprintf(arr, "%04d", bits);//int to char in string
        display(0, 0xc0);
        display_string(arr);
        
        sprintf(arr, "%0d", count);
        display(0, 0xcd);
        display_string(arr);               
    } 
} 
void display_string(char *a)//pointer have power like to store address of other variable
{
    for(int i=0;a[i]!='\0';i++)
    {
        display(1, a[i]);
    }
}
void display(int RS, int DC){
    RD0=RS;//CMD
    PORTC = DC;//DISPLAY ON
    RD1=1;
    __delay_ms(10);
    RD1=0;
    __delay_ms(10);
}
void __interrupt() ISR()
{       
    if(INTF ==1)   {   
        count=count+1;
        INTF=0;
    }   
}