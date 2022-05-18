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


void SystemInit(void);
void cooking(char* dish ,int timer);
char pause(char check);
void defrosting(char *dish , int weightFactor);



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


//case B and C function to accept weight and print corresponding cooking time
void defrosting(char *dish , int weightFactor){
			char weight = 0 ;
			int timer;
			LCD_COMMAND(0x01);
BADR: LCD_STRING(dish);
			LCD_STRING(" weight?");
			
			weight = KEYPAD_READ() ;
			if( weight < '1' || weight > '9' ){		//if user entered wrong input print err for 1 sec 
			LCD_COMMAND(0x01);
			LCD_STRING ("Err");
			delay_ms(1000);
			LCD_COMMAND(0x01);
				goto BADR;
			}
			LCD_COMMAND(0x01);
			LCD_STRING(dish);		//dish name at first line
			LCD_COMMAND(SecondRow);
			LCD_STRING("weight is:");
			LCD_DATA(weight);
			LCD_STRING("kg");		//entered weight in kg at second line
			delay_ms(2000);
			weight = weight - '0';  //converting weight to integer to calculate time
			timer = weightFactor*weight;
			LCD_COMMAND(0x01);
			LCD_STRING ("Close door &");
			LCD_COMMAND(SecondRow);
			LCD_STRING ("press sw2");					
			while( (sw2 != 0) || (door == 0) ){   //if door is closed and switch 2 is pressed begin cooking
				sw2 = readsw2;
				door = readDoor;
			}
			cooking(dish,timer);
			return;
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
	
		// system initilization 
		void SystemInit(void){

SYSCTL_RCGCGPIO_R |= 0x20; // PortF clock enable
while ((SYSCTL_PRGPIO_R & 0x20)==0); //Delay
GPIO_PORTF_LOCK_R = 0x4C4F434B; // Unlock PortF Commit register
GPIO_PORTF_CR_R |= 0x1F; // Allow changes to PF
GPIO_PORTF_AMSEL_R &= ~(0x1F); // Disable analog function
GPIO_PORTF_PCTL_R &= ~0x000FFFFF; // GPIO clear bit PCTL
GPIO_PORTF_AFSEL_R &= ~(0x1F); // No alternate function
GPIO_PORTF_DIR_R |= 0x0E; // PF321 output
GPIO_PORTF_DEN_R |= 0x1F; // Enable digital pins PF4-PF0
GPIO_PORTF_PUR_R |= 0x11;	
GPIO_PORTF_DATA_R &= ~(0x0E); // Initialize LEDs to be off
}

		//function to print time on LCD in minutes and seconds

void lcdTimer(int timer){

	int min,sec;
	char display[6];
	min = timer/60 ; sec = timer%60;
	*(display+0) = '0' + (min/10) ; //display digits from left to right & converting to char
	*(display+1) = '0' + ( min%10);
	*(display+2) = ':';
	*(display+3) = '0' + (sec/10) ;
	*(display+4) = '0' + ( sec%10);
	*(display+5) = '\0';
	LCD_COMMAND(SecondRow);
	LCD_STRING(display);
}



	
/// function to blink when cooking is done

void Finish(){
		int i = 0 ;
		LCD_COMMAND(clear);
		LCD_STRING("HAPPY MEAL");
		while(i < 6){
		GPIO_PORTF_DATA_R ^= 0x0E;      //toggle Leds
		Buzzer ^= 0x04;			//toggle Leds and buzzer
		delay_ms (1000);
		i++;

	}

}
	
	
	
	
}	
	
	
	
	
	
	
}	

