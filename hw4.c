#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int numGlobal = 0;

void *myThreadFunction(void *arg) {
    int *ID = (int *)arg;
    ++numGlobal;

    printf("Thread ID: %d, Global: %d\n", *ID, ++numGlobal);
    pthread_exit(NULL);
}

int main(int argc, char** argv) {
    pthread_t my_thread[10];

    for (int i = 1; i <= 10; ++i) {
        int x = pthread_create(&my_thread[i], NULL, myThreadFunction, (void *)&i);

        if (x != 0) {
            printf("pthread_create() failed\n");
            exit(EXIT_FAILURE);
        }
    }
    pthread_exit(NULL);
}

// The global number never exceeds 20... perhaps it will never exceed the number of threads * 2.
