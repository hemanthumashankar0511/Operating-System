#ifndef MUTEX_H
#define MUTEX_H

#include <pthread.h>

typedef struct {
    pthread_mutex_t mutex;
} Mutex;

void mutex_init(Mutex *mutex);
void mutex_lock(Mutex *mutex);
void mutex_unlock(Mutex *mutex);
void mutex_destroy(Mutex *mutex);

#endif /* MUTEX_H */
