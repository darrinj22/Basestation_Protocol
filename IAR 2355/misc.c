#include  "functions.h"
#include  "msp430.h"
#include "macros.h"
#include <stdbool.h> 

// flags 
extern unsigned short int sendData; 
// timers 
extern unsigned short int start; 
// buffers
 char binNum[32]; 
 
void toggleLEDs(){
if(withinRange(0,50)){
P1OUT |= RED_LED;
P6OUT &= ~GRN_LED; 
}
if(withinRange(50,100)){
  P1OUT &= ~RED_LED;
  P6OUT |= GRN_LED; 
}
if(withinRange(100,150)){
  P1OUT |= RED_LED;
P6OUT &= ~GRN_LED; 
}
if(withinRange(150,200)){
  P1OUT &= ~RED_LED;
  P6OUT |= GRN_LED; 
}
}

void delay(unsigned int time, unsigned short int*timer, unsigned short int *flag, unsigned int flagVal){
  if(*timer > time){
    *flag = flagVal;
     *timer = 0; 
     start = 0; 
  }
}

char * convert(int x) {
        int z = x; 
	int i = 0; 
	while (z > 0) {
		binNum[i] = z % 2;
                binNum[i] = binNum[i] + '0'; 
		z = z / 2; 
		
		i++; 
	}
        binNum[i+1] = '\0'; 
        
        return binNum; 
}