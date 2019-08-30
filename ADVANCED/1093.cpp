// author -sonaspy@outlook.com
// coding - utf_8

#include <stdio.h>

#define test() freopen("in", "r", stdin)
#define MOD 1000000007
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    char s[100001], c;
    int len = 0, i, result = 0, cnt_t = 0, cnt_p = 0;
    while ((c = getchar()) != EOF)
        s[len++] = c;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == 'T')
            cnt_t++;
    }
    for (int i = 0; i < len; i++)
    {
        if (s[i] == 'P')
            cnt_p++;
        else if (s[i] == 'T')
            cnt_t--;
        else if (s[i] == 'A')
            result = (result + cnt_p * cnt_t) % MOD;
    }
    printf("%d", result);
    return 0;
}