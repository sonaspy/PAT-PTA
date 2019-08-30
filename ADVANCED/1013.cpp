// author - sonaspy@outlook.com
// coding - utf_8
#include <iostream>
#include <vector>
#define test() freopen("in", "r", stdin)

using namespace std;
int n, m, k, a, b, vis[1001];
vector<int> map[1001];
void dfs(int v)
{
    vis[v] = 1;
    for (auto i : map[v])
        if (!vis[i])
            dfs(i);
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &a, &b);
        map[a].push_back(b), map[b].push_back(a);
    }
    for (int i = 0; i < k; i++)
    {
        fill(vis, vis + 1001, 0);
        int cknow, cnt = 0;
        cin >> cknow;
        vis[cknow] = true;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j])
            {
                dfs(j);
                cnt++;
            }
        }
        printf("%d\n", cnt - 1);
    }
    return 0;
}