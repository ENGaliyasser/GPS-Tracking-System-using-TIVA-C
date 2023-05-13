#include "GPS.h"
#define RADIUS_OF_EARTH 6371000.0 // Earth's radius in meters
const double PPI=3.14159265358979323846;


	//###### HOW TO BE CALLED ######
	// CALL readGPSDouble AND GIVE IT TWO POINTERS TO SAVE IN THESE LOCATIONS THE FLOAT VALUE OF THE TWO LAT AND LOG
	// CALL CALC DISTANCE AFTER  making sure that the given log and lat are suitable
	
	

	
//=================================================================================

//readGPS is  a function for getting longitude and latitude and storing them as character arrays;

 int readGPS(char * lat, char * log){

//$GPRMC,200751.00,A,4047.32510,N,02929.63031,E,9.879,105.80,301117,,,A*6C
char c;
int i=0,j=0,result=1;

    c = UART5_CharRX();
			UART7_CharTX(c);
    if (c == '$') {
        c = UART5_CharRX();UART7_CharTX(c);
        if (c == 'G') {
            c = UART5_CharRX();UART7_CharTX(c);
            if (c == 'P') {
                c = UART5_CharRX();UART7_CharTX(c);
                if (c == 'R') {
                    c = UART5_CharRX();UART7_CharTX(c);
                    if (c == 'M') {
                        c = UART5_CharRX();UART7_CharTX(c);
                        if (c == 'C') {
                            c = UART5_CharRX();UART7_CharTX(c);
                            if (c == ',') {
                                // Ignoring time and other characters till latitude characters
															//$GPRMC,200751.00,A,4047.32510,N,02929.63031,E,9.879,105.80,301117,,,A*6C
                                do {
                                    c = UART5_CharRX();UART7_CharTX(c);
                                } while (c != ',');

                                // Storing data of latitude
                                //int i = 0;
                                c = UART5_CharRX();//A
																if(c=='A'){
																UART7_CharTX(c);
																c = UART5_CharRX();//,
																UART7_CharTX(c);
																c = UART5_CharRX();//FIRST LAT NUMBER
																UART7_CharTX(c);
                                while (c != ',') {
                                    lat[i++] = c;
                                    c = UART5_CharRX();UART7_CharTX(c);
                                }
                                lat[i] = '\0';
////$GPRMC,200751.00,A,4047.32510,N,02929.63031,E,9.879,105.80,301117,,,A*6C
                                // Ignoring N/S indicator
                                c = UART5_CharRX();
																if(c=='N'){
																UART7_CharTX(c);
																
																c = UART5_CharRX();UART7_CharTX(c);
																c = UART5_CharRX();UART7_CharTX(c);
                                // Ignoring characters till longitude characters
//                                while (c != ',') {
//                                    c = UART7_CharRX();UART7_CharTX(c);
//                                }
//                                // Storing data of longitude
//                                //int j = 0;
//                                c = UART7_CharRX();UART7_CharTX(c);
                                while (c != ',') {
                                    log[j++] = c;
                                    c = UART5_CharRX();UART7_CharTX(c);
                                }
																log[j] = '\0';
																do{
																c = UART5_CharRX();UART7_CharTX(c);
																}while(c!='*');//after * in GPRMC there are 2 more characters left to send then the message is over
																c = UART5_CharRX();UART7_CharTX(c);
																c = UART5_CharRX();UART7_CharTX(c);
																//c = UART7_CharRX();UART7_CharTX(c);
                                result = 0; // Successful extraction
																UART7_StringTX("\r\n");
																UART7_StringTX("lat:");
																UART7_StringTX(lat);
																delay_s();
																UART7_CharTX(',');
																UART7_StringTX("LOG:");
																UART7_StringTX(log);

															  }
															}
                            }
                        }
                    }
                }
            }
        }
    }
else {
        // Send error message via UART7
        char errorMsg[] = "\r\n ERROR ERROR\r\n\0";
     
				UART7_StringTX(errorMsg);
     }
	 }

double toRadians(double degrees) {
    return degrees * PPI / 180.0;
}
double ConvertToDouble(char* str) {
    double result = 0;
    int decimal = 0;
    int sign = 1;

    // Handle sign
    if (str[0] == '-') {
        sign = -1;
        str++;
    }

    // Convert integer part
    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        str++;
    }

    // Check if there is a decimal part
    if (*str == '.') {
        str++;

        // Convert decimal part
        while (*str >= '0' && *str <= '9') {
            result = result * 10 + (*str - '0');
            decimal++;
            str++;
        }
    }

    // Apply sign
    result *= sign;

    // Adjust decimal point
    while (decimal > 0) {
        result /= 10;
        decimal--;
    }

    return result;
}

double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
    double distance;

    // Convert latitude and longitude from degrees to radians
    double lat1_rad = toRadians(lat1);
    double lon1_rad = toRadians(lon1);
    double lat2_rad = toRadians(lat2);
    double lon2_rad = toRadians(lon2);

    // Haversine formula
    double dlat = lat2_rad - lat1_rad;
    double dlon = lon2_rad - lon1_rad;
    double a = sin(dlat / 2) * sin(dlat / 2) + cos(lat1_rad) * cos(lat2_rad) * sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    distance = RADIUS_OF_EARTH * c;

    return distance;
}


double convertDMtoDD(double coordinate) {
    int degrees = (int)(coordinate / 100);
    double minutes = coordinate - degrees * 100;
    double decimalDegrees = degrees + minutes / 60.0;

    return decimalDegrees;
}

double convertDMMtoDD(double coordinate) {
    int degrees = (int)(coordinate / 100);
    double minutes = coordinate - degrees * 100;
    double decimalDegrees = degrees + minutes / 60.0;

    return decimalDegrees;
}
