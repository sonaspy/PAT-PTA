// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
int main(int argc, char const *argv[])
{
    /* code */
    int n;
    long long int ans, length = 10;
    scanf("%d", &n);
    while (--length)
    {
        for (int lo = 2; lo <= sqrt(n); lo++)
        {
            ans = 1;
            for (int i = lo; i < lo + length; i++)
                ans *= i;
            if (n % ans == 0)
            {
                printf("%d\n%d", length, lo);
                for (int i = lo + 1; i < lo + length; i++)
                    printf("*%d", i);
                exit(0);
            }
        }
    }
    printf("1\n%d", n);
    return 0;
}