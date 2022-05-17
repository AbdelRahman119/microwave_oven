#include "C:\Users\Ahmed\Downloads\tm4c123gh6pm.h"
#include <stdint.h>

void SysTick_wait (unsigned int delay)
{
//initialization 
NVIC_ST_CTRL_R=0x00; //disable systick
NVIC_ST_RELOAD_R=delay-1; //reload value
NVIC_ST_CURRENT_R=0; //clear current value
	

while((NVIC_ST_CTRL_R&0x00010000)==0){}//wait for count flag;
} 

/////////////////////////////////////////////// 

void Delay_1ms (unsigned int multi_time)
{
int i;
for(i=0; i<multi_time ; i++)
{
SysTick_wait(16000-1);	//1ms
}
}

/////////////////////////////////////////////// /////////////////////////////////////////////// 
int main()
{
Delay_1ms (15);
}