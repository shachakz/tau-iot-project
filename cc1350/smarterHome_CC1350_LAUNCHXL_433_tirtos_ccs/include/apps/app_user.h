/*
 * app_user.h
 *
 */

#ifndef INCLUDE_APPS_APP_USER_H_
#define INCLUDE_APPS_APP_USER_H_


#include "include/apps/app_mqtt.h"

typedef void (*OnMessageArrived)(MessageData*);

typedef subscribtion_params_t subscribe_t;

void UserInit(void);

extern subscribe_t  subscriptions[];
extern unsigned int subscriptionsSize;


#endif /* INCLUDE_APPS_APP_USER_H_ */
