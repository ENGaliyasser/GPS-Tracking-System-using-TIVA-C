#include "stdint.h"
#ifndef UART_H_
#include "../../Utilities/tm4c123gh6pm.h"
#include "../../Utilities/bitManipulation.h" //startup_TM4C123.s
/////////////UART_INITIALIZATION(ENTER UART PIN NUMBER FROM 0 TO 7)////
void UART_Init(char num , unsigned long  baudrate );


/////////////UARTCHAR_TRANSMIT(ENTER UART PIN NUMBER FROM 0 TO 7)/////
void UART_CharTX(char num , unsigned char ch);


/////////////UARTCHAR_RECIEVE(ENTER UART PIN NUMBER FROM 0 TO 7)/////
unsigned char UART_CharRX(char num );


/////////////UARTSTRING_TRANSMIT(ENTER UART PIN NUMBER FROM 0 TO 7)/////
void UART_StringTX(char num ,char *str);


/////////////UARTSTRING_RECEIVE(ENTER UART PIN NUMBER FROM 0 TO 7)/////
void UART_StringRX(char num ,char *str, char stopCh);

#endif /* UART_H_ */
