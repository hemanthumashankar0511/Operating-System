#include "mutex.h"

void mutex_init(Mutex *mutex) {
    pthread_mutex_init(&mutex->mutex, NULL);
}

void mutex_lock(Mutex *mutex) {
    pthread_mutex_lock(&mutex->mutex);
}

void mutex_unlock(Mutex *mutex) {
    pthread_mutex_unlock(&mutex->mutex);
}

void mutex_destroy(Mutex *mutex) {
    pthread_mutex_destroy(&mutex->mutex);
}
```
