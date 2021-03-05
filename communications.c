#include  "functions.h"
#include  "msp430.h"
#include "macros.h"

void Init_UCA0(int baudRate_A0){
UCA0CTLW0 = clear; // Use word register
UCA0CTLW0 |= UCSWRST; // Set Software reset enable
UCA0CTLW0 |= UCSSEL__SMCLK; // Set SMCLK as fBRCLK

if(baudRate_A0 == positive){
UCA0BRW = 0x04; // 115200 Baud
UCA0MCTLW = 0x5551 ;
}else{
  UCA0BRW = 0x11; // 460800 Baud
UCA0MCTLW = 0x4A ;
}
UCA0CTLW0 &= ~UCSWRST; // Set Software reset enable
UCA0IE |= UCRXIE; // Enable RX Interrupt 
}


void Init_UCA1(int baudRate_A1){
// int i; 

/*for(i=clear; i<SMALL_RING_SIZE; i++){
USB_Char_Rx1[i] = clear; // USB Rx Buffer
}
usb_rx_ring_wr1 = BEGINNING;
usb_rx_ring_rd1 = BEGINNING;

for(i=clear; i<LARGE_RING_SIZE; i++){ // May not use this
USB_Char_Tx1[i] = clear; // USB Tx Buffer
}
usb_tx_ring_wr1 = BEGINNING;
usb_tx_ring_rd1 = BEGINNING;*/
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


#pragma vector=EUSCI_A0_VECTOR
__interrupt void eUSCI_A0_ISR(void){
//unsigned int temp;
//unsigned int tempRead; 
switch(__even_in_range(UCA0IV,8)){
case 0: // Vector 0 - no interrupt
break;
case 2: // Vector 2 – RXIFG
/*temp = usb_rx_ring_wr++;

USB_Char_Rx[temp] = UCA0RXBUF; // RX -> USB_Char_Rx character
if (usb_rx_ring_wr >= (sizeof(USB_Char_Rx))){
usb_rx_ring_wr = BEGINNING; // Circular buffer back to beginning
}

if(USB_Char_Rx[temp] == carriageReturn)
  gotMessage = msgr; 
*/
break;
case 4: 
  break;
default: break; 
}
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
#pragma vector=EUSCI_A1_VECTOR
__interrupt void eUSCI_A1_ISR(void){
//unsigned int temp1;
switch(__even_in_range(UCA1IV,8)){
case 0: // Vector 0 - no interrupt
break;
case 2: // Vector 2 – RXIFG
/*temp1 = usb_rx_ring_wr1++;
USB_Char_Rx1[temp1] = UCA1RXBUF; // RX -> USB_Char_Rx character

if (usb_rx_ring_wr1 >= (sizeof(USB_Char_Rx1))){
usb_rx_ring_wr1 = BEGINNING; // Circular buffer back to beginning
}

if(USB_Char_Rx1[temp1] == carriageReturn)
  gotMessage = msgr; 
*/
break;
case 4:

break;
default: break; 

}
}