#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "mutex.h"
#include "condition_variable.h"

Mutex myMutex;
ConditionVariable myCV;

void *thread_function(void *arg) {
    mutex_lock(&myMutex);
    printf("Critical section entered by thread %ld\n", (long)arg);
    // Simulate some work
    sleep(1);
    mutex_unlock(&myMutex);
    return NULL;
}

void *thread1_function(void *arg) {
    condition_variable_wait(&myCV);
    printf("Thread 1 woke up\n");
    return NULL;
}

void *thread2_function(void *arg) {
    sleep(1); // Simulate some work
    condition_variable_notify(&myCV);
    return NULL;
}

int main() {
    pthread_t threads[4];

    // Example of using mutex (lock)
    mutex_init(&myMutex);

    for (int i = 0; i < 2; ++i) {
        pthread_create(&threads[i], NULL, thread_function, (void *)(long)i);
    }

    for (int i = 0; i < 2; ++i) {
        pthread_join(threads[i], NULL);
    }

    mutex_destroy(&myMutex);

    // Example of using condition variable
    condition_variable_init(&myCV);

    pthread_create(&threads[2], NULL, thread1_function, NULL);
    pthread_create(&threads[3], NULL, thread2_function, NULL);

    pthread_join(threads[2], NULL);
    pthread_join(threads[3], NULL);

    condition_variable_destroy(&myCV);

    return 0;
}
