/*
 * This is the main app, that takes care of setting the green LED PIN,
 * connection to the WiFi and sends a message when the MQTT is ready
 * (after turning the green LED on, indicating that the system is ready).
 */

/*
 *  ======== app_main.c ========
 */

#include "include/apps/app_main.h"
#include "include/system/mqueue.h"
#include <ti/drivers/PIN.h>
#include "include/Board.h"

#define MY_TASK_ID      APP_MAIN_THREAD


static PIN_Handle ledPinHandle;
static PIN_State ledPinState;

PIN_Config ledPinTable[] = {
    Board_PIN_LED1 | PIN_GPIO_OUTPUT_EN | PIN_GPIO_LOW | PIN_PUSHPULL | PIN_DRVSTR_MAX,
    PIN_TERMINATE
};

void* MainThread(void *arg0)
{
    task_message_t inputMessage;
    task_message_t outputMessage;

    memset(&outputMessage, 0x00, sizeof(task_message_t));

    ledPinHandle = PIN_open(&ledPinState, ledPinTable);
    if(!ledPinHandle) {
        /* Error initializing board LED pins */
        while(1);
    }

    SysCreateQueue(MY_TASK_ID, "MainQueue");

    while(1)
    {
        SysWaitOnQueue(MY_TASK_ID, &inputMessage, sizeof(task_message_t));
        System_printf("MainTask recv: %u\n", inputMessage.message_type);
        System_flush();

        switch(inputMessage.message_type)
        {
            case SYS_MSG_WIFI_CONNECTED:
                outputMessage.message_type = SYS_MSG_MQTT_DO_CONNECT;
                SysPublishToQueue(APP_MQTT_THREAD, &outputMessage, sizeof(outputMessage));
                break;

            case SYS_MSG_MQTT_READY:
                PIN_setOutputValue(ledPinHandle, Board_PIN_LED1, 1); //Turning the green LED on, indicating that the system is ready.
                outputMessage.message_type = SYS_MSG_APP_START;
                SysPublishToQueue(APP_USER_THREAD, &outputMessage, sizeof(outputMessage));
                break;
        }

        SysReleaseMessage(&inputMessage);
    }
}
