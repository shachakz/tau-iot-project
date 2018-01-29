/*
 * This file defines the stack and priority of each thread.
 */

/*
 * apps_config.h
 *
 */

#ifndef INCLUDE_APPS_APPS_CONFIG_H_
#define INCLUDE_APPS_APPS_CONFIG_H_

#include <unistd.h>
#include <pthread.h>

/* This include for debug, we can move this to sys print. */
#include <xdc/std.h>
#include <xdc/runtime/System.h>

#include "include/Board.h"

#include "message_types.h"


/* Define IN/OUT for easier input type recognition. */
#define IN
#define OUT

typedef enum{
    APP_MAIN_THREAD     = 0x00,
    APP_WIFI_THREAD,
    APP_WIFI_EVTS_THREAD,
    APP_MQTT_THREAD,
    APP_MQTT_DAEMON_THREAD,

    APP_USER_THREAD,

    MAX_NUM_OF_THREADS
}task_name_e;

/* Tasks priorities and thread sizes. */
#define MAIN_TASK_PRIORITY                  ( 5 )
#define MAIN_TASK_THREAD_SIZE_BYTES         ( 1024 )

#define WIFI_TASK_PRIORITY                  ( 4 )
#define WIFI_TASK_THREAD_SIZE_BYTES         ( 1536 )

#define WIFI_EVT_TASK_PRIORITY              ( 4 )
#define WIFI_EVT_TASK_THREAD_SIZE_BYTES     ( 512 )

#define MQTT_TASK_PRIORITY                  ( 3 )
#define MQTT_TASK_THREAD_SIZE_BYTES         ( 2048 )

#define MQTT_DAEMON_TASK_PRIORITY           ( 2 )
#define MQTT_DAEMON_TASK_THREAD_SIZE_BYTES  ( 1536 )

#define USER_TASK_PRIORITY                  ( 1 )
#define USER_TASK_THREAD_SIZE_BYTES         ( 1024 )

#endif /* INCLUDE_APPS_APPS_CONFIG_H_ */
