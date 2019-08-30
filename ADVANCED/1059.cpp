// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
vector<int64_t> isPrime(1e4, 1);
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int64_t num;
    cin >> num;
    for (int i = 2; i * i < 1e4; i++)
        for (int j = 2; j * i < 1e4; j++)
            isPrime[i * j] = 0;
    printf("%lld=", num);
    if (num == 1)
    {
        cout << 1;
        return 0;
    }
    bool first = true;
    for (int factor = 2; num > 1; factor++)
    {
        int cnt = 0, flag = 0;
        while (isPrime[factor] && num % factor == 0)
            cnt++, num /= factor, flag = 1;
        if (flag)
        {
            if (!first)
                printf("*");
            printf("%d", factor);
            first = false;
            if (cnt > 1)
                printf("^%d", cnt);
        }
    }
    return 0;
}