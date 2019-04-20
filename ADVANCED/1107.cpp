// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int n, id, hob, k, vis[1001] = {0}, cnt = 0;
vector<int> sizes, hobby[1001], MAP[1001];

inline void dfs(int v)
{
    vis[v] = 1;
    cnt++;
    for (auto k : MAP[v])
    {
        if (!vis[k])
            dfs(k);
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
            if (hobby[hob].size())
            {
                for (auto k : hobby[hob])
                {
                    MAP[k].push_back(i);
                    MAP[i].push_back(k);
                }
            }
            hobby[hob].push_back(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            cnt = 0;
            dfs(i);
            sizes.push_back(cnt);
        }
    }
    sort(sizes.begin(), sizes.end(), greater<int>());
    cout << sizes.size() << endl;
    for (int i = 0; i < sizes.size(); i++)
    {
        if (i)
            cout << " ";
        cout << sizes[i];
    }
    return 0;
}