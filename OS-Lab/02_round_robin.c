#include <stdio.h>

int main()
{
    int n, i, tq, time = 0, done = 0;
    int bt[20], rem[20], wt[20], tat[20];
    float awt = 0, atat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter burst time for P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rem[i] = bt[i];
    }

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    // All processes arrive at time 0
    while (done < n)
    {
        for (i = 0; i < n; i++)
        {
            if (rem[i] > 0)
            {
                if (rem[i] > tq)
                {
                    time += tq;
                    rem[i] -= tq;
                }
                else
                {
                    time += rem[i];
                    rem[i] = 0;
                    tat[i] = time;              // completion time (arrival = 0)
                    wt[i]  = tat[i] - bt[i];
                    done++;
                }
            }
        }
    }

    printf("\nProcess\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
        awt  += wt[i];
        atat += tat[i];
    }

    printf("\nAverage Waiting Time    = %.2f\n", awt / n);
    printf("Average Turnaround Time = %.2f\n", atat / n);
    return 0;
}
