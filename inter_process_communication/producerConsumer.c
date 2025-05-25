#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define SIZE 5  // size of the buffer

int buffer[SIZE];
int in = 0, out = 0;

sem_t empty;   // counts empty slots
sem_t full;    // counts filled slots
pthread_mutex_t mutex;  // to protect critical section

// Producer function
void* producer(void* arg) {
    int item;
    for(int i = 0; i < 10; i++) {
        item = rand() % 100;  // produce an item
        sem_wait(&empty);     // check if buffer is full
        pthread_mutex_lock(&mutex);  // enter critical section

        buffer[in] = item;
        printf("Producer produced item: %d at index %d\n", item, in);
        in = (in + 1) % SIZE;

        pthread_mutex_unlock(&mutex);  // exit critical section
        sem_post(&full);     // increase full count

        sleep(1);
    }
    pthread_exit(NULL);
}

// Consumer function
void* consumer(void* arg) {
    int item;
    for(int i = 0; i < 10; i++) {
        sem_wait(&full);     // check if buffer has items
        pthread_mutex_lock(&mutex);  // enter critical section

        item = buffer[out];
        printf("Consumer consumed item: %d from index %d\n", item, out);
        out = (out + 1) % SIZE;

        pthread_mutex_unlock(&mutex);  // exit critical section
        sem_post(&empty);    // increase empty count

        sleep(2);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t prod, cons;

    // Initialize semaphores and mutex
    sem_init(&empty, 0, SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    // Create producer and consumer threads
    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    // Wait for threads to finish
    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    // Destroy semaphores and mutex
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}
