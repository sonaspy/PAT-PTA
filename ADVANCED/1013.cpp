// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#define test() freopen("in", "r", stdin)

using namespace std;
int n, m, k, a, b;
int map[1001][1001], vis[1001];
void dfs(int v)
{
    vis[v] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i] && map[v][i])
            dfs(i);
    }
}
int main(int argc, char const *argv[])
{
    /* code */
    //test(); attention
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &a, &b);
        map[a][b] = 1, map[b][a] = 1;
    }
    for (int i = 0; i < k; i++)
    {
        fill(vis, vis + 1001, 0);
        int check, cnt = 0;
        cin >> check;
        vis[check] = true;
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