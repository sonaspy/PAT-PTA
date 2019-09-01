// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)
using namespace std;
vector<int> strip, f(11111, 1), colorRank(222, 0);
int n, m, l, x, res = 0, i, k;
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
    for (i = 1; i < strip.size(); ++i)
    {
        for (k = 0; k < i; ++k)
            if (colorRank[strip[k]] <= colorRank[strip[i]])
                f[i] = max(f[i], f[k] + 1);
    }
    cout << *max_element(f.begin(), f.end());
    return 0;
} //attention dp