/*
 * This file defines the system message types, and the structure of a message.
 */

/*
 * message_types.h
 *
 */


#ifndef INCLUDE_APPS_MESSAGE_TYPES_H_
#define INCLUDE_APPS_MESSAGE_TYPES_H_

#include <semaphore.h>

typedef enum {
    /* Those are system message types and shouldn't be used ever by application!. */

    /* WiFi Task */
    SYS_MSG_WIFI_DO_CONNECT               = 0x00,
    SYS_MSG_WIFI_CONNECTED,
    SYS_MSG_WIFI_DISCONNECTED,

    /* MQTT Task */
    SYS_MSG_MQTT_DO_CONNECT,
    SYS_MSG_MQTT_READY,
    SYS_MSG_MQTT_ISNT_READY,

    /* Main Task */
    SYS_MSG_APP_START,

    /* Those message types are for application use and should be used when MQTT is ready. */
    SYS_MSG_MQTT_SUBSCRIBE,
    SYS_MSG_MQTT_PUBLISH,

    /* Add your application message types here. */

} message_type_e;

typedef struct task_message_s {
    sem_t*              semaphore;
    message_type_e      message_type;
    uint16_t            message_len;
    void*               message_data;

    /* This is only the 'base class' of message and can be extended with more fields by applications */
} task_message_t;

#endif /* INCLUDE_APPS_MESSAGE_TYPES_H_ */
