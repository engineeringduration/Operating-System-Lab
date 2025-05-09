#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex, wrt;
int readCount = 0;

void* reader(void* arg) {
    int id = *(int*)arg;

    sem_wait(&mutex);
    readCount++;
    if (readCount == 1)
        sem_wait(&wrt); // First reader blocks writer
    sem_post(&mutex);

    printf("Reader %d is reading...\n", id);
    sleep(1);
    printf("Reader %d finished reading.\n", id);

    sem_wait(&mutex);
    readCount--;
    if (readCount == 0)
        sem_post(&wrt); // Last reader unlocks writer
    sem_post(&mutex);

    return NULL;
}

void* writer(void* arg) {
    int id = *(int*)arg;

    sem_wait(&wrt);
    printf("Writer %d is writing...\n", id);
    sleep(2);
    printf("Writer %d finished writing.\n", id);
    sem_post(&wrt);

    return NULL;
}

int main() {
    int numReaders, numWriters;

    printf("Enter number of readers: ");
    scanf("%d", &numReaders);

    printf("Enter number of writers: ");
    scanf("%d", &numWriters);

    pthread_t rThreads[numReaders], wThreads[numWriters];
    int rIDs[numReaders], wIDs[numWriters];

    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);

    // Create reader threads
    for (int i = 0; i < numReaders; i++) {
        rIDs[i] = i + 1;
        pthread_create(&rThreads[i], NULL, reader, &rIDs[i]);
    }

    // Create writer threads
    for (int i = 0; i < numWriters; i++) {
        wIDs[i] = i + 1;
        pthread_create(&wThreads[i], NULL, writer, &wIDs[i]);
    }

    // Wait for all threads
    for (int i = 0; i < numReaders; i++) {
        pthread_join(rThreads[i], NULL);
    }

    for (int i = 0; i < numWriters; i++) {
        pthread_join(wThreads[i], NULL);
    }

    sem_destroy(&mutex);
    sem_destroy(&wrt);

    return 0;
}
