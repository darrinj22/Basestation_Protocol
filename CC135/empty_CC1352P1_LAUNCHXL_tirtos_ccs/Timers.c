#include "ti_drivers_config.h"

#include <ti/drivers/Timer.h>
#include <ti/drivers/GPIO.h>
#include "functions.h"

// Preamble Macros:
#define TARI                        ( 12.5 )
#define DELIM_PERIOD                ( 12.5 )                    // Independent of Tari
#define TARI_HIGH_PERIOD            ( TARI-PW_PERIOD )
#define PW_PERIOD                   ( TARI*0.395 )              // Approx. 5 for Tari = 12.5
#define RTCAL_HIGH_PERIOD           ( (TARI*2.75)-PW_PERIOD )
#define TRCAL_HIGH_PERIOD           ( (TARI*2.05)-PW_PERIOD )

uint16_t fSyncFlag;
uint16_t what;
Timer_Handle    Timer0;
Timer_Params    params;

void preamble() {                                               // R=>T Preamble

    Timer_Params_init(&params);
    params.periodUnits = Timer_PERIOD_US;
    params.timerMode  = Timer_ONESHOT_CALLBACK;

    params.period = DELIM_PERIOD;
    params.timerCallback = tariHigh;
    Timer0 = Timer_open(TIMER_0, &params);

    int32_t status = Timer_start(Timer0);
    GPIO_write(GPIO_TX, 0);
   // what = GPIO_read(GPIO_TX);
}

void frameSync() {
    Timer_Params_init(&params);
    params.periodUnits = Timer_PERIOD_US;
    params.timerMode  = Timer_ONESHOT_CALLBACK;

    fSyncFlag = 1;

    params.period = DELIM_PERIOD;
    params.timerCallback = tariHigh;
    Timer0 = Timer_open(TIMER_0, &params);

    Timer_start(Timer0);
    GPIO_write(GPIO_TX, 0);
    what = GPIO_read(GPIO_TX);
}

void tariHigh(Timer_Handle myHandle, int_fast16_t status) {
    params.timerCallback = pw;
    params.period = TARI_HIGH_PERIOD;
    Timer_start(Timer0);
    GPIO_write(GPIO_TX, 1);
   // what = GPIO_read(GPIO_TX);
}

void pw(Timer_Handle myHandle, int_fast16_t status) {
    params.timerCallback = RTcal;
    params.period = PW_PERIOD;
    Timer_start(Timer0);
    GPIO_write(GPIO_TX, 0);
   what = GPIO_read(GPIO_TX);
}

void RTcal(Timer_Handle myHandle, int_fast16_t status) {
    params.timerCallback = pw2;
    params.period = RTCAL_HIGH_PERIOD;
    Timer_start(Timer0);
    GPIO_write(GPIO_TX, 1);
   // what = GPIO_read(GPIO_TX);
}

void pw2(Timer_Handle myHandle, int_fast16_t status) {
    params.timerCallback = TRcal;
    if (fSyncFlag) {
        params.timerCallback = 0;
        fSyncFlag = 0;
    }
    params.period = PW_PERIOD;
    Timer_start(Timer0);
    GPIO_write(GPIO_TX, 0);
   // what = GPIO_read(GPIO_TX);
}

void TRcal(Timer_Handle myHandle, int_fast16_t status) {
    params.timerCallback = pw3;
    params.period = TRCAL_HIGH_PERIOD;
    Timer_start(Timer0);
    GPIO_write(GPIO_TX, 1);
   // what = GPIO_read(GPIO_TX);
}

void pw3(Timer_Handle myHandle, int_fast16_t status) {
    params.timerCallback = 0;
    params.period = PW_PERIOD;
    Timer_start(Timer0);
    GPIO_write(GPIO_TX, 0);
    //what = GPIO_read(GPIO_TX);
}
