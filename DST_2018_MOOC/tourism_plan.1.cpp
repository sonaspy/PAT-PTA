#include<iostream>
using namespace std;
#define INF 65535
int dist[501];
int map[501][501];  /* 2城市之间的距离~ */
int cost[501][501]; /* 2城市之间的路费~ */
int MCost[501];
bool visited[501] = {false}; /* 判断该点是否已经求出最短路 */
/*  dijkstra求最短路的变种~
*/

void dijkstra(int v0, int v, int d)
{
    dist[v0] = 0;
    visited[v0] = true; /* 初始状态 v节点属于集合 */
    int i, w;
    for (i = 1; i < v; i++)
    {                  /* 开始主循环 每次求得v到某个顶点的最短路径 并加v到集合 */
        int MIN = INF; /* 当前所知离v0最近的节点 */
        for (w = 0; w < v; w++)
        {
            if (!visited[w])
            { /* 节点在 结合 V-S中 */
                if (dist[w] < MIN)
                { /* 找到最短路径节点 */
                    MIN = dist[w];
                    v0 = w;
                }
            }
        }
        visited[v0] = true;
        for (w = 0; w < v; w++)
        { /* 更新当前的最短路径 */
            if (!visited[w] && MIN + map[v0][w] < dist[w])
            {
                dist[w] = MIN + map[v0][w];
                MCost[w] = MCost[v0] + cost[v0][w];
            }
            else if (!visited[w] && MIN + map[v0][w] == dist[w] && MCost[w] > MCost[v0] + cost[v0][w])
            { /* 路径长度相等则选择价格较便宜的一条*/
                MCost[w] = MCost[v0] + cost[v0][w];
            }
        }
    }
}

int main()
{
    int v, e, s, d;
    cin >> v >> e >> s >> d;
    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
        {
            map[i][j] = map[j][i] = INF;
            cost[i][j] = cost[j][i] = INF;
        }
    for (int i = 0; i < e; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        map[a][b] = map[b][a] = c;
        cost[a][b] = cost[b][a] = d;
    }
    for (int i = 0; i < v; i++)
    {
        dist[i] = map[i][s]; /* 记录当到出发点的距离 */
        MCost[i] = cost[i][s];
    }
    dijkstra(s, v, d);
    cout << dist[d] << " " << MCost[d] << endl;
    return 0;
}