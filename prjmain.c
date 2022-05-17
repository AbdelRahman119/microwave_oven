#include "tm4c123gh6pm.h"
#include "lcdmacros.h"
#include "lcd2.h"
#include "systic.h"
#include "keypad.h"
#define readsw1       (GPIO_PORTF_DATA_R & 0x10)
#define readsw2       (GPIO_PORTF_DATA_R & 0x01)
#define readDoor  		(GPIO_PORTA_DATA_R & 0x08)
#define Buzzer				 (GPIO_PORTA_DATA_R)   //pin A2 (0100)
#define ctoi(c)		(c - '0')
#define itoc(i)		(i + '0')


char *dish,input,sw1,sw2,door;


void blinking(){
		int i = 0 ;
	while(i < 6){
	GPIO_PORTF_DATA_R=GPIO_PORTF_DATA_R ^0x0E; //togglo PF 1,2,3
	buzzer ^= 0x10;
	genericDelay(1000);
		i++;
		
	}
return;	
}

void cooking(char* dish ,int timer){

	char reset = 0;
	char i ;
	LCD_COMMAND(clear);
	LCD_STRING(dish);


	while(timer >= 0){
			GPIO_PORTF_DATA_R |= 0x0E; //leds are on;
			LCD_COMMAND(SecondRow);
			door = readDoor;	
			sw1 = readsw1;

			lcdTimer(timer);
			//door = ((GPIO_PORTA_DATA_R & 0x08) >> 3);

			if (timer!= 0 ){
				for(i=0 ; i<50 ; i++){
						sw1 = readsw1 ;
						sw2 = readsw2 ;
						door = readDoor ;
						delay_ms(20);							//if door is open door = 1) or sw1 is pressed (sw1=0) pause		
								if( door == 0 ) reset = pause(sw1) ;
								if(sw1 == 0) {
									delay_ms(20);
									sw1 = readsw1 ;
									if(sw1 == 0 ) reset = pause(sw1) ;
								}
								if (reset == 1) return;
																		
				
			}
		}
			timer--;

		}
	Finish();
}	

//void cooking(timer){

//	countdownLcd(timer);
//	return;
//}
	void pause(timer){
int reset = 0;		
		while( (( s3 != 0) & ( sw2 !=0 ) ) | sw1 != 1 )
		{
			lcdoutput(timer);
			sw1 = (GPIO_PORTF_DATA_R & 0x10);
			sw3 = (GPIO_PORTB_DATA_R & 0x10);
		}	;
if(sw1 ==1 ) reset = 1;		
return reset;		
	
	
	}

int main(){
char dish;
int weight;	
int timer;
	while(1){
	lcdoutput("Please, choose from A,B,C,D");
	input = readKeypad();		//read from keypad a,b,c,d
	sw1_2 = readSwitch1_2(); 	
	sw3 = checkDoor();

		switch(input){
	case 'A':
		
	lcdoutput("Popcorn");
	sw2 = (GPIO_PORTF_DATA_R & 0x01)
	if(sw2==0) cooking(60);
	//ccvv
	break; 
	
	case 'B':
lcdoutput("Beef");		
	
	weight = readweight();
	timer = 30*weight;
	Lcd();
	
	case 'C':
  lcdoutput("Beef");		
	
	weight = readweight();
	timer = 12*weight;

	break; 
	case 'D':


	break; 
	
	default:
		

}
	
	
	
	
	
	
}	
	
	
	
	
	
	
}	

