#include <stdio.h>

int main()
{
    FILE *fp;
    char ch;

    // Open file in write mode
    fp = fopen("demo.txt", "w");

    // Write some text into file
    fputs("Hello C Programming", fp);

    // Close the file
    fclose(fp);

    // Reopen file in read mode
    fp = fopen("demo.txt", "r");

    // ftell() – tells current file position
    printf("Initial position: %ld\n", ftell(fp));

    // Read one character
    ch = fgetc(fp);
    printf("Character read: %c\n", ch);

    // Position after reading one character
    printf("Position after reading one character: %ld\n", ftell(fp));

    // fseek() – move file pointer to 6th position
    fseek(fp, 6, SEEK_SET);
    printf("Position after fseek(): %ld\n", ftell(fp));

    // Read character at new position
    ch = fgetc(fp);
    printf("Character after fseek: %c\n", ch);

    // rewind() – move pointer to beginning of file
    rewind(fp);
    printf("Position after rewind(): %ld\n", ftell(fp));

    // Read first character again
    ch = fgetc(fp);
    printf("First character after rewind: %c\n", ch);

    // Close file
    fclose(fp);

    return 0;
}
