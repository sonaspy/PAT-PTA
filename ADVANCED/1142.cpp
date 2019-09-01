// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
int n, m, k, p;
vector<int> mp[250];
int check[205], vis[205], val[205];
int main()
{
    cin >> n >> m;
    int x, y;
    for (int i = 0; i < m; ++i)
    {
        cin >> x >> y;
        mp[x].push_back(y), mp[y].push_back(x);
    }
    cin >> k;
    while (k--)
    {
        cin >> p;
        fill(vis, vis + n + 1, 0);
        for (int i = 0; i < p; i++)
        {
            cin >> check[i];
            for (auto j : mp[check[i]])
                vis[j]++;
        }
        bool flag = true;
        for (int i = 0; i < p; i++)
        {
            if (vis[check[i]] != p - 1)
            {
                flag = false;
                break;
            }
        }
        if (!flag)
        {
            printf("Not a Clique\n");
            continue;
        }
        int no = count_if(vis + 1, vis + n + 1, [](int &c) { return c == p; });
        (no) ? printf("Not Maximal\n") : printf("Yes\n");
    }
    return 0;
}