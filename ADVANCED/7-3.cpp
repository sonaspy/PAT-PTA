// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
int k, n, m, a, b, c, mp[1111][1111] = {0};
set<int> gangs;
vector<int> suspect, suscall(1111, 0), callback(1111, 0), vis(1111, 0);
void dfs(int id)
{
    for (auto i : suspect)
        if (!vis[i] && mp[id][i] && mp[i][id])
        {
            vis[id] = 1, gangs.insert(id);
            dfs(i);
        }
}
int main(int argc, char const *argv[])
{
    /* code */
    test();
    cin >> k >> n >> m;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        mp[a][b] += c;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (mp[i][j] && mp[i][j] <= 5)
            {
                suscall[i]++;
                if (mp[j][i] > 0)
                    callback[i]++;
            }
        }
        if (callback[i] <= int(0.2 * suscall[i]) && suscall[i] > k)
            suspect.push_back(i);
    }
    n = suspect.size();
    if (!n)
    {
        cout << "None";
        return 0;
    }
    sort(suspect.begin(), suspect.end());
    for (auto i : suspect)
    {
        if (!vis[i])
        {
            gangs.clear();
            vis[i] = 1;
            dfs(i);
            int first = 1;
            for (auto fraud : gangs)
            {
                if (first)
                    first = 0;
                else
                    cout << " ";
                cout << fraud;
            }
            cout << endl;
        }
    }
    return 0;
}