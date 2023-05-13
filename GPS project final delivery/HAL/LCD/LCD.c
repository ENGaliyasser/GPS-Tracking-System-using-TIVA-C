#include "LCD.h"
// if u want to use 8 bit mode replace with this
//init
//        GPIO_PORTB_DIR_R = 0xFF;                        //Configure the data port as output port
//        LCD_sendCommand(TWO_LINE_LCD_Eight_BIT_MODE);   //use 2-line lcd + 8-bit Data Mode + 5*7 dot display Mode
//				LCD_sendCommand(CURSOR_OFF);                        //cursor off
//				LCD_sendCommand(CLEAR_COMMAND); 
//data
//				GPIO_PORTB_DATA_R = data;   /* out the required command to the data bus D0 --> D7 */
//				delay_ms();                 /* delay for processing Tdsw = 100ns */
//				GPIO_PORTE_DATA_R &= ~E;    /* disable LCD E=0 */
//				delay_ms();                 /* delay for processing Th = 13ns */
//command
//        GPIO_PORTB_DATA_R = command; /* out the required command to the data bus D0 --> D7 */
//        delay_ms();                  /* delay for processing Tdsw = 100ns */
//        GPIO_PORTE_DATA_R &= ~E;     /* disable LCD E=0 */
//        delay_ms();                  /* delay for processing Th = 13ns */


// Description : Function to Initialize PORTB for Data and PORTE for control and start initializing the LCD

void LCD_init(void){
    //port E control PE1 --> RS | PE2 --> RW | PE3 --> E
    //port B data
    SYSCTL_RCGCGPIO_R |= 0x12;              //Port D & E clock enable
    while((SYSCTL_PRGPIO_R & 0x12) == 0);   //delay until the SYSCTL is enabled
    //Control port configurations
    GPIO_PORTE_AFSEL_R &= ~(RS|RW|E);       //alternate function select
    GPIO_PORTE_PCTL_R  &= ~(RS|RW|E);       //determine the selected alternate function
    GPIO_PORTE_AMSEL_R &= ~(RS|RW|E);       // analog mode select for port E
    GPIO_PORTE_DEN_R   |= (RS|RW|E);        //digital enable
    GPIO_PORTE_DIR_R   |= (RS|RW|E);        // Configure the control pins(E,RS,RW) as output pins
    //Data port configurations
    GPIO_PORTB_AFSEL_R =0;                  //alternate function select
    GPIO_PORTB_PCTL_R  =0;                  //determine the selected alternate function
    GPIO_PORTB_AMSEL_R = 0;                 // analog mode select   for port B
    GPIO_PORTB_DEN_R = 0XFF;                //digital enable
    GPIO_PORTB_DIR_R |= 0xF0;                   //Configure the highest 4 bits of the data port as output pins
    //GPIO_PORTB_DIR_R |= 0x0F;                   //Configure the lowest 4 bits of the data port as output pins
		LCD_sendCommand(FOUR_BITS_DATA_MODE);           //initialize LCD in 4-bit mode
		LCD_sendCommand(TWO_LINE_LCD_FOUR_BIT_MODE);    //use 2-line lcd + 4-bit Data Mode + 5*7 dot display Mode
    LCD_sendCommand(CURSOR_OFF);                        //cursor off
    LCD_sendCommand(CLEAR_COMMAND);                     //clear LCD at the beginning
}

void LCD_sendCommand(uint8_t command){
    GPIO_PORTE_DATA_R &= ~RS;       // Disable RS
    GPIO_PORTE_DATA_R &= ~RW;       // Disable RW
    delay_ms();                     // wait for 1 ms
    GPIO_PORTE_DATA_R |= E;         // Enable E
    delay_ms();                     // wait for 1 ms
    GPIO_PORTB_DATA_R = (GPIO_PORTB_DATA_R & 0x0F) | (command & 0xF0);
    //GPIO_PORTB_DATA_R = (GPIO_PORTB_DATA_R & 0xF0) | ((command & 0xF0) >> 4);
    delay_ms();                      // wait for 1 ms
    GPIO_PORTE_DATA_R &= ~E;         // Disable E
    delay_ms();                      // wait for 1 ms
    GPIO_PORTE_DATA_R |= E;          // Enable E
    delay_ms();                      // wait for 1 ms
		GPIO_PORTB_DATA_R = (GPIO_PORTB_DATA_R & 0x0F) | ((command & 0x0F) << 4);
		//GPIO_PORTB_DATA_R = (GPIO_PORTB_DATA_R & 0xF0) | (command & 0x0F);
    delay_ms();               /* delay for processing Tdsw = 100ns */
    GPIO_PORTE_DATA_R &= ~E;  /* disable LCD E=0 */
    delay_ms();               /* delay for processing Th = 13ns */
}

void LCD_clearScreen(void){
    LCD_sendCommand(CLEAR_COMMAND); //clear screen
}

void LCD_displayCharacter(uint8_t data){
    GPIO_PORTE_DATA_R |= RS;    //Data Mode RS=1
    GPIO_PORTE_DATA_R &= ~RW;   //write data to LCD so RW=0
    delay_ms();                 //delay for processing Tas = 50ns
    GPIO_PORTE_DATA_R |= E;     //Enable LCD E=1
    delay_ms();                 //delay for processing Tpw - Tdws = 190ns
    //Configure 8 bit mode or 4 bit mode
		GPIO_PORTB_DATA_R = (GPIO_PORTB_DATA_R & 0x0F) | (data & 0xF0);
		//GPIO_PORTB_DATA_R = (GPIO_PORTB_DATA_R & 0xF0) | ((data & 0xF0) >> 4);
    delay_ms();                 //delay for processing Tdsw = 100ns
    GPIO_PORTE_DATA_R &= ~E;    //disable LCD E=0
    delay_ms();                 //delay for processing Th = 13ns
    GPIO_PORTE_DATA_R |= E;     //Enable LCD E=1
    delay_ms();                 //delay for processing Tpw - Tdws = 190ns
    //out the lowest 4 bits of the required data to the data bus B4 --> B7
		GPIO_PORTB_DATA_R = (GPIO_PORTB_DATA_R & 0x0F) | ((data & 0x0F) << 4);
		//GPIO_PORTB_DATA_R = (GPIO_PORTB_DATA_R & 0xF0) | (data & 0x0F);
		delay_ms();                 /* delay for processing Tdsw = 100ns */
		GPIO_PORTE_DATA_R &= ~E;    /* disable LCD E=0 */
		delay_ms();                 /* delay for processing Th = 13ns */

}

void LCD_displayString(const char *Str){
    uint8_t i = 0;
    while(Str[i] != '\0')
    {
        LCD_displayCharacter(Str[i]);
        i++;
    }
}

void LCD_goToRowColumn(uint8_t row,uint8_t col)
{
    uint8_t Address;
    //Calculate the required address
    switch(row)
    {
        case 0:
                Address=col;
                break;
        case 1:
                Address=col+0x40;
                break;
        case 2:
                Address=col+0x10;
                break;
        case 3:
                Address=col+0x50;
                break;
    }
    //to write in a specific address in the LCD
    //we need to send the corresponding command 0b10000000 + Address
    LCD_sendCommand(Address | SET_CURSOR_LOCATION);
}

void LCD_intgerToString(double data)
{
    char buff[16];  //String to hold the ascii result
    sprintf(buff, "%f", data);
    //i_s( buff, (int)data);
    //itoa(data,buff,10);  //10 for decimal

    LCD_displayString(buff);
}
