#include "condition_variable.h"

void condition_variable_init(ConditionVariable *cv) {
    pthread_mutex_init(&cv->mutex, NULL);
    pthread_cond_init(&cv->cond, NULL);
    cv->is_set = 0;
}

void condition_variable_wait(ConditionVariable *cv) {
    pthread_mutex_lock(&cv->mutex);
    while (!cv->is_set) {
        pthread_cond_wait(&cv->cond, &cv->mutex);
    }
    pthread_mutex_unlock(&cv->mutex);
}

void condition_variable_notify(ConditionVariable *cv) {
    pthread_mutex_lock(&cv->mutex);
    cv->is_set = 1;
    pthread_cond_broadcast(&cv->cond);
    pthread_mutex_unlock(&cv->mutex);
}

void condition_variable_clear(ConditionVariable *cv) {
    pthread_mutex_lock(&cv->mutex);
    cv->is_set = 0;
    pthread_mutex_unlock(&cv->mutex);
}

void condition_variable_destroy(ConditionVariable *cv) {
    pthread_mutex_destroy(&cv->mutex);
    pthread_cond_destroy(&cv->cond);
}
