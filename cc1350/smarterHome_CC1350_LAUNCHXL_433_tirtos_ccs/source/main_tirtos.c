/*
 * This is the main function that runs on startup.
 */

/*
 *  ======== main_tirtos.c ========
 */
#include <stdint.h>

/* POSIX Header files */
#include "include/system/threads.h"
#include "include/apps/apps_config.h"
/* RTOS header files */
#include <ti/sysbios/BIOS.h>

/* Example/Board Header files */
#include "../include/Board.h"

extern void *MainThread(void *arg0);
extern void *WifiThread(void *arg0);
extern void *MqttThread(void *arg0);
extern void *UserThread(void *arg0);


int main(void)
{
    /* Call driver init functions. */
    Board_initGeneral();

    /* Shutdown external flash. */
    Board_shutDownExtFlash();

    /* Start the main Thread. */
    SysCreateThread(MainThread, MAIN_TASK_THREAD_SIZE_BYTES, MAIN_TASK_PRIORITY, NULL);

    /* Start the wifi Thread. */
    SysCreateThread(WifiThread, WIFI_TASK_THREAD_SIZE_BYTES, WIFI_TASK_PRIORITY, NULL);

    /* Start the mqtt Thread. */
    SysCreateThread(MqttThread, MQTT_TASK_THREAD_SIZE_BYTES, MQTT_TASK_PRIORITY, NULL);

    /* Start the user Thread. */
    SysCreateThread(UserThread, USER_TASK_THREAD_SIZE_BYTES, USER_TASK_PRIORITY, NULL);

    BIOS_start();

    return (0);
}
