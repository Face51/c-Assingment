#include <stdio.h>

// Function to swap values without third variable
void swap(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int main() {
    int x, y;

    // Declaring function pointer
    void (*fptr)(int*, int*);

    // Assigning function pointer to swap function
    fptr = swap;

    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);

    printf("\nBefore Swapping: x = %d, y = %d\n", x, y);

    // Calling swap using function pointer
    fptr(&x, &y);

    printf("After Swapping : x = %d, y = %d\n", x, y);

    return 0;
}