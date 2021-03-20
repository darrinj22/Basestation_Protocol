/**
 * @file       pin-assign.h
 *
 * This file specifies pin assignments for the particular hardware platform used.
 *  currently this file targets the WISP5-LRG platform.
 *
 * @author     Aaron Parks, Justin Reina, UW Sensor Systems Lab
 *
 * @todo       The pin definitions in this file are incomplete! Use script to autogenerate these.
 *
 */

#ifndef PIN_ASSIGN_H_
#define PIN_ASSIGN_H_
#include "wispGuts.h"

/** @section    IO CONFIGURATION
 *  @brief      This represents the default IO configuration for the WISP 5.0 rev 0.1 hardware
 *  @details    Pay very close attention to your IO direction and connections if you are modifying any of this!
 *
 *  @note   PIN_TX Must be BIT7 of a port register, as the register is used as a mini-FIFO in the transmit operation. BIT0 may also be
 *          used with some modification of the transmit routine. Do NOT attempt to use other pins on PTXOUT as outputs.
 */
/************************************************************************************************************************************/

/*
 * Port 1
 */

// P1.0 - LED2
#define     PIN_LED2                (BIT0)
#define     PDIR_LED2               (P1DIR)
#define     PLED2OUT                (P1DIR)

// P1.2 - TRANSMIT - OUTPUT
#define     PIN_TX                  (BIT2)
#define     PTXOUT                  (P1OUT)
#define     PTXDIR                  (P1DIR)

// P1.3 - AUX1 -  INPUT/OUTPUT
#define     PIN_AUX1                (BIT3)
#define     PAUX1IN                 (P1IN)
#define     PDIR_AUX1               (P1DIR)
#define     PAUX1SEL0               (P1SEL0)
#define     PAUX1SEL1               (P1SEL1)

// P1.4 - AUX2 -  INPUT/OUTPUT
#define     PIN_AUX2                (BIT4)
#define     PAUX2IN                 (P1IN)
#define     PDIR_AUX2               (P1DIR)
#define     PAUX2SEL0               (P1SEL0)
#define     PAUX2SEL1               (P1SEL1)

// P1.5 - AUX3 -  INPUT/OUTPUT
#define		PIN_AUX3			    (BIT5)
#define 	PIN_AUX3_OUT		    (P1OUT)
#define 	PAUX3IN				    (P1IN)
#define 	PDIR_AUX3			    (P1DIR)
#define		PAUX3SEL0			    (P1SEL0)
#define		PAUX3SEL1			    (P1SEL1)

/*// P1.6 - ACCEL_MOSI - OUTPUT
#define     PIN_ACCEL_MOSI          (BIT6)
#define     PDIR_ACCEL_MOSI         (PRX_DIR)
#define     PACCEL_MOSISEL0         (P1SEL0)
#define     PACCEL_MOSISEL1         (P1SEL1)

// P1.7 - ACCEL_MISO - INPUT
#define     PIN_ACCEL_MISO          (BIT7)
#define     PDIR_ACCEL_MISO         (PRX_DIR)
#define     PACCEL_MISOSEL0         (P1SEL0)
#define     PACCEL_MISOSEL1         (P1SEL1)*/

/*
 * Port 2
 */

// P2.2 - DEBUG LINE - OUTPUT
#define     PIN_DBG0                (BIT2)
#define     PDBGOUT                 (P2OUT)

/*// P2.2 - ACCEL_SCLK - OUTPUT
#define     PIN_ACCEL_SCLK          (BIT2)
#define     PDIR_ACCEL_SCLK         (PRX_DIR)
#define     PACCEL_SCLKSEL0         (P2SEL0)
#define     PACCEL_SCLKSEL1         (P2SEL1)*/

// P2.4 MEAS INPUT
#define     PIN_MEAS                (BIT4)
#define     PMEASOUT                (P2OUT)
#define     PMEASDIR                (PMEAS_ACCEL_DIR)
#define     PMEASSEL0               (P2SEL0)
#define     PMEASSEL1               (P2SEL1)

// P2.5 - UART TX - OUTPUT
#define		PIN_UART_TX			    (BIT5)
#define		PUART_TXSEL0		    (P2SEL0)
#define		PUART_TXSEL1		    (P2SEL1)

// P2.6 - UART RX - INPUT
#define		PIN_UART_RX			    (BIT6)
#define		PUART_RXSEL0		    (P2SEL0)
#define		PUART_RXSEL1		    (P2SEL1)

/*
 * Port 3
 */

// P3.0 - RECEIVE - INPUT
#define     PIN_RX                  (BIT0)
#define     PRXIN                   (P3IN)
#define     PDIR_RX                 (PRX_DIR)
#define     PRXIES                  (P3IES)
#define     PRXIE                   (P3IE)
#define     PRXIFG                  (P3IFG)
#define     PRXSEL0                 (P3SEL0)
#define     PRXSEL1                 (P3SEL1)
#define     PRX_VECTOR_DEF          (PORT3_VECTOR)

// P3.4 - RECEIVE ENABLE - OUTPUT
#define     PIN_RX_EN               (BIT4)
#define     PRXEOUT                 (P3OUT)
#define     PDIR_RX_EN              (P3DIR)

// P3.5 - I2C_SCL -  INPUT/OUTPUT
#define     PIN_I2C_SCL             (BIT5)
#define     PDIR_I2C_SCL            (P3DIR)
#define     PI2C_SCLSEL0            (P3SEL0)
#define     PI2C_SCLSEL1            (P3SEL1)

// P3.6 - I2C_SDA -  INPUT/OUTPUT
#define     PIN_I2C_SDA             (BIT6)
#define     PI2C_SDAIN              (P3IN)
#define     PDIR_I2C_SDA            (P3DIR)
#define     PI2C_SDASEL0            (P3SEL0)
#define     PI2C_SDASEL1            (P3SEL1)

/*
 * Port 4
 */

// P4.2 - RX_BITLINE INPUT
#define     PIN_RX_BITLINE          (BIT2)
#define     PRX_BITLINEOUT          (P4OUT)
#define     PDIR_RXBIT              (PRXB_DIR)

// P4.3 MEAS_EN (OUTPUT)
#define     PIN_MEAS_EN             (BIT3)
#define     PMEAS_ENOUT             (P4OUT)
#define     PMEAS_ENDIR             (P4DIR)

// P4.6 - LED1 OUTPUT
#define     PIN_LED1                (BIT6)
#define		PLED1OUT			    (P4OUT)
#define 	PDIR_LED1			    (LED_DIR)

/*
 * Port 5
 */

/*
 * Port 6
 */

/*
 * Port J
 */

/*
 *  Unused on MSP430
 */

/*// P4.2 - ACCEL_EN - OUTPUT
#define     PIN_ACCEL_EN            (BIT2)
#define     POUT_ACCEL_EN           (P4OUT)
#define     PDIR_ACCEL_EN           (PMEAS_ACCEL_DIR)

// P4.3 - ACCEL_CS - OUTPUT
#define     PIN_ACCEL_CS            (BIT3)
#define     POUT_ACCEL_CS           (P4OUT)
#define     PDIR_ACCEL_CS           (P4DIR)*/

/*// P3.6 - ACCEL_INT2 - INPUT
#define     PIN_ACCEL_INT2          (BIT6)
#define     PDIR_ACCEL_INT2         (AUX_DIR)
#define     PACCEL_INT2SEL0         (P3SEL0)
#define     PACCEL_INT2SEL1         (P3SEL1)

// P3.7 - ACCEL_INT1 - INPUT
#define     PIN_ACCEL_INT1          (BIT7)
#define     PDIR_ACCEL_INT1         (AUX_DIR)
#define     PACCEL_INT1SEL0         (P3SEL0)
#define     PACCEL_INT1SEL1         (P3SEL1)
*/

/*
 * ADC Channel definitions
 */

/**
 * Default IO setup
 */
/** @todo: Default for unused pins should be output, not tristate.  */
/** @todo:  Make sure the Tx port pin should be tristate not output and unused pin to be output*/
// Set as many as possible pins to output and drive them low
#ifndef __ASSEMBLER__
#define setupDflt_IO() \
    P1OUT = 0x00;\
    P2OUT = 0x00;\
    P3OUT = 0x00;\
    P4OUT = 0x00;\
    PJOUT = 0x00;
    P1DIR = 0xFF;
    P2DIR = 0xFF;
    P3DIR = 0xFF;
    P4DIR = 0xFF;
    PJDIR = 0xFF;
    LED_DIR = 0xFF;\
    PRXB_DIR = ~PIN_RX_BITLINE;
    PRX_DIR = ~PIN_RX;\
    PMEAS_ACCEL_DIR = (~PIN_MEAS & ~PIN_ACCEL_EN);\

#endif /* ~__ASSEMBLER__ */

#endif /* PIN_ASSIGN_H */
