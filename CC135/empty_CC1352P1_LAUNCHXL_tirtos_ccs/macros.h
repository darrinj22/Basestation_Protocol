/*
 * macros.h
 *
 *  Created on: Mar 29, 2021
 *      Author: darri
 */

#ifndef MACROS_H_
#define MACROS_H_

// Preamble & Frame Sync macros:
//#define TARI                        ( 12.5 )
//#define DELIM_PERIOD                ( 12.5 )                    // Independent of Tari
//#define TARI_HIGH_PERIOD            ( TARI-PW_PERIOD )
//#define PW_PERIOD                   ( TARI*0.395 )
//#define RTCAL_HIGH_PERIOD           ( (TARI*2.75)-PW_PERIOD )
//#define TRCAL_HIGH_PERIOD           ( (TARI*2.05)-PW_PERIOD )

#define TARI                        ( 100 )
#define DELIM_PERIOD                ( 125 )                    // Independent of Tari
#define TARI_HIGH_PERIOD            ( 135 )
#define PW_PERIOD                   ( 145 )
#define RTCAL_HIGH_PERIOD           ( 155 )
#define TRCAL_HIGH_PERIOD           ( 165 )

// Preamble & Frame Sync states:
#define DE                          ( 0 )
#define TA                          ( 1 )
#define PW                          ( 2 )
#define RT                          ( 3 )
//#define P2                          ( 4 )
#define TR                          ( 4 )
//#define P3                          ( 6 )
#define END                         ( 5 )

#endif /* MACROS_H_ */
