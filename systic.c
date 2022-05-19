#include "C:\Users\Ahmed\Downloads\tm4c123gh6pm.h"
#include <stdint.h>

void SysTick_wait (unsigned int delay)
{
//initialization 
NVIC_ST_CTRL_R=0x00; //disable systick
NVIC_ST_RELOAD_R=delay-1; //reload value
NVIC_ST_CURRENT_R=0; //clear current value
NVIC_ST_CTRL_R=0x00000005; //enable systick 	

while((NVIC_ST_CTRL_R&0x00010000)==0){}//wait for count flag;
} 

/////////////////////////////////////////////// 

void delay_inMilli (unsigned int delay)
{
int i;
for(i=0; i<delay ; i++)
{
SysTick_wait(80000/5);	//1ms
}
}


/////////////////////////////////////////////// /////////////////////////////////////////////// 
void delay_inMicro (unsigned int delay)
{
int i;
for(i=0; i<delay ; i++)
{
SysTick_wait(16);	//1 microsec
}
}
int main()
{
Delay_1ms (15);
}