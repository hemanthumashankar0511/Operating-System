#ifndef CONDITION_VARIABLE_H
#define CONDITION_VARIABLE_H

#include <pthread.h>

typedef struct {
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int is_set;
} ConditionVariable;

void condition_variable_init(ConditionVariable *cv);
void condition_variable_wait(ConditionVariable *cv);
void condition_variable_notify(ConditionVariable *cv);
void condition_variable_clear(ConditionVariable *cv);
void condition_variable_destroy(ConditionVariable *cv);

#endif /* CONDITION_VARIABLE_H */
