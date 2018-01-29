/*
 * This file defines the create thread method.
 */

/*
 *  ======== threads.c ========
 */


#include "include/system/threads.h"
#include <pthread.h>


void SysCreateThread(RunnableCallback callback,
                     size_t stackSize,
                     int priority,
                     void* arg)
{
    pthread_t           thread;
    pthread_attr_t      attrs;
    struct sched_param  priParam;
    int                 retc;
    int                 detachState;

    /* Set priority and stack size attributes */
    pthread_attr_init(&attrs);
    priParam.sched_priority = priority;

    detachState = PTHREAD_CREATE_DETACHED;
    retc = pthread_attr_setdetachstate(&attrs, detachState);
    if (retc != 0) {
        /* pthread_attr_setdetachstate() failed */
        while (1);
    }

    pthread_attr_setschedparam(&attrs, &priParam);

    retc |= pthread_attr_setstacksize(&attrs, stackSize);
    if (retc != 0) {
        /* pthread_attr_setstacksize() failed */
        while (1);
    }

    retc = pthread_create(&thread, &attrs, callback, arg);
    if (retc != 0) {
        /* pthread_create() failed */
        while (1);
    }
}
