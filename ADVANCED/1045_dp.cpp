// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)
using namespace std;
int strip[11111], dp[11111], colorRank[222];
int n, m, l, c = 0, x, res = 0, i, j;
int main()
{
    cin >> n >> m;
    for (i = 0; i < m; ++i)
    {
        scanf("%d", &x);
        colorRank[x] = i + 1;
    }
    cin >> l;
    for (i = 0; i < l; ++i)
    {
        scanf("%d", &x);
        if (colorRank[x])
            strip[c++] = x;
    }
    for (i = 0; i < c; ++i)
    {
        dp[i] = 1;
        for (j = 0; j < i; ++j)
            if (colorRank[strip[j]] <= colorRank[strip[i]])
                dp[i] = max(dp[i], dp[j] + 1);
        res = max(res, dp[i]);
    }
    cout << res;
    return 0;
} //attention