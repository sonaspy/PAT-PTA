#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
static char sub[20];
char *cut(char *ss, int m, int n)
{
    int i;
    for (i = 0; i < n; i++)
        sub[i] = ss[m + i];
    sub[i] = '\0';
    return sub;
}
int main(int argc, char const *argv[])
{
    /* code */
    static char s[] = "goodmorning";
    char *p = cut(s, 3, 4);
    printf("%s\n", p);
    return 0;
}