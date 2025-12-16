#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    int *ptr;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Dynamically allocate memory
    ptr = (int *)malloc(n * sizeof(int));

    // Check if memory is allocated
    if (ptr == NULL)
    {
        printf("Memory allocation failed!");
        return 1;
    }

    // Input elements
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", (ptr + i));
    }

    // Print elements using pointer
    printf("Array elements are:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", *(ptr + i));
    }

    // Free allocated memory
    free(ptr);

    return 0;
}
