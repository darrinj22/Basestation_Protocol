//Test
//MACROS FROM main.c============================================================
#define ALWAYS                  (1)
#define RESET_STATE             (0)
#define RED_LED              (0x01) // RED LED 0
#define GRN_LED              (0x40) // GREEN LED 1


// MACROS FROM clocks.c=========================================================
#define MCLK_FREQ_MHZ 8                     // MCLK = 8MHz
#define CLEAR_REGISTER     (0X0000)


// Port 1 Pins==================================================================
#define RED_LED (0x01) // 0 RED LED 0
#define A1_SEEED (0x02) // 1 A1_SEEED
#define V_DETECT_L (0x04) // 2 V_DETECT_L
#define V_DETECT_R (0x08) // 3 V_DETECT_R
#define A4_SEEED (0x10) // 4 A4_SEEED
#define V_THUMB (0x20) // 5 V_THUMB
#define UCA0RXD (0x40) // 6 Back Channel UCA0RXD
#define UCA0TXD (0x80) // 7 Back Channel UCA0TXD


// Port 2 Pins==================================================================
#define P2_0 (0x01) // 0
#define P2_1 (0x02) // 1
#define P2_2 (0x04) // 2
#define SW2 (0x08) // 3 SW2
#define P2_4 (0x10) // 4
#define P2_5 (0x20) // 5
#define LFXOUT (0x40) // XOUTR
#define LFXIN (0x80) // XINR

// Port 3 Pins==================================================================
#define TEST_PROBE (0x01) // 0 TEST PROBE
#define CHECK_BAT (0x02) // 1 CHECK_BAT
#define OA2N (0x04) // 2 Photodiode Circuit
#define OA2P (0x08) // 3 Photodiode Circuit
#define SMCLK_OUT (0x10) // 4 SMCLK
#define IR_LED (0x20) // 5 IR_LED
#define IOT_LINK (0x40) // 6 IOT_LINK
#define P3_7 (0x80) // 7 P3_7

// Port 4 Pins==================================================================
#define RESET_LCD (0x01) // 0 LCD Reset
#define SW1 (0x02) // 1 SW1
#define UCA1RXD (0x04) // 2 Back Channel UCA1RXD
#define UCA1TXD (0x08) // 3 Back Channel UCA1TXD
#define UCB1_CS_LCD (0x10) // 4 Chip Select
#define UCB1CLK (0x20) // 5 SPI mode - clock output—UCB1CLK
#define UCB1SIMO (0x40) // 6 UCB1SIMO
#define UCB1SOMI (0x80) // 7 UCB1SOMI

// Port 5 Pins==================================================================
#define IOT_RESET (0x01) // 
#define V_BAT (0x02) // 
#define IOT_PROGRAM_SELECT (0x04) // 
#define V_33 (0x08) //
#define IOT_PROGRAM_MODE (0x10) // 

// Port 6 Pins =================================================================
#define R_FORWARD (0x01) // 
#define L_FORWARD (0x02) // 
#define R_REVERSE (0x04) // 
#define L_REVERSE (0x08) // 
#define LCD_BACKLITE (0x10) // 
#define P6_5 (0x20) // 
#define GRN_LED (0x40) // 

// Default Settings ============================================================
#define def_out (0xFF) // default pin to out 
#define def_low (0x00) // default pin to low 



// main macros =================================================================
#define positive (0x01) //
#define clear 0
// ports macros 
#define USE_GPIO (0x00)
#define USE_SMCLK (0x01)

// timers macros 
#define TB0CCR0_INTERVAL 25000
#define TB0CCR1_INTERVAL 25000
#define TB0CCR2_INTERVAL 25000 



