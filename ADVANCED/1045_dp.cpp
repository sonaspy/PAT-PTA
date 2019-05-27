// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)
using namespace std;
vector<int> strip, dp(11111, 1), colorRank(222, 0);
int n, m, l, x, res = 0, i, j;
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
            strip.push_back(x);
    }
    for (i = 0; i < strip.size(); ++i)
    {
        for (j = 0; j < i; ++j)
            if (colorRank[strip[j]] <= colorRank[strip[i]])
                dp[i] = max(dp[i], dp[j] + 1);
        res = max(res, dp[i]);
    }
    cout << res;
    return 0;
} //attention