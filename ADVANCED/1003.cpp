// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <algorithm>
#define test() freopen("in", "r", stdin)
#define INF 1 << 30
using namespace std;
// attention
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, m, c1, c2, a1, a2, b, teams[501], map[501][501], W[501], dis[501], pathnum[501];
    bool vis[501];
    cin >> n >> m >> c1 >> c2;
    for (int i = 0; i < n; i++)
        scanf("%d", &teams[i]);
    fill(map[0], map[0] + 501 * 501, INF), fill(dis, dis + 501, INF), fill(vis, vis + 501, false);
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &a1, &a2, &b);
        map[a1][a2] = map[a2][a1] = b;
    }
    dis[c1] = 0, W[c1] = teams[c1], pathnum[c1] = 1;
    while (true)
    {
        int k = -1, _min = INF;
        for (int j = 0; j < n; j++)
        {
            if (!vis[j] && dis[j] < _min)
            {
                k = j;
                _min = dis[j];
            }
        }
        if (k == -1)
            break;
        vis[k] = true;
        for (int v = 0; v < n; v++)
        {
            if (!vis[v] && map[k][v] < INF)
            {
                if (dis[k] + map[k][v] < dis[v])
                {
                    dis[v] = dis[k] + map[k][v];
                    pathnum[v] = pathnum[k];
                    W[v] = W[k] + teams[v];
                }
                else if (dis[k] + map[k][v] == dis[v])
                {
                    pathnum[v] += pathnum[k];
                    if (W[v] < W[k] + teams[v])
                        W[v] = W[k] + teams[v];
                }
            }
        }
    } //dijkstra
    printf("%d %d", pathnum[c2], W[c2]);
    return 0;
}