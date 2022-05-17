#include "tm4c123gh6pm.h"
#include "lcdmacros.h"
#define buzzer GPIO_PORTx_DATA_R  //0x10

char input;
int sw1,sw2,sw3;
int timer;
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
void cooking(timer){
	int reset = 0;
	lcd_command(Sec_line);
	while(timer != 0){
	if( (sw3 == 1 || sw1 == 0) {						//check for the door and bottun each second
		pause(timer) ; 	
		
	}
	if (reset == 1) return;
	lcdoutput(timer);
	systic_doubledelay(1000);
	timer--;	
		
		
	}
	blinking();
	return;
	
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

