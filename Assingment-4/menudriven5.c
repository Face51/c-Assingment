#include <stdio.h>

// Function declarations
int linearSearch(int [], int, int);
void bubbleSort(int [], int);
int maxArray(int [], int);

int main() {
    int arr[100], n, ch, search, result, max, i;

    printf("Enter size of the array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    while (1) {
        printf("\n===========================\n");
        printf("        MAIN MENU\n");
        printf("===========================\n");
        printf("1. Linear Search\n");
        printf("2. Bubble Sort\n");
        printf("3. Highest Element in Array\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element to search: ");
                scanf("%d", &search);
                result = linearSearch(arr, n, search);
                if (result != -1)
                    printf("Element %d found at position %d.\n", search, result + 1);
                else
                    printf("Element %d not found in the array.\n", search);
                break;

            case 2:
                bubbleSort(arr, n);
                printf("Array sorted successfully.\nSorted array: ");
                for (i = 0; i < n; i++)
                    printf("%d ", arr[i]);
                printf("\n");
                break;

            case 3:
                max = maxArray(arr, n);
                printf("Highest element in array is: %d\n", max);
                break;

            case 4:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
                continue;
        }
    }
}

// Linear search
int linearSearch(int arr[], int n, int search) {
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == search)
            return i;
    return -1;
}

// Bubble sort (optimized)
void bubbleSort(int arr[], int n) {
    int i, j, temp, swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped)
            break;
    }
}

// Max of array
int maxArray(int arr[], int n) {
    int i, max;
    max = arr[0];
    for (i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}