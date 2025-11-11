#include <stdio.h>

// Function declarations
void inputMatrix(int [10][10], int, int);
void displayMatrix(int [10][10], int, int);
void diagonalElements(int [10][10], int, int);
void checkIdentityUnit(int [10][10], int, int);
void addMatrices(int [10][10], int [10][10], int [10][10], int, int);

int main() {
    int mat1[10][10], mat2[10][10], result[10][10];
    int r, c, ch;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter elements of first matrix:\n");
    inputMatrix(mat1, r, c);

    while (1) {
        printf("\n========== MATRIX MENU ==========\n");
        printf("1. Display Matrix\n");
        printf("2. Find Diagonal Elements\n");
        printf("3. Check Identity & Unit Matrix\n");
        printf("4. Add Two Matrices\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                displayMatrix(mat1, r, c);
                break;

            case 2:
                diagonalElements(mat1, r, c);
                break;

            case 3:
                checkIdentityUnit(mat1, r, c);
                break;

            case 4:
                printf("Enter elements of second matrix (%dx%d):\n", r, c);
                inputMatrix(mat2, r, c);
                addMatrices(mat1, mat2, result, r, c);
                printf("Resultant matrix after addition:\n");
                displayMatrix(result, r, c);
                break;

            case 5:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

// Function to input a matrix
void inputMatrix(int mat[10][10], int r, int c) {
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &mat[i][j]);
        }
    }
}

// Function to display matrix
void displayMatrix(int mat[10][10], int r, int c) {
    int i, j;
    printf("Matrix (%dx%d):\n", r, c);
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++)
            printf("%d\t", mat[i][j]);
        printf("\n");
    }
}

// Function to display diagonal elements
void diagonalElements(int mat[10][10], int r, int c) {
    int i;
    if (r != c) {
        printf("Matrix is not square, no diagonals.\n");
        return;
    }
    printf("Diagonal elements: ");
    for (i = 0; i < r; i++)
        printf("%d ", mat[i][i]);
    printf("\n");
}

// Function to check if matrix is identity/unit matrix
void checkIdentityUnit(int mat[10][10], int r, int c) {
    int i, j, identity = 1;
    if (r != c) {
        printf("Matrix is not square, cannot check identity.\n");
        return;
    }
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            if ((i == j && mat[i][j] != 1) || (i != j && mat[i][j] != 0)) {
                identity = 0;
                break;
            }
        }
    }
    if (identity)
        printf("It is an Identity (Unit) Matrix.\n");
    else
        printf("It is NOT an Identity (Unit) Matrix.\n");
}

// Function to add two matrices
void addMatrices(int mat1[10][10], int mat2[10][10], int result[10][10], int r, int c) {
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}
