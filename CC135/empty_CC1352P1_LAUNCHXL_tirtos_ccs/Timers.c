#define jonMark (0)
#define working (1)
#if working
#include "ti_drivers_config.h"
#include <ti/drivers/Timer.h>
#include <ti/drivers/GPIO.h>
#include "functions.h"
#include "macros.h"

Timer_Handle Timer0;
Timer_Params params;
uint8_t state = 0;
uint8_t pwState = 0;
int_fast16_t status;
void frameSync(void){
    Timer_Params_init(&params);
    params.periodUnits = Timer_PERIOD_US;
    params.period = 1000;
    params.timerMode  = Timer_CONTINUOUS_CALLBACK;
    params.timerCallback = frameSync_callback;

    Timer0 = Timer_open(TIMER_0, &params);
    if (Timer0 == NULL) {
      //Timer_open() failed
     while (1);}

    status = Timer_start(Timer0);

}
void frameSync_callback(Timer_Handle Timer0, int_fast16_t status){
    //GPIO_toggle(GPIO_TX);

    switch(state){
    case DE:
        Timer_stop(Timer0);
        Timer_setPeriod(Timer0,Timer_PERIOD_US,1250);
        Timer_start(Timer0);
        //GPIO_toggle(GPIO_TX);
        GPIO_write(GPIO_TX,0);
        state = TA;
        break;
    case TA:
       Timer_stop(Timer0);
       Timer_setPeriod(Timer0,Timer_PERIOD_US,1000);
       Timer_start(Timer0);
       //GPIO_toggle(GPIO_TX);
       GPIO_write(GPIO_TX,1);
       state = PW;
        break;
    case PW:
           Timer_stop(Timer0);
           Timer_setPeriod(Timer0,Timer_PERIOD_US,500);
           Timer_start(Timer0);
           //GPIO_toggle(GPIO_TX);
           GPIO_write(GPIO_TX,0);
           switch(pwState){
           case 0:
               state = RT;
               pwState++;
               break;
           case 1:
               state = END;
               pwState--;
               break;
           default:
               break;
           }
            break;
    case RT:
           Timer_stop(Timer0);
           Timer_setPeriod(Timer0,Timer_PERIOD_US,2500);
           Timer_start(Timer0);
           //GPIO_toggle(GPIO_TX);
           GPIO_write(GPIO_TX,1);
           state = PW;
            break;
    case END:
            GPIO_write(GPIO_TX,1);
            Timer_stop(Timer0);
            Timer_close(Timer0);
            state = DE;
        break;
    default:
        break;
    }
}

void preamble(void){
    Timer_Params_init(&params);
    params.periodUnits = Timer_PERIOD_US;
    params.period = 1000;
    params.timerMode  = Timer_CONTINUOUS_CALLBACK;
    params.timerCallback = preamble_callback;

    Timer0 = Timer_open(TIMER_0, &params);
    if (Timer0 == NULL) {
      // Timer_open() failed
      while (1);}

    status = Timer_start(Timer0);

    // preamble(Timer0, status);
}

void preamble_callback(Timer_Handle Timer0, int_fast16_t status){
    //GPIO_toggle(GPIO_TX);

    switch(state){
    case DE:
        Timer_stop(Timer0);
        Timer_setPeriod(Timer0,Timer_PERIOD_US,1250);
        Timer_start(Timer0);
        //GPIO_toggle(GPIO_TX);
        GPIO_write(GPIO_TX,0);
        state = TA;
        break;
    case TA:
       Timer_stop(Timer0);
       Timer_setPeriod(Timer0,Timer_PERIOD_US,1000);
       Timer_start(Timer0);
       //GPIO_toggle(GPIO_TX);
       GPIO_write(GPIO_TX,1);
       state = PW;
        break;
    case PW:
           Timer_stop(Timer0);
           Timer_setPeriod(Timer0,Timer_PERIOD_US,500);
           Timer_start(Timer0);
           //GPIO_toggle(GPIO_TX);
           GPIO_write(GPIO_TX,0);
           switch(pwState){
           case 0:
               state = RT;
               pwState++;
               break;
           case 1:
               state = TR;
               pwState++;
               break;
           case 2:
               state = END;
               pwState = 0;
               break;
           default:
               break;
           }
            break;
    case RT:
           Timer_stop(Timer0);
           Timer_setPeriod(Timer0,Timer_PERIOD_US,2500);
           Timer_start(Timer0);
           //GPIO_toggle(GPIO_TX);
           GPIO_write(GPIO_TX,1);
           state = PW;
            break;
    case TR:
           Timer_stop(Timer0);
           Timer_setPeriod(Timer0,Timer_PERIOD_US,2500);
           Timer_start(Timer0);
           //GPIO_toggle(GPIO_TX);
           GPIO_write(GPIO_TX,1);
           state = PW;
            break;
    case END:
            GPIO_write(GPIO_TX,1);
            Timer_stop(Timer0);
            Timer_close(Timer0);
            state = DE;
        break;
    default:
        break;
    }
}


#endif

#if jonMark
#include "ti_drivers_config.h"
#include <ti/drivers/Timer.h>
#include <ti/drivers/GPIO.h>
#include "functions.h"
#include "macros.h"

uint16_t state = DE;
Timer_Handle Timer0;
Timer_Params params;

bool flag = false;

void preamble(Timer_Handle Timer0, int_fast16_t status) {
    //GPIO_toggle(GPIO_TX);
    switch (state) {
   case DE:


      status = Timer_start(Timer0);
      state = TA;
      GPIO_write(GPIO_TX, 0);                // Delimiter
      if (status == Timer_STATUS_ERROR) {
         //Timer_start() failed
         while (1);
      }
      Timer_stop(Timer0);
      break;
   case TA:
      status = Timer_setPeriod(Timer0, Timer_PERIOD_US, TARI_HIGH_PERIOD);
      status = Timer_start(Timer0);
      state = P1;
      GPIO_write(GPIO_TX, 1);                // Tari high
      if (status == Timer_STATUS_ERROR) {
         //Timer_start() failed
         while (1);
      }
      Timer_stop(Timer0);
      break;

   case P1:
      status = Timer_setPeriod(Timer0, Timer_PERIOD_US, PW_PERIOD);
      status = Timer_start(Timer0);
      state = RT;
      GPIO_write(GPIO_TX, 0);                // PW
      if (status == Timer_STATUS_ERROR) {
         //Timer_start() failed
         while (1);
      }
      Timer_stop(Timer0);
      break;
   case RT:
      status = Timer_setPeriod(Timer0, Timer_PERIOD_US, RTCAL_HIGH_PERIOD);
      status = Timer_start(Timer0);
      state = P2;
      GPIO_write(GPIO_TX, 1);                // RTcal high
      if (status == Timer_STATUS_ERROR) {
         //Timer_start() failed
         while (1);
      }
      Timer_stop(Timer0);
      break;

   case P2:
      status = Timer_setPeriod(Timer0, Timer_PERIOD_US, PW_PERIOD);
      status = Timer_start(Timer0);
      state = TR;
      GPIO_write(GPIO_TX, 0);                // PW
      if (status == Timer_STATUS_ERROR) {
         //Timer_start() failed
         while (1);
      }
      Timer_stop(Timer0);
      break;

   case TR:
      status = Timer_setPeriod(Timer0, Timer_PERIOD_US, TRCAL_HIGH_PERIOD);
      status = Timer_start(Timer0);
      state = P3;
      GPIO_write(GPIO_TX, 1);                // TRcal high
      if (status == Timer_STATUS_ERROR) {
         //Timer_start() failed
         while (1);
      }
      Timer_stop(Timer0);
      break;

   case P3:
      status = Timer_setPeriod(Timer0, Timer_PERIOD_US, PW_PERIOD);
      status = Timer_start(Timer0);
      state = END;
      GPIO_write(GPIO_TX, 0);                // PW
      if (status == Timer_STATUS_ERROR) {
         //Timer_start() failed
         while (1);
      }
      Timer_stop(Timer0);
      flag = true;
      break;
   default: break;
   }
}



void frameSync(Timer_Handle Timer0, int_fast16_t status) {
   switch (state) {
   case DE:
      Timer_Params_init(&params);
      params.periodUnits = Timer_PERIOD_US;
      params.period = DELIM_PERIOD;
      params.timerMode  = Timer_ONESHOT_CALLBACK;
      params.timerCallback = frameSync;

      Timer0 = Timer_open(TIMER_0, &params);
      if (Timer0 == NULL) {
         // Timer_open() failed
         while (1);
      }

      status = Timer_start(Timer0);
      state = TA;
      GPIO_write(GPIO_TX, 0);                // Delimiter
      if (status == Timer_STATUS_ERROR) {
         //Timer_start() failed
         while (1);
      }
      Timer_stop(Timer0);
      break;
   case TA:
      status = Timer_setPeriod(Timer0, Timer_PERIOD_US, TARI_HIGH_PERIOD);
      status = Timer_start(Timer0);
      state = P1;
      GPIO_write(GPIO_TX, 1);                // Tari high
      if (status == Timer_STATUS_ERROR) {
         //Timer_start() failed
         while (1);
      }
      Timer_stop(Timer0);
      break;

   case P1:
      status = Timer_setPeriod(Timer0, Timer_PERIOD_US, PW_PERIOD);
      status = Timer_start(Timer0);
      state = RT;
      GPIO_write(GPIO_TX, 0);                // PW
      if (status == Timer_STATUS_ERROR) {
         //Timer_start() failed
         while (1);
      }
      Timer_stop(Timer0);
      break;
   case RT:
      status = Timer_setPeriod(Timer0, Timer_PERIOD_US, RTCAL_HIGH_PERIOD);
      status = Timer_start(Timer0);
      state = P2;
      GPIO_write(GPIO_TX, 1);                // RTcal high
      if (status == Timer_STATUS_ERROR) {
         //Timer_start() failed
         while (1);
      }
      Timer_stop(Timer0);
      break;

   case P2:
      status = Timer_setPeriod(Timer0, Timer_PERIOD_US, PW_PERIOD);
      status = Timer_start(Timer0);
      state = DE;
      GPIO_write(GPIO_TX, 0);                // PW
      if (status == Timer_STATUS_ERROR) {
         //Timer_start() failed
         while (1);
      }
      Timer_stop(Timer0);
      break;
   default: break;
   }
}
#endif
