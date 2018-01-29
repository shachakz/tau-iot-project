/*
 * app_mqtt.h
 *
 */

#ifndef INCLUDE_APPS_APP_MQTT_H_
#define INCLUDE_APPS_APP_MQTT_H_

#include "apps_config.h"
#include "include/mqtt/MQTTClient.h"

typedef void (*SubscribeHandler)(MessageData* md, char* response, char* param);

typedef struct {
    char*               topic;
    SubscribeHandler    handler;
} subscribtion_params_t;

typedef struct {
    char*               topic;
    char*               message_data;
} publish_params_t;

void PublishMqtt(char* topic, char* msg);
void SubscribeMqtt(char* topic, messageHandler handler, int correlation);

#endif /* INCLUDE_APPS_APP_MQTT_H_ */
