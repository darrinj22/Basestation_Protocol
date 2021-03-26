#include "macros.h" 
#include "functions.h" 
#include "msp430.h"
#include <stdbool.h>

// timers 
volatile unsigned short int Time_Sequence = clear;
extern unsigned short int wait2send = 0;
//flags
extern unsigned short int sendData;
extern unsigned short int start;


void Init_Timer_B0(void) {
TB0CTL = TBSSEL__SMCLK; // SMCLK source
TB0CTL |= TBCLR; // Resets TB0R, clock divider, count direction
TB0CTL |= MC__CONTINOUS; // Continuous up
TB0CTL |= ID_1; // Divide clock by 2
TB0EX0 = TBIDEX_7; // Divide clock by an additional 8
TB0CCR0 = TB0CCR0_INTERVAL; // CCR0
TB0CCTL0 |= CCIE; // CCR0 enable interrupt
TB0CCR1 = TB0CCR1_INTERVAL; // CCR1
TB0CCTL1 |= CCIE; // CCR1 enable interrupt
TB0CCR2 = TB0CCR2_INTERVAL; // CCR2
TB0CCTL2 |= CCIE; // CCR2 enable interrupt
TB0CTL &= ~TBIE; // Disable Overflow Interrupt
TB0CTL &= ~TBIFG; // Clear Overflow Interrupt flag
}


bool withinRange(int x,int y){
  if(Time_Sequence > x && Time_Sequence < y){
    return true; 
  }else{return false;} 
}

// interrupt for timer B0, increments time sequence

#pragma vector = TIMER0_B0_VECTOR
__interrupt void Timer0_B0_ISR(void){
//------------------------------------------------------------------------------
// TimerB0 0 Interrupt handler
//----------------------------------------------------------------------------
 
Time_Sequence++; 

if(Time_Sequence > 200){
  Time_Sequence = clear; 
}

if(sendData == 2 || start == 1){
  wait2send++; 
}



 TB0CCR0 += TB0CCR0_INTERVAL; // Add Offset to TBCCR0 
}

//----------------------------------------------------------------------------



// interrupt for timer B0, deals with debouncing 


#pragma vector=TIMER0_B1_VECTOR
__interrupt void TIMER0_B1_ISR(void){
//----------------------------------------------------------------------------
// TimerB0 1-2, Overflow Interrupt Vector (TBIV) handler
//----------------------------------------------------------------------------
switch(__even_in_range(TB0IV,14)){
case 0: break; // No interrupt
case 2: // CCR1 not used


TB0CCR1 += TB0CCR1_INTERVAL; // Add Offset to TBCCR1
break;
case 4: // CCR2 not used

TB0CCR2 += TB0CCR2_INTERVAL; // Add Offset to TBCCR2
break;
case 14: // overflow
//...... Add What you need happen in the interrupt ......
break;
default: break;
}
}//--------

