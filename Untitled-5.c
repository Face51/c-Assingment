#include <stdio.h>

// Function to insert an element
void insert(int arr[], int *n)
{
    int pos, value, i;

    printf("Enter position (0 to %d): ", *n);
    scanf("%d", &pos);

    if (pos < 0 || pos > *n)
    {
        printf("Invalid position\n");
        return;
    }

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
void deleteElement(int arr[], int *n)
{
    int pos, i;

    if (*n == 0)
    {
        printf("Array is empty\n");
        return;
    }

    printf("Enter position (0 to %d): ", *n - 1);
    scanf("%d", &pos);

    if (pos < 0 || pos >= *n)
    {
        printf("Invalid position\n");
        return;
    }

    for (i = pos; i < *n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    (*n)--;
}

// Function to display array
void display(int arr[], int n)
{
    int i;

    if (n == 0)
    {
        printf("Array is empty\n");
        return;
    }

    printf("Array elements: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
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

    while (1)
    {
        printf("\n--- MENU ---");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert(arr, &n);
                display(arr, n);
                break;

            case 2:
                deleteElement(arr, &n);
                display(arr, n);
                break;

            case 3:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
