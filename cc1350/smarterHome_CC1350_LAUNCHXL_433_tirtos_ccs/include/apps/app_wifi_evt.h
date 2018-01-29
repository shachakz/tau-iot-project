/*
 * app_wifi_evt.h
 *
 */

#ifndef INCLUDE_APPS_APP_WIFI_EVT_H_
#define INCLUDE_APPS_APP_WIFI_EVT_H_

#include "apps_config.h"

extern uint8_t connectionStatus;
extern uint8_t ipStatus;

void* WifiEventsTask(void* arg0);

#endif /* INCLUDE_APPS_APP_WIFI_EVT_H_ */
