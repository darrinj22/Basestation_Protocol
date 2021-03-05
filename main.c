#include  "functions.h"
#include  "msp430.h"
#include "macros.h"
// other variables 
char message[] = "Jon Mark " ; 
int location = 0; 

//timers 
extern volatile unsigned int Time_Sequence;
extern int wait2send; 

//flags 
extern int sendData = 1;
extern int start = 0; 
extern unsigned int transmit = 0; 
void main(void){
Init_All(); 

  while(ALWAYS) {  
    switch(sendData){
    case 1: 
      while(message[location] != '\0'){
        switch(transmit){
        case 0: 
        UCA1TXBUF = message[location];
        transmit = 1; 
        start = 1; 
        break; 
        case 1: 
          delay(0,&wait2send,&start,0);
          if(start == 0){
            transmit = 0;
            location++;
          }
          break; 
        default:
          break; 
        }
      }
     location = 0; 
     sendData = 2; 
    //toggleLEDs();
     break; 
    case 2: 
      delay(0,&wait2send,&sendData,4); 
      break; 
    default: 
      break; 
    }
  }
}


  






