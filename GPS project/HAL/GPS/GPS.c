
#include "GPS.h"
const double EARTHRADIUS = 6371000;
const double PI=3.14159265358979323846;
//int main(){}

	//###### HOW TO BE CALLED ######
	// CALL readGPSDouble AND GIVE IT TWO POINTERS TO SAVE IN THESE LOCATIONS THE FLOAT VALUE OF THE TWO LAT AND LOG
	// CALL CALC DISTANCE AFTER  making sure that the given log and lat are suitable
	
	
	

	
//=================================================================================

//readGPS is  a function for getting longitude and latitude and storing them as character arrays;

 int readGPS(char * lat, char * log){

//$GPRMC,200751.00,A,4047.32510,N,02929.63031,E,9.879,105.80,301117,,,A*6C


    char c;

    c = UART_CharRX(0);
    if (c == '$'){
       c = UART_CharRX(0);
       if (c == 'G'){
          c = UART_CharRX(0);
          if (c == 'P'){
             c = UART_CharRX(0);
             if (c == 'R'){
                c = UART_CharRX(0);
                if (c == 'M'){
                   c = UART_CharRX(0);
                   if (c == 'C'){
                      c = UART_CharRX(0);
                      if (c == ','){


                 //================================
                 //ignoring time and other characters till latitude characters:
                       do{
                                c = UART_CharRX(0);    //#######this will recieve ',' before it exits the loop???

                         }while(c != ',');             //#######IT CAN GO INTO A LOOP IF THE DATA WAS INVALID AND IT NEVER SENT 'A'
                                                       //#######INCASE OF INVALID NEEDS TO RETURN -1 
                 //storing data of latitude:
                       c = UART_CharRX(0);
                       if(c == 'A') {
											c = UART_CharRX(0);
                       UART_StringRX(0 , lat , ',');}
											 else return -1;

                 //================================

                 //ignoring time and other characters till longitude characters:
                       do{
                                c = UART_CharRX(0);

                         }while(c != 'N'   ||   c != 'S');

                 //================================

                 //storing data of longitude:
                       c = UART_CharRX(0);
                       if(c == ',')
                       UART_StringRX(0 , log , ',');
                 //================================
											 return 0;

                                   }
                                }
                             }
                          }
                       }
                    }
                 }
  return 1;

}


//================================================================================

//floatVal is a function for converting the string value of a character array to a double value

//char chara[11] = "6094.20986"; //el values de tosta3ml fel 7esabat bs , 3shan law awel rakam 0 msh haib2a lih e3tbar

//double floatVal(char *c , int latOrlog){
//    int number , i = 0;
//    int j=3 ; // if latOrlog = 0 ---> lat and so 10 power 3 is the highest power , if latOrlog = 1 --> log and so 10 power 4 is the highest power

//    if (latOrlog == 1) j = 4;

//    double valueOflog_lat = 0.0f; //value of latitude or longitude in numbers


//    while( j > -6){

//    if(c[i] == '.')
//       {
//           i++;
//           continue;
//       }

//    number = c[i] - 48;


//    valueOflog_lat += number*(pow(10 , j));


//    j--;

//    i++;

//    }

//    return valueOflog_lat;

//}

//===========================================================================================================
//floatVal V2

double floatVal(char *c){
    char holder[10]; //215.34
    double result = 0;
    int i = 0;
    int p = 0;
		int j;
    while(*c){if(*c == '.'){p = i;c++;continue;}holder[i] = *c;i++;c++;}
    holder[i] = '\0';
    for(j = 0;j < i;j++){result += (int)(holder[i-j-1] - '0') * pow(10,j);}
    p = i - p;
    result /= pow(10,p);
    return result;
}
//===========================================================================================================

double degToRad(double deg) { return deg* ( PI /180);}

double convertCoords(char * old){
	double x;
	x = floatVal(old);
	x = (int)(x / 100) + ((x - ((int)(x / 100) * 100))/ 60); ////now all the coordinates are in degrees ad not degrees and minutes
	return x;
}

//===========================================================================================================


//calcDistance is a function for calculating distance between two points using latitudes and longitudes
double calcDistance(volatile double latitude_1, volatile double logitude_1, volatile double latitude_2, volatile double logitude_2){
volatile double phi1, phi2, delta_phi, delta_lmbda, a, b, c, d;
	phi1 = degToRad(latitude_1);
	phi2 = degToRad(latitude_2);
  delta_phi = phi2-phi1;
  delta_lmbda = logitude_2-logitude_1;
  delta_lmbda = degToRad(delta_lmbda);

   a = (sin(delta_phi/2) * sin(delta_phi/2)) + 
       (cos(phi1) * cos(phi2)) *
       (sin(delta_lmbda/2) * sin(delta_lmbda/2)) ;
   c = 2 * atan2(sqrt(a),sqrt(1-a));
   d = EARTHRADIUS * c;
	return d;
	



}
 //return distance;


//===========================================================================================================

void readGPSDouble(volatile double * dlat,volatile double * dlog){
	char lat[15]={0};
	char log[15]={0};
	readGPS(lat,log);
	while(!lat[0]){readGPS(lat,log);}
	*dlat = convertCoords(lat);
	*dlog = convertCoords(log);
}
