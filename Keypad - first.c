#include "tm4c123gh6pm.h"

void KEYPAD_INIT(void){
	
	SYSCTL_RCGCGPIO_R |= 0x09;
	while((SYSCTL_PRGPIO_R & 0x09) == 0){};
		GPIO_PORTD_LOCK_R = 0x4C4F434B;
		GPIO_PORTD_CR_R |= 0x0F;
		GPIO_PORTD_AMSEL_R &= ~0x0F;
		GPIO_PORTD_PCTL_R &= ~0x0000FFFF;
		GPIO_PORTD_AFSEL_R &= ~0x0F;
		GPIO_PORTD_DIR_R |= 0x0F;   // to be updated
		GPIO_PORTD_DEN_R |= 0x0F;
		
		GPIO_PORTA_LOCK_R = 0x4C4F434B;
		GPIO_PORTA_CR_R |= 0xF0;
		GPIO_PORTA_AMSEL_R &= ~0xF0;
		GPIO_PORTA_PCTL_R &= ~0xFFFF0000;
		GPIO_PORTA_AFSEL_R &= ~0xF0;
		GPIO_PORTA_DIR_R |= 0x0F;   // to be updated
		GPIO_PORTA_DEN_R |= 0xF0;
		GPIO_PORTA_PUR_R |= 0xF0;
	}

void SysTick_wait (unsigned int delay){		//initialization 
		NVIC_ST_CTRL_R=0x00; //disable systick
		NVIC_ST_RELOAD_R=delay-1; //reload value
		NVIC_ST_CURRENT_R=0; //clear current value
		NVIC_ST_CTRL_R=0x05; //enable systick 

		while((NVIC_ST_CTRL_R&0x00010000)==0){}//wait for count flag;
} 


void Delay_1ms (unsigned int multi_time){
		int i;
		for(i=0; i<multi_time ; i++)
			{
				SysTick_wait(16000-1);	//1ms
			}
}

		unsigned char KEYPAD_READ(){
	
		unsigned char arr[4][4] = {{'1','2','3','A'},
															{'4','5','6','B'},
															{'7','8','9','C'},
															{'*','0','#','D'}};
	
		char row, col, x;
		for(row = 0; row < 4; row++)
		{
			GPIO_PORTD_DATA_R = 0x0F;
			GPIO_PORTD_DATA_R &= ~(1 << row);
			//Delay_1ms(1);
		
			for(col = 0; col < 4; col++)
			{
				x = (GPIO_PORTA_DATA_R & (1 << (col+4)));
				if(x == 0)
				{
					return arr[row][col];
				}
			}
		}
}

	int main(){
		SYSCTL_RCGCGPIO_R |= 0x20;
	while((SYSCTL_PRGPIO_R & 0x20) == 0){};
		GPIO_PORTF_LOCK_R = 0x4C4F434B;
		GPIO_PORTF_CR_R |= 0x0E;
		GPIO_PORTF_AMSEL_R &= ~0x0E;
		GPIO_PORTF_PCTL_R &= ~0x0000FFF0;
		GPIO_PORTF_AFSEL_R &= ~0x0E;
		GPIO_PORTF_DIR_R |= 0x0E;
		GPIO_PORTF_DEN_R |= 0x0E;
		GPIO_PORTF_DATA_R &= ~0x0E;
		KEYPAD_INIT();
		while(1){
		if(KEYPAD_READ() == '*')
		{
			GPIO_PORTF_DATA_R = 0x02;
		}
	}
}
