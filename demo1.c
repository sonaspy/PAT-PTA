#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    /* code */
    int (*pa)[10];
    int a[10][10];
    pa = a + 1;
    int i = pa[1][1];
    return 0;
}
