#include <avr/io.h>
#include <stdint.h>                         // needed for uint8_t
#include <avr/interrupt.h>
#define FOSC 16000000                       // Clock Speed
#define BAUD 9600                
#define MYUBRR FOSC/16/BAUD -1
volatile int i=0,a0[500],a1[500],a2[500],a3[500],a4[500],a5[500],flag=0;;
void adc_init()
{
    ADMUX = (1<<REFS0);
    ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
}
uint16_t adc_read(uint8_t ch)
{
  ch &= 0b00000111;  
  ADMUX = (ADMUX & 0xF8)|ch; 
  ADCSRA |= (1<<ADSC);
  while(ADCSRA & (1<<ADSC));
  return (ADC);
}
ISR (USART_RXC_vect)
{
    s = UDR0;
    if(s=='s')
      flag_stop=1;
}
void USART_Transmit(  uint8_t data )
{ while ( !( UCSR0A & (1<<5)) )
             ;
  UDR0 = data;
 }
int minimum_arr(int arr[500])
{for (j = 1; j < 500; j++)
    {
        if (arr[j] < minimum)
        {
           minimum = arr[j];
        }
    }
  
}
int maximum_arr(int arr[500])
{for (j = 1; j < 500; j++)
    {
        if (arr[j] > maximum)
        {
           maximum = arr[j];
        }
    }
  
}
void calculate_max_amplitude()
{  
  A0 = maximum_arr(a0[500])-minimum_arr(a0[500]);
  A1 = maximum_arr(a1[500])-minimum_arr(a1[500]);
  A2 = maximum_arr(a2[500])-minimum_arr(a2[500]);
  A3 = maximum_arr(a3[500])-minimum_arr(a3[500]);
  A4 = maximum_arr(a4[500])-minimum_arr(a4[500]);
  A5 = maximum_arr(a5[500])-minimum_arr(a5[500]);
}
void send_values()
{ //work in progress
}
void GSM_init()
{ //work in progress
}
int main(void)
{ adc_init();
  UBRR0H = (MYUBRR >> 8);
  UBRR0L = MYUBRR;
  UCSR0B |= (1 << RXEN0) | (1 << TXEN0);                       
  UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);
  UCSR0B |= (1 << RXCIE0);                   //enable receive interrupt
  i=0;
  GSM_init();
  while(1)
  {   
      while(!flag_stop)  
      { 
        a0[i] = adc_read(0);                       
        a1[i] = adc_read(1);                  
        a2[i] = adc_read(2);
        a3[i] = adc_read(3);
        a4[i] = adc_read(4);
        a5[i] = adc_read(5);
        i++;
        if(i>=500)
        i=0;
      }

      flag_stop=0;
      calculate_max_amplitude();
      send_values();
      
   }
}
