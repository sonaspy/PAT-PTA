#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    /* code */
    FILE *fpin, *fpout;
    int x;
    if ((fpin = fopen("input.txt", "r")) == NULL)
    {
        printf("Can't open file input.txt\n");
        exit(0);
    }
    if ((fpout = fopen("output.txt", "w")) == NULL)
    {
        printf("Can't creat file output.txt");
        exit(0);
    }
    fclose(fpin);
    return 0;
}
