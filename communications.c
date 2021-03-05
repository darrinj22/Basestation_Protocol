#include  "functions.h"
#include  "msp430.h"
#include "macros.h"
#include <string.h>
// general globals 
extern int location; 
char RX[32] = {'\0'}; 
extern char holding[32] = {'\0'}; 
int RX_iterator = 0 ;
int RX_location = 0 ; 

//timers 
extern volatile unsigned short int Time_Sequence;
extern unsigned short int wait2send; 

//flags 
extern unsigned short int sendData;
extern unsigned short int start = 1; 
extern unsigned short int transmit = 0; 
extern unsigned short int msgReceived = 0;
extern unsigned short int y = 0; 


// transfer message function 

void tx(char msg[]){
   while(msg[location] != '\0'){
        switch(transmit){
        case 0: 
        UCA1TXBUF = msg[location];
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
   
}

// receive message function 

void rx(void){
  if(msgReceived){
    clearRX(holding); 
        strcpy(holding,RX); 
        msgReceived = 0 ; 
      sendData = 1; 
      y = 1; 
      clearRX(RX); 
      }
  
}

void clearRX(char r[]){
  RX_location = 0 ; 
  RX_iterator = 0 ; 
    for(int i = 0 ; i < 32 ; i++){
    r[i] = '\0'; 
  }
}


void Init_UCA1(int baudRate_A1){
// Configure UART 0
 UCA1TXBUF = clear; 
UCA1CTLW0 = clear; // Use word register
UCA1CTLW0 |= UCSWRST; // Set Software reset enable
UCA1CTLW0 |= UCSSEL__SMCLK; // Set SMCLK as fBRCLK

if(baudRate_A1 == positive){
UCA1BRW = 0x04; // 115200 Baud
UCA1MCTLW = 0x5551 ;
}else{
  UCA1BRW = 0x11; // 460800 Baud
UCA1MCTLW = 0x4A ;
}

UCA1CTLW0 &= ~UCSWRST; // Set Software reset enable
UCA1IE |= UCRXIE; // Enable RX Interrupt 
}

#pragma vector=EUSCI_A1_VECTOR
__interrupt void eUSCI_A1_ISR(void){
//unsigned int temp1;
switch(__even_in_range(UCA1IV,8)){
case 0: // Vector 0 - no interrupt
break;
case 2: // Vector 2 – RXIFG
// this circle ring buffer works:   
// RX_location = RX_iterator++; 
// RX[RX_location] = UCA1RXBUF; 
// if(RX_iterator >= 32){RX_iterator = 0 ;}
  
  // this limits input to 32 chars 
  RX_location = RX_iterator++; 
  RX[RX_location] = UCA1RXBUF; 

if(UCA1RXBUF == '\n'){
  msgReceived = 1; 
} // we know the message has ended 



  // for now we can go off of a character to say the message is done, later 
  // we may want to go to time elapsed to signal that a message is done
  // i.e. 1 ms has passed since last received character so assume message is done  


break;
case 4:

break;
default: break; 

}
}