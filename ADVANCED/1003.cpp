// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <algorithm>
#define test() freopen("in", "r", stdin)
#define INF 1 << 30
using namespace std;
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, m, c1, c2, a1, a2, b, team[501], map[501][501], sOfTeam[501], dis[501], nOfPath[501];
    bool vis[501];
    cin >> n >> m >> c1 >> c2;
    for (int i = 0; i < n; i++)
        scanf("%d", &team[i]);
    fill(map[0], map[0] + 501 * 501, INF), fill(dis, dis + 501, INF), fill(vis, vis + 501, false);
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &a1, &a2, &b);
        map[a1][a2] = map[a2][a1] = b;
    }
    dis[c1] = 0, sOfTeam[c1] = team[c1], nOfPath[c1] = 1;
    while (true)
    {
        int v = -1, _min = INF;
        for (int j = 0; j < n; j++)
        {
            if (!vis[j] && dis[j] < _min)
            {
                v = j;
                _min = dis[j];
            }
        }
        if (v == -1)
            break;
        vis[v] = true;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i] && map[v][i] < INF)
            {
                if (dis[v] + map[v][i] < dis[i])
                {
                    dis[i] = dis[v] + map[v][i];
                    nOfPath[i] = nOfPath[v];
                    sOfTeam[i] = sOfTeam[v] + team[i];
                }
                else if (dis[v] + map[v][i] == dis[i])
                {
                    nOfPath[i] += nOfPath[v];
                    if (sOfTeam[i] < sOfTeam[v] + team[i])
                        sOfTeam[i] = sOfTeam[v] + team[i];
                }
            }
        }
    } //dijkstra
    printf("%d %d", nOfPath[c2], sOfTeam[c2]);
    return 0;
}