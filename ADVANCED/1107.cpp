// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int n, id, hob, k, vis[1001] = {0}, cnt = 0;
vector<int> cluster, hobby[1001], MAP[1001];

inline void dfs(int v)
{
    for (auto k : MAP[v])
    {
        if (!vis[k])
        {
            vis[k] = 1;
            cnt++;
            dfs(k);
        }
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d:", &k);
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &hob);
            for (auto &k : hobby[hob])
                MAP[k].push_back(i), MAP[i].push_back(k);
            hobby[hob].push_back(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            cnt = 1, vis[i] = 1;
            dfs(i);
            cluster.push_back(cnt);
        }
    }
    sort(cluster.begin(), cluster.end(), greater<int>());
    cout << cluster.size() << endl;
    for (int i = 0; i < cluster.size(); i++)
    {
        if (i) cout << " ";
        cout << cluster[i];
    }
    return 0;
}