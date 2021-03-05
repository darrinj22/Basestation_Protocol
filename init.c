#include "macros.h" 
#include "functions.h"
#include "msp430.h" 


extern volatile unsigned int Time_Sequence;
extern volatile char one_time;
void Init_All(void){
PM5CTL0 &= ~LOCKLPM5;
  Init_Ports();                        // Initialize Ports
  Init_Clocks();                       // Initialize Clock System
  enable_interrupts();                   // Initialize Variables and Initial Conditions
  Init_Timer_B0();                       // Initialize Timers
  Init_UCA1(1);                         // // Initialize baudrate to 115k
}


void enable_interrupts(void){
  __bis_SR_register(GIE);
}