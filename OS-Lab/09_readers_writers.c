#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

int shared_data = 0;
int read_count = 0;

sem_t mutex;      // protects read_count
sem_t rw_mutex;   // exclusive access for writers

void *reader(void *arg)
{
    int reader_id = *(int *)arg;

    sem_wait(&mutex);
    read_count++;
    if (read_count == 1)
        sem_wait(&rw_mutex);        // first reader locks out writers
    sem_post(&mutex);

    printf("Reader %d is reading data: %d\n", reader_id, shared_data);
    sleep(1);

    sem_wait(&mutex);
    read_count--;
    if (read_count == 0)
        sem_post(&rw_mutex);        // last reader lets writers in
    sem_post(&mutex);

    printf("Reader %d has finished reading.\n", reader_id);
    return NULL;
}

void *writer(void *arg)
{
    int writer_id = *(int *)arg;

    sem_wait(&rw_mutex);
    shared_data++;
    printf("Writer %d is writing data: %d\n", writer_id, shared_data);
    sleep(2);
    printf("Writer %d has finished writing.\n", writer_id);
    sem_post(&rw_mutex);
    return NULL;
}

int main()
{
    pthread_t readers[3], writers[2];
    int reader_id[3] = {1, 2, 3};
    int writer_id[2] = {1, 2};

    sem_init(&mutex, 0, 1);
    sem_init(&rw_mutex, 0, 1);

    for (int i = 0; i < 3; i++)
        pthread_create(&readers[i], NULL, reader, &reader_id[i]);
    for (int i = 0; i < 2; i++)
        pthread_create(&writers[i], NULL, writer, &writer_id[i]);

    for (int i = 0; i < 3; i++)
        pthread_join(readers[i], NULL);
    for (int i = 0; i < 2; i++)
        pthread_join(writers[i], NULL);

    sem_destroy(&mutex);
    sem_destroy(&rw_mutex);

    printf("\nFinal shared data value: %d\n", shared_data);
    return 0;
}
