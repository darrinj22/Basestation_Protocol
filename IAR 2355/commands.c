#include  "functions.h"
#include  "msp430.h"
#include "macros.h"

float TARI = 12.5; 
float RTcal = 31.25; 
float TRcal = 34.5;
float PW = 6; 

void preamble(float T,float RT,float TR,float P){
  
  
}

/*
// 
// Select command: 
// Arguments: 4-bit command 
void Select(int Target, int Action, int MemBank, int Truncate, int CRC_16){
  float command = Select_cmd;
  
  
  
}

// challenge command
// Arguments: 2-bit RFU value (should be 00, if not then tag returns to ready)
// 1- bit IncRepLen value (whether tags reply should include length y:1 n:0)
// 1-bit Immed value: (whether tag should concatenate 
void Challenge(int RFU, int IncRepLen, int Immed, int CSI, int length, int message, int CRC_16){
  int command = Challenge_cmd; 
  
  
  
}
*/

// QueryAdjust command
// Arguments: session and UpDn
// Session: confirms the session number for the inventory round given by Query 
// UpDn: Determines how the value Q is adjusted, Q is the # of slots in an inventory round 
int QueryAdjust(int session, int UpDn){
int command = QueryAdjust_cmd; 
command = command << 2; 
command |= session;
command = command << 3; 
command |= UpDn; 
return command;   
}



// QueryRep command 
// Arguments: session
// session: same as QueryAdjust
int QueryRep(int session){
int command = QueryRep_cmd; 
command = command << 2; 
command |= session;
return command; 
}
