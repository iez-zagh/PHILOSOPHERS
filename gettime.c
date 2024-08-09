#include "philo.h"
#include <stdio.h>
#include <pthread.h>

int shared_variable = 0;

void* increment(void* arg) {
    for (int i = 0; i < 100000; i++) {
        shared_variable++; // This is a read-modify-write operation
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, increment, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final value: %d\n", shared_variable);
    return 0;
}
