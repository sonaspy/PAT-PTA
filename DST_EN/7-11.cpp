#include <bits/stdc++.h>
#include <cmath>

#define mem(a, b) memset(a, b, sizeof a)
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 320;

struct node
{
    int x, y;
} nds[maxn];

int n, len;
double D;
int vis[maxn], dis[maxn], pre[maxn], fst[maxn];
int g[maxn][maxn];

inline double fdis(node a, node b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
void dijkstra(int s)
{
    dis[s] = 0;
    while (1)
        {
            int mi = INF;
            s = -1;
            for (int i = 0; i < len; i++)
                if (!vis[i] && mi > dis[i])
                    mi = dis[i], s = i;
            if (s == -1)
                return;
            vis[s] = 1;
            for (int i = 0; i < len; i++)
                if (!vis[i] && mi + g[s][i] < dis[i])
                    {
                        dis[i] = mi + g[s][i], pre[i] = s;
                        if (s != 0)
                            fst[i] = fst[s];
                    }
                else if (!vis[i] && mi + g[s][i] == dis[i] && fst[i] > fst[s])
                    pre[i] = s, fst[i] = fst[s];
        }
}

int main()
{
    scanf("%d%lf", &n, &D);
    n++;
    nds[0].y = nds[0].x = 0;
    for (int i = 1; i < n; i++)
        scanf("%d%d", &nds[i].x, &nds[i].y);
    if (D + 7.5 >= 50)
        {
            puts("1");
            return 0;
        }
    len = n;
    for (int i = 1; i < n; i++)
        if (50 - abs(nds[i].x) <= D)
            nds[len].x = nds[i].x >= 0 ? 50 : -50, nds[len++].y = nds[i].y;
        else if (50 - abs(nds[i].y) <= D)
            nds[len].y = nds[i].y >= 0 ? 50 : -50, nds[len++].x = nds[i].x;
    mem(g, INF), mem(vis, 0), mem(dis, INF), mem(pre, -1), mem(fst, INF);
    double diff;
    for (int i = 1; i < len; i++)
        {
            if ((diff = fdis(nds[0], nds[i]) - 7.5) <= D)
                g[i][0] = g[0][i] = 1, fst[i] = diff;
            for (int j = 1; j < len; j++)
                if (i != j && fdis(nds[i], nds[j]) <= D)
                    g[i][j] = g[j][i] = 1;
        }
    dijkstra(0);
    int mi = INF, h = -1;
    for (int i = n; i < len; i++)
        if (mi > dis[i] || mi == dis[i] && h != -1 && fst[h] > fst[i])
            mi = dis[i], h = i;
    if (mi != INF)
        {
            printf("%d\n", mi);
            vector<int> vec;
            while (h != -1)
                {
                    vec.push_back(h);
                    h = pre[h];
                }
            for (int i = vec.size() - 2; i > 0; i--)
                printf("%d %d\n", nds[vec[i]].x, nds[vec[i]].y);
        }
    else
        puts("0");
    return 0;
}
