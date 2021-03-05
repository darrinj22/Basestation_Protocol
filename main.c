#include  "functions.h"
#include  "msp430.h"
#include "macros.h"
#include <string.h>
// other variables 
char message[] = "Confirmed Received Message: " ; 
extern int location = 0; 
extern char holding[32];
char waiting[] = "Waiting for Response... " ; 

//timers 
extern volatile unsigned short int Time_Sequence;
extern unsigned short int wait2send; 

//flags 
extern unsigned short int sendData = 1;
extern unsigned short int start; 
extern unsigned short int transmit; 
extern unsigned short int msgReceived;
extern unsigned short int y; 
extern int x; 

void main(void){
Init_All(); 

  while(ALWAYS) {  
    switch(sendData){
    case 1: 
      if(y){
        tx(message); 
        tx(holding);
         y = 0; 
      }else{
        tx(waiting); 
    }
     break; 
    case 2: 
      delay(0,&wait2send,&sendData,3); 
      break; 
    case 3: 
      rx(); 
      break; 
    default: 
      break; 
    }
  }
  
  
}


  






