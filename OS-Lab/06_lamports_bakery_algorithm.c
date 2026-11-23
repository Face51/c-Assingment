#include <stdio.h>
#include <pthread.h>

#define N 2

int choosing[N] = {0};
int number[N] = {0};
int shared_counter = 0;

void lock(int process)
{
    int i;
    choosing[process] = 1;

    number[process] = 1;
    for (i = 0; i < N; i++)
        if (number[i] > number[process])
            number[process] = number[i];
    number[process]++;

    choosing[process] = 0;

    for (i = 0; i < N; i++)
    {
        while (choosing[i]);
        while (number[i] != 0 &&
              (number[i] < number[process] ||
              (number[i] == number[process] && i < process)));
    }
}

void unlock(int process) { number[process] = 0; }

void *process(void *arg)
{
    int id = *(int *)arg;
    for (int i = 0; i < 3; i++)
    {
        lock(id);
        shared_counter++;                       // Critical Section
        printf("Process %d: Counter = %d\n", id, shared_counter);
        unlock(id);
    }
    return NULL;
}

int main()
{
    pthread_t t[N];
    int id[N] = {0, 1};

    for (int i = 0; i < N; i++)
        pthread_create(&t[i], NULL, process, &id[i]);
    for (int i = 0; i < N; i++)
        pthread_join(t[i], NULL);

    printf("Final Counter = %d\n", shared_counter);
    return 0;
}
