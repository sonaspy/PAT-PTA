// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <algorithm>
#define test() freopen("in", "r", stdin)
#define INF 9999999
using namespace std;
// attention
int main(int argc, char const *argv[])
{
    /* code */
    test();
    int n, m, c1, c2, a1, a2, b, teams[501], map[501][501], w[501], dis[501], num[501];
    bool vis[501];
    cin >> n >> m >> c1 >> c2;
    for (int i = 0; i < n; i++)
        scanf("%d", &teams[i]);
    fill(map[0], map[0] + 501 * 501, INF);
    fill(dis, dis + 501, INF);
    fill(vis, vis + 501, false);
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &a1, &a2, &b);
        map[a1][a2] = b;
        map[a2][a1] = b;
    }
    dis[c1] = 0, w[c1] = teams[c1], num[c1] = 1;
    for (int i = 0; i < n; i++)
    {
        int u = -1, _min = INF;
        for (int j = 0; j < n; j++)
        {
            if (!vis[j] && dis[j] < _min){
                u = j;
                _min = dis[j];
            }
        }
        if(u == -1) break;
        vis[u] = true;
        for(int v = 0; v < n; v++){
            if(!vis[v] && map[u][v] < INF){
                if(dis[u] + map[u][v] < dis[v]){
                    dis[v] = dis[u] + map[u][v];
                    num[v] = num[u];
                    w[v] = w[u] + teams[v];
                }
                else if (dis[u] + map[u][v] == dis[v]){
                    num[v] += num[u];
                    if (w[v] < w[u] + teams[v])
                        w[v] = w[u] + teams[v];
                }
            }
        }
    }//dijkstra
    printf("%d %d", num[c2], w[c2]);
    return 0;
}