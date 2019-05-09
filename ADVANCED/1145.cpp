// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

bool isprime(int n)
{
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int msize, n, m, a, ans = 0, pos, flag, i, step;
    scanf("%d %d %d", &msize, &n, &m);
    while (!isprime(msize))
        msize++;
    vector<int> table(msize, 0);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a);
        flag = 0;
        for (step = 0; step <= msize; step++)
        {
            pos = (a + step * step) % msize;
            if (table[pos] == 0)
            {
                table[pos] = a;
                flag = 1;
                break;
            }
        }
        if (!flag)
            printf("%d cannot be inserted.\n", a);
    }
    for (i = 0; i < m; i++)
    {
        scanf("%d", &a);
        for (step = 0; step <= msize; step++)
        {
            ans++;
            pos = (a + step * step) % msize;
            if (table[pos] == a || table[pos] == 0)
                break;
        }
    }
    printf("%.1lf\n", ans * 1.0 / m);
    return 0;
} //attention