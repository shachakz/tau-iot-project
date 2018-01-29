/*
 * This file contains the mqtt's methods.
 */

/*
 *  ======== mqueue.c ========
 */


#include "include/system/mqueue.h"

static message_queue_t knownMQueues[MAX_NUM_OF_THREADS] = {0};

int SysCreateQueue(task_name_e taskId, char* name)
{
    struct mq_attr ma;

    // Specify message queue attributes.
    ma.mq_flags = 0;                            // blocking read/write
    ma.mq_maxmsg = 4;                           // maximum number of messages allowed in queue
    ma.mq_msgsize = sizeof(task_message_t);     // messages are contents of a task_message_t
    ma.mq_curmsgs = 0;                          // number of messages currently in queue

    // Create the message queue with some default settings.
    return NULL != (knownMQueues[taskId] = mq_open(name, O_RDWR | O_CREAT, 0700, &ma));
}

int SysPublishToQueue(task_name_e taskId, task_message_t* msg, size_t msgLen)
{
    msg->semaphore = NULL;

    /* Assumes all priorities are equal :D. */
    return mq_send(knownMQueues[taskId], (const char *)msg, msgLen, 1);
}

int SysPublishToQueueBlocking(task_name_e taskId, task_message_t* msg, size_t msgLen)
{
    int ret;
    sem_t sem;
    if(SYS_SUCCESS != sem_init(&sem, 1, 0)) //this semaphore should be shared!!!
    {
        return SYS_FAIL;
    }

    msg->semaphore = &sem;

    ret = mq_send(knownMQueues[taskId], (const char *)msg, msgLen, 1);
    sem_wait(&sem);
    sem_destroy(&sem);

    return ret;
}

int SysWaitOnQueue(task_name_e taskId, task_message_t* msg, size_t maxMsgLen)
{
    unsigned int devNull;
    return mq_receive(knownMQueues[taskId], msg, maxMsgLen, &devNull);
}

void SysReleaseMessage(task_message_t* msg)
{
    if (NULL != msg->semaphore)
    {
        sem_post(msg->semaphore);
    }
}
