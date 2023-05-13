#include "UART.h"

//int main(){}
void UART0_Init( unsigned long  baudrate ){
unsigned long uartIBRD, uartFBRD,dumyDelay;
	double CLDIV = (clock / (16.0 * baudrate));
	
	uartIBRD = (int)(CLDIV);
	uartFBRD = (int)((CLDIV - uartIBRD) * 64 + 0.5);
	SET_BIT(SYSCTL_RCGCUART_R,0);
	while((SYSCTL_PRUART_R&0X01)==0){}
	SET_BIT(SYSCTL_RCGCGPIO_R,0);
	while((SYSCTL_PRGPIO_R & 0x01) == 0){}
	CLEAR_BIT(UART0_CTL_R,0);
	UART0_IBRD_R = uartIBRD;
	UART0_FBRD_R = uartFBRD;
	UART0_LCRH_R |= 0x70;
	UART0_CTL_R |= 0x301;
	GPIO_PORTA_DEN_R |= 0x03;
	GPIO_PORTA_AFSEL_R |= 0x03;
	GPIO_PORTA_AMSEL_R &= ~0x03;
	GPIO_PORTA_PCTL_R |= 0x00000011;

	}
/////////////////TRANSMIT CHAR///////////////
void UART0_CharTX( unsigned char ch){				 
 while((UART0_FR_R&0x02) != 0){}
 UART0_DR_R = ch; 

			 }
			//////////// RECEIVE CHAR /////////
unsigned char UART0_CharRX(){
	while((UART0_FR_R&0x10) != 0){}
	return UART0_DR_R&0xFF;

			 }
			 /////////////STRING TRANSMIT ///////////////
   void UART0_StringTX(char *str){
		 while(*str!='\0'){
				UART0_CharTX(*str );
				str++;
		 
		 } }
			 ///////////// STRING RECEIVE ///////////
void UART0_StringRX(char *str, char stopCh){		
 char c = UART0_CharRX();
	while( c != stopCh){
		*str = c;
		str++;
		c = UART0_CharRX();
	}
	*str = 0x00;
}
////////// UARTINITIALIZATION ///////
void UART5_Init( unsigned long  baudrate ){
	unsigned long uartIBRD, uartFBRD,dumyDelay;
	double CLDIV = (clock / (16.0 * baudrate));
	uartIBRD = (int)(CLDIV);
	uartFBRD = (int)((CLDIV - uartIBRD) * 64 + 0.5);
  SET_BIT(SYSCTL_RCGCUART_R,5);
	while((SYSCTL_PRUART_R&(0x20))==0){}
	SET_BIT(SYSCTL_RCGCGPIO_R,4);
	dumyDelay= 1+1;
 // while((SYSCTL_PRGPIO_R & (0x20)) == 0) {}
	CLEAR_BIT(UART5_CTL_R,0);
	UART5_IBRD_R = uartIBRD;
	UART5_FBRD_R = uartFBRD;
	UART5_LCRH_R |= 0x70;
	UART5_CTL_R |= 0x301;
	GPIO_PORTE_DEN_R |= 0x30;
	GPIO_PORTE_AMSEL_R &= ~0x30;
	GPIO_PORTE_AFSEL_R |= 0x30;
	GPIO_PORTE_PCTL_R |= 0x00110000;

	}
/////////////////TRANSMIT CHAR///////////////
void UART5_CharTX( unsigned char ch){				 
 while((UART5_FR_R&0x02) != 0){}
 UART5_DR_R = ch; 

			 }
			//////////// RECEIVE CHAR /////////
unsigned char UART5_CharRX(){
	while((UART5_FR_R&0x10) != 0){}
	return UART5_DR_R&0xFF;

			 }
			 /////////////STRING TRANSMIT ///////////////
   void UART5_StringTX(char *str){
		 while(*str != '\0'){
				UART5_CharTX(*str );
				str++;
		 
		 } }
			 ///////////// STRING RECEIVE ///////////
void UART5_StringRX(char *str, char stopCh){		
 char c = UART5_CharRX();
	while(c != stopCh){
		*str = c;
		str++;
		c = UART5_CharRX();
	}
	*str = 0x00;
}
/////////////////////UART2/////////////////

void UART2_Init( unsigned long  baudrate ){
	unsigned long uartIBRD, uartFBRD,dumyDelay;
	double CLDIV = (clock / (16.0 * baudrate));
	uartIBRD = (int)(CLDIV);
	uartFBRD = (int)((CLDIV - uartIBRD) * 64 + 0.5);
	SET_BIT(SYSCTL_RCGCUART_R,2);
	while((SYSCTL_PRUART_R&(0x04))==0){}
	SET_BIT(SYSCTL_RCGCGPIO_R,3);
	while((SYSCTL_PRGPIO_R & (0x08)) == 0) {}
	CLEAR_BIT(UART2_CTL_R,0);
	UART2_IBRD_R = uartIBRD;
	UART2_FBRD_R = uartFBRD;
	UART2_LCRH_R |= 0x70;
	UART2_CTL_R |= 0x301;
	GPIO_PORTD_DEN_R |= 0xC0;
	GPIO_PORTD_AMSEL_R &= ~0xC0;
	GPIO_PORTD_AFSEL_R |= 0xC0;
	GPIO_PORTD_PCTL_R |= 0x11000000;

}
void UART2_CharTX( unsigned char ch){
	while((UART2_FR_R&0x02) != 0){}
	UART2_DR_R = ch; 

}
unsigned char UART2_CharRX(){
	while((UART2_FR_R&0x10) != 0){}
	return UART2_DR_R&0xFF; 

}
void UART2_StringTX(char *str){
 while(*str!='\0'){
   UART2_CharTX(*str );
    str++;
       
			 }	
}
void UART2_StringRX(char *str, char stopCh){
	char c = UART2_CharRX();
	while( c != stopCh){
		*str = c;
		str++;
		c = UART2_CharRX();
	}
	*str = 0x00;
}




////////////////////uart7////////////
void UART7_Init( unsigned long  baudrate ){
	unsigned long uartIBRD, uartFBRD,dumyDelay;
	double CLDIV = (clock / (16.0 * baudrate));
	uartIBRD = (int)(CLDIV);
	uartFBRD = (int)((CLDIV - uartIBRD) * 64 + 0.5);
	SET_BIT(SYSCTL_RCGCUART_R,7);
	while((SYSCTL_PRUART_R&(0x80))==0){}
	SET_BIT(SYSCTL_RCGCGPIO_R,4);
	while((SYSCTL_PRGPIO_R & (0x01<<4)) == 0) {}
	CLEAR_BIT(UART7_CTL_R,0);
	UART7_IBRD_R = uartIBRD;
	UART7_FBRD_R = uartFBRD;
	UART7_LCRH_R |= 0x70;
	UART7_CTL_R |= 0x301;
	GPIO_PORTE_DEN_R |= 0x03;
	GPIO_PORTE_AMSEL_R &= ~0x03;
	GPIO_PORTE_AFSEL_R |= 0x03;
	GPIO_PORTE_PCTL_R |= 0x00000011;
}
void UART7_CharTX( unsigned char ch){
 while((UART7_FR_R&0x02) != 0){}
	 UART7_DR_R = ch; 
}
unsigned char UART7_CharRX(){
 while((UART7_FR_R&0x10) != 0){}
return UART7_DR_R&0xFF;
}
void UART7_StringTX(char *str){
 while(*str!='\0'){
   UART7_CharTX(*str );
    str++;
       
			 }
}
void UART7_StringRX(char *str, char stopCh){
	char c = UART7_CharRX();
	while( c != stopCh){
		*str = c;
		str++;
		c = UART7_CharRX();
	}
	*str = 0x00;
}
