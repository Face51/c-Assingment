#include <stdio.h>

// Recursive function for factorial
int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

// Recursive function for Fibonacci
int fibonacci(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Recursive function for GCD
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Recursive function for sum of natural numbers
int sumNatural(int n) {
    if (n == 0)
        return 0;
    return n + sumNatural(n - 1);
}

int main() {
    int choice, n, a, b, i;

    while (1) {
        printf("\n------ MENU ------\n");
        printf("1. Factorial of a number\n");
        printf("2. Fibonacci series up to n terms\n");
        printf("3. GCD of two numbers\n");
        printf("4. Sum of first n natural numbers\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a number: ");
                scanf("%d", &n);
                printf("Factorial of %d = %d\n", n, factorial(n));
                break;

            case 2:
                printf("Enter number of terms: ");
                scanf("%d", &n);
                printf("Fibonacci Series: ");
                for (i = 0; i < n; i++)
                    printf("%d ", fibonacci(i));
                printf("\n");
                break;

            case 3:
                printf("Enter two numbers: ");
                scanf("%d %d", &a, &b);
                printf("GCD of %d and %d = %d\n", a, b, gcd(a, b));
                break;

            case 4:
                printf("Enter a number: ");
                scanf("%d", &n);
                printf("Sum of first %d natural numbers = %d\n", n, sumNatural(n));
                break;

            case 5:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
