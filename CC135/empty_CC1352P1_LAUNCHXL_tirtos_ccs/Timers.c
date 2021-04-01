#define jonMark (0)
#define working (1)
#if working
#include "ti_drivers_config.h"
#include <ti/drivers/Timer.h>
#include <ti/drivers/GPIO.h>
#include "functions.h"
#include "macros.h"

Timer_Handle Timer0;
Timer_Params params0;
Timer_Handle Timer1;
Timer_Params params1;

uint8_t state = TA;
uint8_t pwState = 0;
int_fast16_t status;

void frameSync(void) {
    Timer_Params_init(&params0);
    params0.periodUnits = Timer_PERIOD_HZ;
    params0.period = DELIM_PERIOD;
    params0.timerMode  = Timer_ONESHOT_CALLBACK;
    params0.timerCallback = frameSync_callback;

    Timer0 = Timer_open(TIMER_0, &params0);
    if (Timer0 == NULL) {
      //Timer_open() failed
     while (1);}

    status = Timer_start(Timer0);
    GPIO_write(GPIO_TX, 0);

}
void frameSync_callback(Timer_Handle Timer0, int_fast16_t status) {
    switch(state) {
    case TA:
        Timer_setPeriod(Timer0,Timer_PERIOD_HZ, TARI_HIGH_PERIOD);
        Timer_start(Timer0);
        GPIO_write(GPIO_TX,1);
        state = PW;
        break;
    case PW:
        Timer_setPeriod(Timer0, Timer_PERIOD_HZ, PW_PERIOD);
        Timer_start(Timer0);
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
        Timer_setPeriod(Timer0, Timer_PERIOD_HZ, RTCAL_HIGH_PERIOD);
        Timer_start(Timer0);
        GPIO_write(GPIO_TX, 1);
        state = PW;
        break;
    case END:
        GPIO_write(GPIO_TX, 1);
        Timer_close(Timer0);
        state = TA;
        break;
    default: break;
    }
}

void preamble(void) {
    Timer_Params_init(&params1);
    params1.periodUnits = Timer_PERIOD_HZ;
    params1.period = DELIM_PERIOD;
    params1.timerMode  = Timer_ONESHOT_CALLBACK;
    params1.timerCallback = preamble_callback;

    Timer1 = Timer_open(TIMER_1, &params1);
    if (Timer1 == NULL) {
      // Timer_open() failed
      while (1);}

    status = Timer_start(Timer1);
    GPIO_write(GPIO_TX, 0);
}

void preamble_callback(Timer_Handle Timer1, int_fast16_t status) {
    switch(state){
    case TA:
        Timer_setPeriod(Timer1, Timer_PERIOD_HZ, TARI_HIGH_PERIOD);
        Timer_start(Timer1);
        GPIO_write(GPIO_TX, 1);
        state = PW;
        break;
    case PW:
        Timer_setPeriod(Timer1, Timer_PERIOD_HZ, PW_PERIOD);
        Timer_start(Timer1);
        GPIO_write(GPIO_TX, 0);
        switch(pwState) {
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
        Timer_setPeriod(Timer1, Timer_PERIOD_HZ, RTCAL_HIGH_PERIOD);
        Timer_start(Timer1);
        GPIO_write(GPIO_TX, 1);
        state = PW;
        break;
    case TR:
        Timer_setPeriod(Timer1, Timer_PERIOD_HZ, TRCAL_HIGH_PERIOD);
        Timer_start(Timer1);
        GPIO_write(GPIO_TX, 1);
        state = PW;
        break;
    case END:
        GPIO_write(GPIO_TX, 1);
        Timer_close(Timer1);
        state = TA;
        break;
    default: break;
    }
}

#endif
