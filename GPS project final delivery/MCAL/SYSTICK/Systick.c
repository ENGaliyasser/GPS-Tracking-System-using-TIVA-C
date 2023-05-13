#include "Systick.h"
void delay_s(void){

    NVIC_ST_CTRL_R = 0; // disable SysTick during setup
    NVIC_ST_RELOAD_R = 16000000 - 1;
    NVIC_ST_CURRENT_R = 0; //clear current register and COUNTFLAG
    NVIC_ST_CTRL_R = 0x05; 
    while((NVIC_ST_CTRL_R&0x10000) == 0);
 
}

void wait_s(uint32_t num){
    unsigned long k;
	for(k = 0; k < num; k++){
		
	}
}

void delay_ms(void){
    NVIC_ST_CTRL_R = 0;
    NVIC_ST_RELOAD_R = 16000-1; //1 msec.
    NVIC_ST_CURRENT_R = 0; //clear current register and COUNTFLAG
    NVIC_ST_CTRL_R = 5; //enable and clock source 101 = 5
    while((NVIC_ST_CTRL_R & 0x10000) == 0){}
}

void wait_ms(uint32_t num){
    unsigned long k;
	for(k = 0; k < num; k++){
		delay_ms();
	}
}
