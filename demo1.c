#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main(int argc, char const *argv[])
{
    /* code */
    int count;
    char ch1, ch2;
    FILE *f1, *f2;
    if ((f1 = fopen("a.txt", "r")) == NULL)
    {
        printf("Can't open file : %s\n", "a.txt");
        exit(0);
    }
    if ((f2 = fopen("b.txt", "r")) == NULL)
    {
        printf("Can't open file : %s\n", "b.txt");
        exit(0);
    }
    count = 0;
    while (!feof(f1) || !feof(f2))
    {
        ch1 = fgetc(f1);
        ch2 = fgetc(f2);
        if (ch1 != ch2)
        {
            printf("%c#%c#", ch1, ch2);
            printf("%d#", count);
            break;
        }
        if (ch1 == '?')
            count++;
    }
    fclose(f1);
    fclose(f2);
    return 0;
}
