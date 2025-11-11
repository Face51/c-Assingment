#include <stdio.h>

// Function declarations
int mystrlen(char []);
void mystrcat(char [], char []);
void mystrcopy(char [], char []);
void mystrrev(char []);
int mystrcomp(char [], char []);

int main() {
    char str1[100], str2[100];
    int ch, result;

    while (1) {
        printf("\n==============================\n");
        printf("        STRING MENU\n");
        printf("==============================\n");
        printf("1. Find Length of String\n");
        printf("2. Concatenate Two Strings\n");
        printf("3. Copy String\n");
        printf("4. Reverse String\n");
        printf("5. Compare Two Strings\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        getchar(); // to clear newline from input buffer

        switch (ch) {
            case 1:
                printf("Enter a string: ");
                gets(str1);
                printf("Length of the string = %d\n", mystrlen(str1));
                break;

            case 2:
                printf("Enter first string: ");
                gets(str1);
                printf("Enter second string: ");
                gets(str2);
                mystrcat(str1, str2);
                printf("Concatenated string: %s\n", str1);
                break;

            case 3:
                printf("Enter source string: ");
                gets(str1);
                mystrcopy(str2, str1);
                printf("Copied string: %s\n", str2);
                break;

            case 4:
                printf("Enter a string to reverse: ");
                gets(str1);
                mystrrev(str1);
                printf("Reversed string: %s\n", str1);
                break;

            case 5:                                                        //////////////start///////////
                printf("Enter first string: ");
                gets(str1);
                printf("Enter second string: ");
                gets(str2);
                result = mystrcomp(str1, str2);
                if (result == 0)
                    printf("Strings are equal.\n");
                else if (result > 0)
                    printf("First string is greater.\n");
                else
                    printf("Second string is greater.\n");
                break;

            case 6:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

// Function to find length of a string
int mystrlen(char str[]) {
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

// Function to concatenate two strings
void mystrcat(char str1[], char str2[]) {
    int i = 0, j = 0;
    while (str1[i] != '\0')
        i++;
    while (str2[j] != '\0') {
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0';
}

// Function to copy one string to another
void mystrcopy(char dest[], char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

// Function to reverse a string
void mystrrev(char str[]) {
    int i = 0, j, len, temp;
    len = mystrlen(str);
    j = len - 1;

    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

// Function to compare two strings
int mystrcomp(char str1[], char str2[]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i])
            return str1[i] - str2[i];
        i++;
    }
    return str1[i] - str2[i];

}
