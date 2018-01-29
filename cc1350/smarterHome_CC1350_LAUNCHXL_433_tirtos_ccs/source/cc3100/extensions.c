/*
 * extensions.c
 *
 */


#include "include/cc3100/extensions.h"
#include "include/cc3100/porting.h"

int sem_wait_time(sem_t* sem, uint32_t time)
{
    if (SL_OS_NO_WAIT == time)
    {
        return sem_trywait(sem);
    }

    if ((uint32_t)SL_OS_WAIT_FOREVER == time)
    {
        return sem_wait(sem);
    }

    struct timespec abstime;
    abstime.tv_sec = time / 1000;
    abstime.tv_nsec = (time % 1000) * 1000000;

    return sem_timedwait(sem, &abstime);
}

