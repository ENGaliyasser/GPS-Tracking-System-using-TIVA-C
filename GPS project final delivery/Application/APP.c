#include "APP.h"
#include <math.h>
#include <stdlib.h>
void SystemInit(){}
//#include "driverlib/sysctl.h"
int main(){
char k;
char lat[20] = {0};
char log[20] = {0};	
double latitude_2=30.064069;
double logitude_2=31.279220;
double displacement;
double latDM;
double lonDMM;
double latDD;
double lonDD;
//this function is called to set the clock of the tiva to 16MHZ
//SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_INT | SYSCTL_MAIN_OSC_DIS);
UART0_Init(  9600 );	
UART5_Init(  9600 ); 
UART7_Init(  9600 ); 
LED_init();

while(1){ 
readGPS(lat,log);
latDM =ConvertToDouble(lat);
lonDMM =ConvertToDouble(log);
latDD = convertDMtoDD(latDM);
lonDD = convertDMMtoDD(lonDMM);
displacement = calculateDistance(latDD, lonDD, latitude_2, logitude_2);   
if(displacement>20)
		LED_ON('r');
else if(displacement<20 && displacement>10)
		LED_ON('y');
else
		LED_ON('g');		

    }	
}
