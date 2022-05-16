#include <stdint.h>
#include "C:\ARM\tm4c123gh6pm.h"



void LCD_COMMAND ( char com )
		{
      GPIO_PORTE_DATA_R &= ~ 0x06;
			//Rs=0 Rw=0
			GPIO_PORTB_DATA_R = com;
		  GPIO_PORTE_DATA_R |= 0x08;

			//delay_1ms ( 5 );
		   GPIO_PORTE_DATA_R &=~0x08;
		}
		
void LCD_initialization ()
	{
		SYSCTL_RCGCGPIO_R |= 0X12;
	while((SYSCTL_PRGPIO_R & 0x12) == 0){};
		//PORTB
		GPIO_PORTB_LOCK_R = 0x4C4F434B;
		GPIO_PORTB_CR_R |= 0xFF;
		GPIO_PORTB_AMSEL_R &= ~0xFF;
		GPIO_PORTB_PCTL_R &= ~0xFFFFFFFF;
		GPIO_PORTB_AFSEL_R &= ~0xFF;
		//PORTE
		GPIO_PORTB_LOCK_R = 0x4C4F434B;
		GPIO_PORTE_CR_R |= 0x0E;
		GPIO_PORTE_AMSEL_R &= ~0x0E;
		GPIO_PORTE_PCTL_R &= ~0x0000FFF0;
		GPIO_PORTE_AFSEL_R &= ~0x0E;
		
		GPIO_PORTB_DIR_R = 0xFF;
		GPIO_PORTB_DEN_R = 0xFF;
		GPIO_PORTE_DIR_R |= 0x0E;
		GPIO_PORTE_DEN_R |= 0x0E;
		
		LCD_COMMAND (0X30);
		LCD_COMMAND (0X38);
		LCD_COMMAND (0X06);
		LCD_COMMAND (0X01);
		LCD_COMMAND (0X0F);
	}
	
	
		
		
		void LCD_DATA (char data){
		GPIO_PORTE_DATA_R &= ~0x04;
		GPIO_PORTE_DATA_R |= 0x02;
		GPIO_PORTB_DATA_R = data;
		GPIO_PORTE_DATA_R |= 0x08;
		
		//delay_1ms ( 5 );
		GPIO_PORTE_DATA_R &= ~0x08;
		
		
	}
		
