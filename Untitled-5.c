#include <stdio.h>

// Function to insert an element
void insert(int arr[], int *n)
{
    int pos, value, i;

    printf("Enter position to insert (0 to %d): ", *n);
    scanf("%d", &pos);

    printf("Enter value to insert: ");
    scanf("%d", &value);

    for (i = *n; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[pos] = value;
    (*n)++;
}

// Function to delete an element
void delete(int arr[], int *n)
{
    int pos, i;

    printf("Enter position to delete (0 to %d): ", *n - 1);
    scanf("%d", &pos);

    for (i = pos; i < *n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    (*n)--;
}

int main()
{
    int arr[100];
    int n, i, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\n1. Insert");
    printf("\n2. Delete");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        insert(arr, &n);
    }
    else if (choice == 2)
    {
        delete(arr, &n);
    }
    else
    {
        printf("Invalid choice");
        return 0;
    }

    printf("\nUpdated array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}