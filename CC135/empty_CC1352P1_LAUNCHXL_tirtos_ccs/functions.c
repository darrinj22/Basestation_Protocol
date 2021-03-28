/*
 * functions.c
 *
 *  Created on: Mar 27, 2021
 *      Author: DJ Hansen & Jon Mark Long
 */


#include "includes.h"


/*
 *  tx:
 *  arguments:
 *  cmd[]: array that contains specific cmd string to be transmitted
 *  size: size of array
 */
uint32_t waitBetween = 1;
uint32_t count = 0;
void tx(unsigned int cmd[], uint8_t size){
    uint16_t it = 0;
        while(it < size){
           GPIO_write(GPIO_TX,cmd[it++]);
           sleep(waitBetween);
        }
}


