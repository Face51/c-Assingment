#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex;

void *process(void *arg)
{
    int id = *(int *)arg;

    printf("Process %d is waiting...\n", id);
    sem_wait(&mutex);                         // Wait (P)

    printf("Process %d entered Critical Section\n", id);
    sleep(2);
    printf("Process %d is leaving Critical Section\n", id);

    sem_post(&mutex);                         // Signal (V)
    return NULL;
}

int main()
{
    pthread_t t1, t2;
    int p1 = 1, p2 = 2;

    sem_init(&mutex, 0, 1);                   // binary semaphore

    pthread_create(&t1, NULL, process, &p1);
    pthread_create(&t2, NULL, process, &p2);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    sem_destroy(&mutex);
    return 0;
}
