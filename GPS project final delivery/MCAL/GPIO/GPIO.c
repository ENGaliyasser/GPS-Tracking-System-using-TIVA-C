#include "GPIO.h"


	
void GPIO_InitPort(uint8_t port)
{
	switch (port)
{
		case 'A':
			
		     SET_BIT(SYSCTL_RCGCGPIO_R,0); // set port A
		
		while (READ_BIT(SYSCTL_PRGPIO_R,0) == 0){}; // check the delay
			
         GPIO_PORTA_LOCK_R = 0x4C4F434B;// 
         GPIO_PORTA_CR_R = 0xFC; //access 2>7 pins in port A
         GPIO_PORTA_AMSEL_R = 0; // disable analog mode select
         GPIO_PORTA_AFSEL_R = 0; // no alternative fn
			// GPIO_PORTA_PCTL_R = 0;
         GPIO_PORTA_DEN_R = 0xFC; // pins 2>7 are digital 
		
break;
			
			
			
		case 'B':
			
		     SET_BIT(SYSCTL_RCGCGPIO_R,1); // set port B
		
		while (READ_BIT(SYSCTL_PRGPIO_R,1) == 0){}; // check the delay
			
         GPIO_PORTB_LOCK_R = 0x4C4F434B;// 
         GPIO_PORTB_CR_R = 0x3C; //access 2>5 pins in port B
         GPIO_PORTB_AMSEL_R = 0; // disable analog mode select
         GPIO_PORTB_AFSEL_R = 0; // no alternative fn
			// GPIO_PORTB_PCTL_R = 0;
         GPIO_PORTB_DEN_R = 0x3C; // pins 2>5 are digital
		
		
break;
			
			
			
		case 'D':
			
		     SET_BIT(SYSCTL_RCGCGPIO_R,3); // set port D
		
		while (READ_BIT(SYSCTL_PRGPIO_R,3) == 0){}; // check the delay
			
         GPIO_PORTD_LOCK_R = 0x4C4F434B;// 
         GPIO_PORTD_CR_R = 0xCC; //access 2,3,6,7 pins in port D
         GPIO_PORTD_AMSEL_R = 0; // disable analog mode select
         GPIO_PORTD_AFSEL_R = 0; // no alternative fn
			// GPIO_PORTD_PCTL_R = 0;
         GPIO_PORTD_DEN_R = 0xCC; // pins 2,3,6,7 are digital
		
	
break;
		
		
		
		case 'E':
			
		     SET_BIT(SYSCTL_RCGCGPIO_R,4); // set port E
		
		while (READ_BIT(SYSCTL_PRGPIO_R,4) == 0){}; // check the delay
			
         GPIO_PORTE_LOCK_R = 0x4C4F434B;// 
         GPIO_PORTE_CR_R = 0x3F; //access 0>5 pins in port E
         GPIO_PORTE_AMSEL_R = 0; // disable analog mode select
         GPIO_PORTE_AFSEL_R = 0; // no alternative fn
			// GPIO_PORTE_PCTL_R = 0;
         GPIO_PORTE_DEN_R = 0x3F; // pins 0>5 are digital
		
	
break;
		
		
		
		case 'F':
			
				SYSCTL_RCGCGPIO_R|=0x20;
				while((SYSCTL_PRGPIO_R&0X20)==0){}
				//delay=1+1; //to insert delay
				GPIO_PORTF_LOCK_R=GPIO_LOCK_KEY;
				GPIO_PORTF_CR_R=0X1F;
				//GPIO_PORTF_DIR_R=0x0E;
				GPIO_PORTF_AFSEL_R=0;
				GPIO_PORTF_PCTL_R=0;
				GPIO_PORTF_AMSEL_R=0;
				GPIO_PORTF_PUR_R=0X11;
				GPIO_PORTF_DEN_R=0X1F;
		
break;

}
}

void GPIO_SetPortValue(uint8_t port, uint8_t value)
{
   switch(port)
	 {
		 case 'A':
			GPIO_PORTA_DATA_R = value;
		     
break;
			
			
			
		case 'B':
			GPIO_PORTB_DATA_R = value;
		     		
break;
			
			
			
		case 'D':
			GPIO_PORTD_DATA_R = value;
		     	
break;
		
		
		
		case 'E':
			GPIO_PORTE_DATA_R = value;
		     	
break;
		
		
		
		case 'F':
			GPIO_PORTF_DATA_R = value;
		     		
break;
	
	}
}

void GPIO_SetPinDirection(uint8_t port, uint8_t pin, uint8_t direction)
{
   switch(port)
	 {
		 case 'A':
			if ( direction == 'O' ) // output
			{
				SET_BIT(GPIO_PORTA_DIR_R,pin); // set the pin as output

			}
			else if ( direction == 'I' ) // input
			{
				CLEAR_BIT(GPIO_PORTA_DIR_R,pin); // set pin as input
				SET_BIT(GPIO_PORTA_PUR_R,pin); // enable switch
			}
			
break;
			
		case 'B':
			if ( direction == 'O' ) // output
			{
				SET_BIT(GPIO_PORTB_DIR_R,pin); // set the pin as output
			}
			else if ( direction == 'I' ) // input
			{
				CLEAR_BIT(GPIO_PORTB_DIR_R,pin); // set pin as input
				SET_BIT(GPIO_PORTB_PUR_R,pin); // enable switch
			}
		     		
break;
			
		case 'D':
			if ( direction == 'O' ) // output
			{
				SET_BIT(GPIO_PORTD_DIR_R,pin); // set the pin as output
			}
			else if ( direction == 'I' ) // input
			{
				CLEAR_BIT(GPIO_PORTD_DIR_R,pin); // set pin as input
				SET_BIT(GPIO_PORTD_PUR_R,pin); // enable switch
			}
		     	
break;
	
		
		case 'E':
			if ( direction == 'O' ) // output
			{
				SET_BIT(GPIO_PORTE_DIR_R,pin); // set the pin as output
			}
			else if ( direction == 'I' ) // input
			{
				CLEAR_BIT(GPIO_PORTE_DIR_R,pin); // set pin as input
				SET_BIT(GPIO_PORTE_PUR_R,pin); // enable switch
			}
		     	
break;

		
		case 'F':
			if ( direction == 'O' ) // output
			{
				SET_BIT(GPIO_PORTF_DIR_R,pin); // set the pin as output
			}
			else if ( direction == 'I' ) // input
			{
				CLEAR_BIT(GPIO_PORTF_DIR_R,pin); // set pin as input
				SET_BIT(GPIO_PORTF_PUR_R,pin); // enable switch
			}
		     		
break;
	
	}
}

void GPIO_SetPinValue(uint8_t port, uint8_t pin, uint8_t value )
{
	switch(port)
	 {
		 case 'A':
			if ( value == 'S' ) // set
			{
				SET_BIT(GPIO_PORTA_DATA_R,pin); // pin is set
			}
			else if ( value == 'C' ) //clear
			{
				CLEAR_BIT(GPIO_PORTA_DATA_R,pin); // pin is cleared
			}
		     
break;
			
			
			
		case 'B':
			if ( value == 'S' ) 
			{
				SET_BIT(GPIO_PORTB_DATA_R,pin); // pin is set
			}
			else if ( value == 'C' ) 
			{
				CLEAR_BIT(GPIO_PORTB_DATA_R,pin); // pin is cleared
			}
		     		
break;
			
			
			
		case 'D':
			if ( value == 'S' ) 
			{
				SET_BIT(GPIO_PORTD_DATA_R,pin); // pin is set
			}
			else if ( value == 'C' ) 
			{
				CLEAR_BIT(GPIO_PORTD_DATA_R,pin); // pin is cleared
			}
		     	
break;
		
		
		
		case 'E':
			if ( value == 'S' ) 
			{
				SET_BIT(GPIO_PORTE_DATA_R,pin); // pin is set
			}
			else if ( value == 'C' ) 
			{
				CLEAR_BIT(GPIO_PORTE_DATA_R,pin); // pin is cleared
			}
		     	
break;
		
		
		
		case 'F':
		  if ( value == 'S' ) 
			{
				SET_BIT(GPIO_PORTF_DATA_R,pin); // pin is set
			}
			else if ( value == 'C' ) 
			{
				CLEAR_BIT(GPIO_PORTF_DATA_R,pin); // pin is cleared
			}
break;
	
	}
}

uint8_t GPIO_GetPinValue(uint8_t port, uint8_t pin)
{
	switch(port)
	 {
		 case 'A':
			 return READ_BIT(GPIO_PORTA_DATA_R,pin); // Read value of the desired pin
		     
break;
			
			
			
		case 'B':
			 return READ_BIT(GPIO_PORTB_DATA_R,pin); // Read value of the desired pin
		     		
break;
			
			
			
		case 'D':
			 return READ_BIT(GPIO_PORTD_DATA_R,pin); // Read value of the desired pin
		     	
break;
		
		
		
		case 'E':
			 return READ_BIT(GPIO_PORTE_DATA_R,pin); // Read value of the desired pin
		     	
break;
		
		
		
		case 'F':
			 return READ_BIT(GPIO_PORTF_DATA_R,pin); // Read value of the desired pin
		     		
break;
		
		default: return 0;
	}
	 
}
