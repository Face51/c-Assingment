#include <stdio.h>

// Define structure
struct Person
{
    int age;
    float weight;
};

int main()
{
    struct Person p[10];        // array of structures
    struct Person *ptr;         // pointer to structure
    int i;

    ptr = p;   // pointer points to first structure

    // Input age and weight
    for (i = 0; i < 10; i++)
    {
        printf("\nEnter details of person %d\n", i + 1);
        printf("Age: ");
        scanf("%d", &(ptr + i)->age);

        printf("Weight: ");
        scanf("%f", &(ptr + i)->weight);
    }

    // Display age and weight
    printf("\n--- Person Details ---\n");
    for (i = 0; i < 10; i++)
    {
        printf("Person %d -> Age: %d, Weight: %.2f\n",
               i + 1,
               (ptr + i)->age,
               (ptr + i)->weight);
    }

    return 0;
}
