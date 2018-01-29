/*
 * mqueue.h
 *
 */

#ifndef INCLUDE_SYSTEM_MQUEUE_H_
#define INCLUDE_SYSTEM_MQUEUE_H_

#include "system_common.h"
#include <ti/sysbios/posix/mqueue.h>

typedef mqd_t message_queue_t;

int SysCreateQueue(task_name_e taskId, char* name);
int SysPublishToQueue(task_name_e taskId, task_message_t* msg, size_t msgLen);
int SysPublishToQueueBlocking(task_name_e taskId, task_message_t* msg, size_t msgLen);
int SysWaitOnQueue(task_name_e taskId, task_message_t* msg, size_t maxMsgLen);
void SysReleaseMessage(task_message_t* msg);

#endif /* INCLUDE_SYSTEM_MQUEUE_H_ */
