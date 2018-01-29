/*
 * This file defines and implements all the methods that a user can do when being asked to.
 * It includes dimming, turning off, turning on and toggling LEDs, and measuring the temperature.
 * In addition, it contains the list of queues subjects the the user is subscribed to.
 */

/*
 *  ======== user.c ========
 */

#include "include/apps/app_user.h"
#include <ti/drivers/PWM.h>
#include <ti/devices/cc13x0/driverlib/aon_batmon.h>
#include <ti/devices/cc13x0/driverlib/setup_rom.h>

#include "include/Board.h"
#include <string.h>
#include <stdlib.h>

static PWM_Handle pwm1;
const uint16_t   pwmDutyOn  = 3000;
const uint16_t   pwmDutyOff = 0;
uint16_t   currentPwm;


void UserInit(void)
{
    //LED init
    PWM_Params params;

    pwm1 = NULL;
    pwm1 = NULL;
    PWM_init();

    PWM_Params_init(&params);
    params.dutyUnits = PWM_DUTY_US;
    params.dutyValue = pwmDutyOff;
    params.periodUnits = PWM_PERIOD_US;
    params.periodValue = pwmDutyOn;

    currentPwm = pwmDutyOff;

    pwm1 = PWM_open(Board_PWM0, &params);
    if (pwm1 == NULL) {
        /* Board_PWM0 did not open */
        while (1);
    }

    PWM_start(pwm1);

    AONBatMonEnable();
}

void TurnOn(MessageData* md, char* response, char* param)
{
    currentPwm = pwmDutyOn;
    PWM_setDuty(pwm1, currentPwm);

    sprintf(response, "OK");
}

void TurnOff(MessageData* md, char* response, char* param)
{
    currentPwm = pwmDutyOff;
    PWM_setDuty(pwm1, currentPwm);

    sprintf(response, "Sir yes sir!");
}

void Toggle(MessageData* md, char* response, char* param)
{
    currentPwm = pwmDutyOn - currentPwm;
    PWM_setDuty(pwm1, currentPwm);

    sprintf(response, "Just did");
}

void Dim(MessageData* md, char* response, char* param)
{
    uint8_t dimValue = atoi(param);

    if(dimValue > 100) {
        dimValue = 100;
    }

    currentPwm = pwmDutyOn * dimValue / 100;
    PWM_setDuty(pwm1, currentPwm);

    /* Handle response. */
    sprintf(response, "Dimming lights to %u out of 100", dimValue);
}

void TempState(MessageData* md, char* response, char* param)
{
    int32_t tempC = AONBatMonTemperatureGetDegC();

    /* Handle response. */
    sprintf(response, "Temperature is %d Celsius degrees", tempC);
}

subscribe_t subscriptions[] =   {
                                     { "bedroom/lights/on",     TurnOn },
                                     { "bedroom/lights/off",    TurnOff },
                                     { "bedroom/lights/toggle", Toggle },
                                     { "bedroom/lights/dim",    Dim },
                                     { "bedroom/temperature/state",    TempState}
                                };

unsigned int subscriptionsSize = sizeof(subscriptions) / sizeof(subscribe_t);
