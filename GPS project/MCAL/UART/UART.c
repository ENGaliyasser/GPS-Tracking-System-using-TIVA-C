#include "TM4C123GH6PM.h"
#include "UART.h"

////////// UARTINITIALIZATION ///////
void UART_Init(char num , unsigned long  baudrate , unsigned long clock){
	unsigned long uartIBRD, uartFBRD;
	double CLDIV = (clock / (16.0 * baudrate));
	
	uartIBRD = (int)(CLDIV);
	uartFBRD = (int)((CLDIV - uartIBRD) * 64 + 0.5);
	switch( num ){
		  case '0':
            SET(SYSCTL_RCGCUART_R,0);
	          SET(SYSCTL_RCGCGPIO_R,0);
	          while((SYSCTL_PRGPIO_R & 0x01) == 0){}
	          CLEAR(UART0_CTL_R,0);
	          UART0_IBRD_R = uartIBRD;
	          UART0_FBRD_R = uartFBRD;
	          UART0_LCRH_R |= 0x70;
	          UART0_CTL_R |= 0x301;
	          GPIO_PORTA_DEN_R |= 0x03;
	          GPIO_PORTA_AFSEL_R |= 0x03;
	          GPIO_PORTA_AMSEL_R &= ~0x03;
	          GPIO_PORTA_PCTL_R |= 0x00000011;
            break;
       case '1':
            SET(SYSCTL_RCGCUART_R,1);
	          SET(SYSCTL_RCGCGPIO_R,1);
	          while((SYSCTL_PRGPIO_R & 0x02) == 0){}
	          CLEAR(UART1_CTL_R,0);
	          UART1_IBRD_R = uartIBRD;
	          UART1_FBRD_R = uartFBRD;
	          UART1_LCRH_R |= 0x70;
	          UART1_CTL_R |= 0x301;
	          GPIO_PORTB_DEN_R |= 0x03;
	          GPIO_PORTB_AFSEL_R |= 0x03;
	          GPIO_PORTB_AMSEL_R &= ~0x03;
	          GPIO_PORTB_PCTL_R |= 0x00000011;
	          break;
       case '2':
            SET(SYSCTL_RCGCUART_R,2);
	          SET(SYSCTL_RCGCGPIO_R,3);
	          while((SYSCTL_PRGPIO_R & (0x01<<3)) == 0) {}
	          CLEAR(UART2_CTL_R,0);
	          UART2_IBRD_R = uartIBRD;
	          UART2_FBRD_R = uartFBRD;
	          UART2_LCRH_R |= 0x70;
	          UART2_CTL_R |= 0x301;
	          GPIO_PORTD_DEN_R |= 0xC0;
						GPIO_PORTD_AMSEL_R &= ~0xC0;
	          GPIO_PORTD_AFSEL_R |= 0xC0;
	          GPIO_PORTD_PCTL_R |= 0x11000000;
            break;
        case '3':
            SET(SYSCTL_RCGCUART_R,3);
	          SET(SYSCTL_RCGCGPIO_R,2);
	          while((SYSCTL_PRGPIO_R & (0x01<<2)) == 0) {}
	          CLEAR(UART3_CTL_R,0);
	          UART3_IBRD_R = uartIBRD;
	          UART3_FBRD_R = uartFBRD;
	          UART3_LCRH_R |= 0x70;
	          UART3_CTL_R |= 0x301;
	          GPIO_PORTC_DEN_R |= 0xC0;
						GPIO_PORTC_AMSEL_R &= ~0xC0;
	          GPIO_PORTC_AFSEL_R |= 0xC0;
	          GPIO_PORTC_PCTL_R |= 0x11000000;
            break;
        case '4':
            SET(SYSCTL_RCGCUART_R,4);
	          SET(SYSCTL_RCGCGPIO_R,2);
	          while((SYSCTL_PRGPIO_R & (0x01<<2)) == 0) {}
	          CLEAR(UART4_CTL_R,0);
	          UART4_IBRD_R = uartIBRD;
	          UART4_FBRD_R = uartFBRD;
	          UART4_LCRH_R |= 0x70;
	          UART4_CTL_R |= 0x301;
	          GPIO_PORTC_DEN_R |= 0x30;
						GPIO_PORTC_AMSEL_R &= ~0x30;
	          GPIO_PORTC_AFSEL_R |= 0x30;
	          GPIO_PORTC_PCTL_R |= 0x00110000;
            break;
        case '5':
            SET(SYSCTL_RCGCUART_R,5);
	          SET(SYSCTL_RCGCGPIO_R,4);
	          while((SYSCTL_PRGPIO_R & (0x01<<4)) == 0) {}
	          CLEAR(UART5_CTL_R,0);
	          UART5_IBRD_R = uartIBRD;
	          UART5_FBRD_R = uartFBRD;
	          UART5_LCRH_R |= 0x70;
	          UART5_CTL_R |= 0x301;
	          GPIO_PORTE_DEN_R |= 0x30;
						GPIO_PORTE_AMSEL_R &= ~0x30;
	          GPIO_PORTE_AFSEL_R |= 0x30;
	          GPIO_PORTE_PCTL_R |= 0x00110000;
            break;
				case '6':
            SET(SYSCTL_RCGCUART_R,6);
	          SET(SYSCTL_RCGCGPIO_R,3);
	          while((SYSCTL_PRGPIO_R & (0x01<<3)) == 0) {}
	          CLEAR(UART6_CTL_R,0);
	          UART6_IBRD_R = uartIBRD;
	          UART6_FBRD_R = uartFBRD;
	          UART6_LCRH_R |= 0x70;
	          UART6_CTL_R |= 0x301;
	          GPIO_PORTD_DEN_R |= 0x30;
						GPIO_PORTD_AMSEL_R &= ~0x30;
	          GPIO_PORTD_AFSEL_R |= 0x30;
	          GPIO_PORTD_PCTL_R |= 0x00110000;
            break;
				case '7':
            SET(SYSCTL_RCGCUART_R,7);
	          SET(SYSCTL_RCGCGPIO_R,4);
	          while((SYSCTL_PRGPIO_R & (0x01<<4)) == 0) {}
	          CLEAR(UART7_CTL_R,0);
	          UART7_IBRD_R = uartIBRD;
	          UART7_FBRD_R = uartFBRD;
	          UART7_LCRH_R |= 0x70;
	          UART7_CTL_R |= 0x301;
	          GPIO_PORTE_DEN_R |= 0x03;
						GPIO_PORTE_AMSEL_R &= ~0x03;
	          GPIO_PORTE_AFSEL_R |= 0x03;
	          GPIO_PORTE_PCTL_R |= 0x00000011;
            break;
							default:
            break;
       
    }
	}
/////////////////TRANSMIT CHAR///////////////
      void UART_TRANSMITChar(char num , unsigned char ch){
				
				
       switch(num){
				 case '0': 
            
	               while((UART0_FR_R&TXFULL) != 0){}
	               UART0_DR_R = ch; 
		        break;
				 case '1':
				 
	                while((UART1_FR_R&TXFULL) != 0){}
	                UART1_DR_R = ch; 
		        break;
	       case '2':
							 
	                while((UART2_FR_R&TXFULL) != 0){}
	                UART2_DR_R = ch; 
		        break;
	       case '3':
					  				 
	                while((UART3_FR_R&TXFULL) != 0){}
	                UART3_DR_R = ch; 
		        break;
	       case '4':
								 
	                while((UART4_FR_R&TXFULL) != 0){}
	                UART4_DR_R = ch; 
		        break;
	       case '5': 
					 
	                while((UART5_FR_R&TXFULL) != 0){}
	                UART5_DR_R = ch; 
		        break;
	       
				 case '6':
									 
	                while((UART6_FR_R&TXFULL) != 0){}
	                UART6_DR_R = ch; 
		        break;
				 case '7':
					  				 
	                while((UART7_FR_R&TXFULL) != 0){}
	                UART7_DR_R = ch; 
		        break;
										default:
            break;
	
	
}
			 }
			//////////// RECEIVE CHAR /////////
			 unsigned char UART_RECEIVEChar(char num ){
       switch(num){
				 case '0':				 
	                while((UART0_FR_R&RXEMPTY) != 0){}
	                return UART0_DR_R&0xFF;
		     break;
				 case '1':				 
	                while((UART1_FR_R&RXEMPTY) != 0){}
	                return UART1_DR_R&0xFF;
		     break;
	       case '2':				 
	                while((UART2_FR_R&RXEMPTY) != 0){}
	                return UART2_DR_R&0xFF; 
		     break;
	       case '3':				 
	                while((UART3_FR_R&RXEMPTY) != 0){}
	                return UART3_DR_R&0xFF;
		     break;
	       case '4':				 
	                while((UART4_FR_R&RXEMPTY) != 0){}
	                return UART4_DR_R&0xFF;
		     break;
	       case '5':				 
	                while((UART5_FR_R&RXEMPTY) != 0){}
	                return UART5_DR_R&0xFF;
		     break;
	       
				 case '6':				 
	                while((UART6_FR_R&RXEMPTY) != 0){}
	                return UART6_DR_R&0xFF;
		     break;
				 case '7':				 
	                while((UART7_FR_R&RXEMPTY) != 0){}
	                return UART7_DR_R&0xFF;
		     break;
	       default:
         break;
	
}
			 }
			 /////////////STRING TRANSMIT ///////////////
			 void UART_TRANSMITString(char num ,char *str){
				 while(*str){
          UART_TRANSMITChar( num ,*str );
          str++;
       
			 } }
			 ///////////// STRING RECEIVE ///////////
			 void UART_RECEIVEString(char num ,char *str, char stopCh){		
	char c = UART_RECEIVEChar( num );
	while(c && c != stopCh){
		*str = c;
		str++;
		c = UART_RECEIVEChar( num );
	}
	*str = 0x00;
}
