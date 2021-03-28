/*
 * includes.h
 *
 *  Created on: Mar 27, 2021
 *      Author: DJ Hansen & Jon Mark Long
 */

#ifndef INCLUDES_H_
#define INCLUDES_H_

#include "functions.h"
// empty.c
/* For usleep() */
#include <unistd.h>
#include <stdint.h>
#include <stddef.h>

/* Driver Header files */
#include <ti/drivers/GPIO.h>
// #include <ti/drivers/I2C.h>
// #include <ti/drivers/SPI.h>
// #include <ti/drivers/UART.h>
// #include <ti/drivers/Watchdog.h>
#include <ti/drivers/Timer.h>

/* Driver configuration */
#include "ti_drivers_config.h"
#include <ti/display/Display.h>

// main_rtos.c
#include <stdint.h>

/* POSIX Header files */
#include <pthread.h>

/* RTOS header files */
#include <ti/sysbios/BIOS.h>

#include <ti/drivers/Board.h>
#endif /* INCLUDES_H_ */
