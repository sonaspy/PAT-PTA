// author -sonaspy@outlook.com
// coding - utf_8

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int *f(int *p)
{
    return p;
}
int main(int argc, char const *argv[])
{
    /* code */
    int i;
    scanf("%d", &i);
    i %= 4;
    printf("%d", i);
    return 0;
}