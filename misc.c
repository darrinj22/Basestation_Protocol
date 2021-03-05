#include  "functions.h"
#include  "msp430.h"
#include "macros.h"
#include <stdbool.h> 

// flags 
extern int sendData; 
// timers 
extern int start; 

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

void delay(int time, int *timer, int *flag,int flagVal){
  if(*timer > time){
    *flag = flagVal;
     *timer = 0; 
     start = 0; 
  }
}