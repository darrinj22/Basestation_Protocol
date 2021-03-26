#include <stdbool.h>
// Initialization
void Init_Conditions(void);
void Init_All(void);
void Init_UCA0(int baudrate_A0); 
void Init_UCA1(int baudRate_A1);
// Interrupts
void enable_interrupts(void);
__interrupt void Timer0_B0_ISR(void);

// Clocks
void Init_Clocks(void);

// Ports
void Init_Ports(void);
void Init_Port1(void);
void Init_Port2(void);
void Init_Port3(int x);
void Init_Port4(void);
void Init_Port5(void);
void Init_Port6(void);

// Timers
void Init_Timers(void);
void Init_Timer_B0(void);
bool withinRange(int x,int y);

//commands
void preamble(float T,float RT,float TR,float P); 
int QueryAdjust(int session, int UpDn);
int QueryRep(int session);
//misc  
void toggleLEDs(); 
void delay(unsigned int time, unsigned short int *timer, unsigned short int *flag, unsigned int flagVal); 
char * convert(int x);

//comms 
void tx_cmd(int msg[]); 
void tx_msg(char msg[]);
void rx(void); 
void clearRX(char r[]);
