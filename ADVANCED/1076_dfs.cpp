// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
int n, level, num, k, tmp, vis[1010], sum_f;
vector<int> BUCKET[1010];
inline void solve(int lel, int src)
{
    vis[src] = 1;
    if (lel + 1 < level)
        for (auto ip : BUCKET[src])
            solve(lel + 1, ip);
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cin >> n >> level;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &num);
        for (int j = 0; j < num; j++)
        {
            scanf("%d", &tmp);
            BUCKET[tmp].push_back(i);
        }
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &tmp);
        fill(vis, vis + 1010, 0);
        solve(-1, tmp);
        cout << count(vis + 1, vis + n + 1, 1) - 1 << endl;
    }
    return 0;
}