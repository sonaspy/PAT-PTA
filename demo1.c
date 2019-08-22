#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    /* code */
    int m;
    char ss[10] = "12345", *s = ss;
    for (m = 10; m != 0; m--)
        ;
    printf("%d", m);
    while (*s++)
        putchar(*++s);

    return 0;
}
