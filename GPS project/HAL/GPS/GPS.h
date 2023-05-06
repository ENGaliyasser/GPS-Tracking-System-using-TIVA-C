#ifndef GPS_H_INCLUDED
#define GPS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "../../MCAL/UART/UART.h"
#include <math.h>

int readGPS(char * lat, char * log);   ///if it returns 0 then its working and 1 means didnt find gprmc and -1 means invalid data

double calcDistance(volatile double latitude_1, volatile double logitude_1, volatile double latitude_2, volatile double logitude_2);


//double floatVal(char *c , int latOrlog);

double floatVal(char *c);

double convertCoords(char * old);

double degToRad(double deg);

double calcDistance(volatile double latitude_1, volatile double logitude_1, volatile double latitude_2, volatile double logitude_2);


void readGPSDouble(volatile double * dlat,volatile double * dlog);


#endif // GPS_H_INCLUDED
