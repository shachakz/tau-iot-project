/*
 * threads.h
 *
 */

#ifndef INCLUDE_SYSTEM_THREADS_H_
#define INCLUDE_SYSTEM_THREADS_H_

#include <string.h>
#include "system_common.h"

/* The runnable type. */
typedef void* (*RunnableCallback)(void* arg);

/* Create new thread. */
void SysCreateThread(RunnableCallback callback, size_t stackSize, int priority, void* arg);

#endif /* INCLUDE_SYSTEM_THREADS_H_ */
