#include <stdio.h>

int main() {
    int number, org, sum = 0, digits[10], n = 0;

    printf("Enter a positive integer: ");
    scanf("%d", &number);

    if (number <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    org = number;

    // Extract digits and count at the same time
    int temp = org;
    while (temp) {
        digits[n++] = temp % 10;
        temp /= 10;
    }

    // Calculate sum using stored digits
    for (int i = 0; i < n; i++) {
        int power = 1;
        for (int j = 0; j < n; j++) power *= digits[i];
        sum += power;
    }

    printf("%d is %san Armstrong number.\n", org, (sum == org) ? "" : "not ");

    return 0;
}
