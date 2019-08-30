// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>
using namespace std;
#define test() freopen("in", "r", stdin)

inline bool isPrime(uint64_t n)
{
    if (n < 2)
        return false;
    for (uint64_t i = 2; i <= int(sqrt(n)); i++)
        if (n % i == 0)
            return false;
    return true;
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int m, n, key, pos, step, f;
    cin >> m >> n;
    while (!isPrime(m))
        m++;
    vector<bool> table(m, false);
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
            printf(" ");
        f = 0;
        scanf("%d", &key);
        for (step = 0; step <= m; step++)
        {
            pos = (key + step * step) % m;
            if (!table[pos])
            {
                table[pos] = 1;
                printf("%d", pos);
                f = 1;
                break;
            }
        }
        if (!f) printf("-");
    }
    return 0;
}