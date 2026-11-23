#include <stdio.h>

int main()
{
    int n, i, j;
    int pid[20], bt[20], pr[20], wt[20], tat[20];
    int temp;
    float awt = 0, atat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        pid[i] = i + 1;
        printf("Enter burst time and priority for P%d: ", i + 1);
        scanf("%d %d", &bt[i], &pr[i]);
    }

    // Sort by priority (lower number = higher priority)
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (pr[j] > pr[j + 1])
            {
                temp = pr[j];  pr[j]  = pr[j + 1];  pr[j + 1]  = temp;
                temp = bt[j];  bt[j]  = bt[j + 1];  bt[j + 1]  = temp;
                temp = pid[j]; pid[j] = pid[j + 1]; pid[j + 1] = temp;
            }

    wt[0] = 0;
    for (i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1];

    for (i = 0; i < n; i++)
    {
        tat[i] = wt[i] + bt[i];
        awt  += wt[i];
        atat += tat[i];
    }

    printf("\nProcess\tBT\tPriority\tWT\tTAT\n");
    for (i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t\t%d\t%d\n", pid[i], bt[i], pr[i], wt[i], tat[i]);

    printf("\nAverage Waiting Time    = %.2f\n", awt / n);
    printf("Average Turnaround Time = %.2f\n", atat / n);
    return 0;
}
