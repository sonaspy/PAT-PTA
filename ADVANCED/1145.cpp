// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
#define EMPTY 0
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
    int msize, n, search_n, key, ssl = 0, pos, flag, i, step;
    scanf("%d %d %d", &msize, &n, &search_n);
    while (!isprime(msize))
        msize++;
    vector<int> table(msize, 0);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &key);
        flag = 0;
        for (step = 0; step <= msize; step++)
        {
            pos = (key + step * step) % msize;
            if (table[pos] == EMPTY)
            {
                table[pos] = key;
                flag = 1;
                break;
            }
        }
        if (!flag)
            printf("%d cannot be inserted.\n", key);
    }
    for (i = 0; i < search_n; i++)
    {
        scanf("%d", &key);
        for (step = 0; step <= msize; step++)
        {
            ssl++;
            pos = (key + step * step) % msize;
            if (table[pos] == key || table[pos] == EMPTY)
                break;
        }
    }
    printf("%.1lf\n", ssl * 1.0 / search_n);
    return 0;
}