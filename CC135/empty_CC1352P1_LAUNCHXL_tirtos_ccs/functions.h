/*
 * functions.h
 *
 *  Created on: Mar 27, 2021
 *      Author: darri
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
#include <stdint.h>
#include <unistd.h>
#include <stddef.h>
#include <ti/drivers/Timer.h>

void tx(unsigned int cmd[], uint8_t size);
void timer0_init(void);

void timerCallback(Timer_Handle myHandle, int_fast16_t status);
void upDown(void);
//preamble and frame sync
void preamble(void);
void frameSync(void);
void tariHigh(Timer_Handle myHandle, int_fast16_t status);
void pw(Timer_Handle myHandle, int_fast16_t status);
void pw2(Timer_Handle myHandle, int_fast16_t status);
void pw3(Timer_Handle myHandle, int_fast16_t status);
void RTcal(Timer_Handle myHandle, int_fast16_t status);
void TRcal(Timer_Handle myHandle, int_fast16_t status);

#endif /* FUNCTIONS_H_ */
