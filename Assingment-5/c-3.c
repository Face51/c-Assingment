#include <stdio.h>

int main() {

    int a = 10, b = 20;

    // Pointer to Constant
    const int *ptr1 = &a;
    printf("Pointer to Constant:\n");
    printf("ptr1 points to a = %d\n", *ptr1);

    // *ptr1 = 15;  //  NOT allowed (value cannot change through pointer)
    ptr1 = &b;      //  allowed (pointer can point somewhere else)
    printf("After changing address, ptr1 now points to b = %d\n\n", *ptr1);

    // Constant Pointer
    int *const ptr2 = &a;
    printf("Constant Pointer:\n");
    printf("ptr2 points to a = %d\n", *ptr2);

    *ptr2 = 25;     //  allowed (value can change)
    printf("After modifying value through ptr2, a = %d\n", *ptr2);

    // ptr2 = &b;   //  NOT allowed (address cannot change)

    return 0;
}
