#include <stdio.h>

// Function using Call by Value
void swapByValue(int x, int y) {
    printf("\n[Call by Value]");
    printf("\nBefore Swap: x = %d, y = %d", x, y);

    // Swap without temporary variable
    x = x + y;
    y = x - y;
    x = x - y;

    printf("\nAfter Swap:  x = %d, y = %d\n", x, y);
}

// Function using Call by Reference
void swapByReference(int *x, int *y) {
    printf("\n[Call by Reference]");
    printf("\nBefore Swap: x = %d, y = %d", *x, *y);

    // Swap without temporary variable
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;

    printf("\nAfter Swap:  x = %d, y = %d\n", *x, *y);
}

int main() {
    int a, b;

    // User input
    printf("Enter two numbers (a and b): ");
    scanf("%d %d", &a, &b);

    printf("\nInitial values: a = %d, b = %d", a, b);

    // Call by Value
    swapByValue(a, b);
    printf("After Call by Value : a = %d, b = %d", a, b);

    // Call by Reference
    swapByReference(&a, &b);
    printf("\nAfter Call by Reference : a = %d, b = %d\n", a, b);

    return 0;
}
