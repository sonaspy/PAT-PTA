// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
int main(int argc, char const *argv[])
{
    /* code */
    int n;
    long long int ans;
    scanf("%d", &n);
    int _number = sqrt(n);
    for (int length = 13; length > 0; length--)
    {
        for (int start = 2; start <= _number; start++)
        {
            ans = 1;
            for (int i = start; i < start + length; i++)
                ans *= i;
            if (n % ans == 0)
            {
                printf("%d\n%d", length, start);
                for (int i = start + 1; i < start + length; i++)
                    printf("*%d", i);
                return 0;
            }
        }
    }
    printf("1\n%d", n);
    return 0;
} //attention