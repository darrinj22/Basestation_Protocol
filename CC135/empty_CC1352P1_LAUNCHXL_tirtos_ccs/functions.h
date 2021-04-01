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
void transmit(void);
void timerCallback(Timer_Handle myHandle, int_fast16_t status);
void upDown(void);

//preamble and frame sync
void preamble(void);
void preamble_callback(Timer_Handle Timer0, int_fast16_t status);
void frameSync(void);
void frameSync_callback(Timer_Handle Timer0, int_fast16_t status);

#endif /* FUNCTIONS_H_ */
