#include "LED.h"


void LED_init(){
GPIO_InitPort('F');
	GPIO_SetPinDirection('F',1,'O');
	GPIO_SetPinDirection('F',2,'O');
	GPIO_SetPinDirection('F',3,'O');
}
void LED_ON(char rgb){
	switch(rgb){
		case 'r':
		  GPIO_SetPinValue('F',1,'S');
			break;
		case 'g':
			GPIO_SetPinValue('F',3,'S');
			break;
		case 'b':
			GPIO_SetPinValue('F',2,'S');
			break;
	  case 'y':
			GPIO_SetPinValue('F',1,'S');
		  GPIO_SetPinValue('F',3,'S');
			break;
		default:
			break;
	}
}
void LED_OFF(char rgb){
	switch(rgb){
		case 'r':
			GPIO_SetPinValue('F',1,'C');
			break;
		case 'g':
			GPIO_SetPinValue('F',3,'C');
			break;
		case 'b':
			GPIO_SetPinValue('F',2,'C');
			break;
		case 'y':
			GPIO_SetPinValue('F',1,'C');
		  GPIO_SetPinValue('F',3,'C');
			break;
		default:
			break;	
}
}
