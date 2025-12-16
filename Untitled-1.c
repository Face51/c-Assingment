#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *a, *b;
    char ch;

    a = fopen(argv[1], "r");   // open source file
    b = fopen(argv[2], "w");   // open destination file

    while ((ch = fgetc(a)) != EOF)
    {
        fputc(ch, b);
    }

    fclose(a);
    fclose(b);

    printf("Done\n");
    return 0;
}
