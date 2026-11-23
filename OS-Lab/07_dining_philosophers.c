#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5

pthread_mutex_t forks[N];
sem_t room;

void *philosopher(void *arg)
{
    int id = *(int *)arg;
    int left = id;
    int right = (id + 1) % N;

    for (int i = 0; i < 2; i++)
    {
        printf("Philosopher %d is thinking\n", id);
        sleep(1);

        sem_wait(&room);
        pthread_mutex_lock(&forks[left]);
        pthread_mutex_lock(&forks[right]);

        printf("Philosopher %d is eating\n", id);
        sleep(1);

        pthread_mutex_unlock(&forks[right]);
        pthread_mutex_unlock(&forks[left]);
        sem_post(&room);

        printf("Philosopher %d finished eating\n", id);
    }
    return NULL;
}

int main()
{
    pthread_t threads[N];
    int id[N];

    sem_init(&room, 0, N - 1);
    for (int i = 0; i < N; i++)
        pthread_mutex_init(&forks[i], NULL);

    for (int i = 0; i < N; i++)
    {
        id[i] = i;
        pthread_create(&threads[i], NULL, philosopher, &id[i]);
    }
    for (int i = 0; i < N; i++)
        pthread_join(threads[i], NULL);

    for (int i = 0; i < N; i++)
        pthread_mutex_destroy(&forks[i]);
    sem_destroy(&room);
    return 0;
}
