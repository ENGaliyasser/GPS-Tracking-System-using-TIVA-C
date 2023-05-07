#include "APP.h"
void SystemInit(){}
int main() {
UART_Init( 1 , 9600 );

//void UART_CharTX(char num , unsigned char ch);
//unsigned char UART_CharRX(char num );
//void UART_StringTX(char num ,char *str);
//void UART_StringRX(char num ,char *str, char stopCh);
	while(1){
		UART_CharTX(1 , 'a');
		
	}
		

}