/////////////UART_INITIALIZATION(ENTER UART PIN NUMBER FROM 0 TO 7)////
void UART_Init(char num , unsigned long  baudrate , unsigned long clock);


/////////////UARTCHAR_TRANSMIT(ENTER UART PIN NUMBER FROM 0 TO 7)/////
void UART_TRANSMITChar(char num , unsigned char ch);


/////////////UARTCHAR_RECIEVE(ENTER UART PIN NUMBER FROM 0 TO 7)/////
unsigned char UART_RECEIVEChar(char num );


/////////////UARTSTRING_TRANSMIT(ENTER UART PIN NUMBER FROM 0 TO 7)/////
void UART_TRANSMITString(char num ,char *str);


/////////////UARTSTRING_RECEIVE(ENTER UART PIN NUMBER FROM 0 TO 7)/////
void UART_RECEIVEString(char num ,char *str, char stopCh);
