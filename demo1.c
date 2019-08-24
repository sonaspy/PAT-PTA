#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int fun(int x)
{
    int countx = 0;
    while (x)
    {
        countx++;
        x = x & (x - 1);
    }
    return countx;
}
int sub_count(char *s, char *sub)
{
    char *p2 = sub, *p1;
    int sum = 0;
    while (*s)
    {
        p1 = s, p2 = sub;
        while (*p1 == *p2 && *p1 && *p2)
        {
            p1++;
            p2++;
        }
        if (*p2 == '\0')
            sum++;
        s++;
    }
    return sum;
}
int main(int argc, char const *argv[])
{
    /* code */
    char *s = "sadsadsadssssad", *ss = "sad";
    printf("%d", sub_count(s, ss));
    return 0;
}