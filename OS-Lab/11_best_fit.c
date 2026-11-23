#include <stdio.h>

int main()
{
    int b, p, i, j, best;

    printf("Enter number of blocks: ");
    scanf("%d", &b);
    int block[b];
    printf("Enter block sizes:\n");
    for (i = 0; i < b; i++)
        scanf("%d", &block[i]);

    printf("Enter number of processes: ");
    scanf("%d", &p);
    int process[p], allocation[p];
    printf("Enter process sizes:\n");
    for (i = 0; i < p; i++)
    {
        scanf("%d", &process[i]);
        allocation[i] = -1;
    }

    for (i = 0; i < p; i++)
    {
        best = -1;
        for (j = 0; j < b; j++)
            if (block[j] >= process[i])
                if (best == -1 || block[j] < block[best])
                    best = j;

        if (best != -1)
        {
            allocation[i] = best;
            block[best] -= process[i];
        }
    }

    printf("\nProcess\tSize\tBlock\n");
    for (i = 0; i < p; i++)
    {
        printf("P%d\t%d\t", i + 1, process[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
    return 0;
}
