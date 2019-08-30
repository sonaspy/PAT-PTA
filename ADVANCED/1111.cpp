// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)
#define INF (1 << 30)
using namespace std;
struct node
{
    int l = INF, t = INF;
} MAP[501][501];
int src, dst, n, m, i, v1, v2, onew, l, t, vis[501], dis[501], times[501], min_time = INF, tmp_time = 0, assist_a[501];
vector<int> pre(501);
deque<int> res_t, res_l;

inline void findPath(deque<int> &path)
{
    int walk = dst;
    while (walk != src)
    {
        path.push_front(walk);
        walk = pre[walk];
    }
    path.push_front(walk);
}

inline void dij1()
{
    fill(dis, dis + 501, INF);
    fill(vis, vis + 501, 0);
    fill(pre.begin(), pre.end(), -1);
    pre.clear();
    dis[src] = 0;
    assist_a[src] = 0;
    while (true)
    {
        int k = -1, min_ = INF;
        for (i = 0; i < n; i++)
        {
            if (!vis[i] && dis[i] < min_)
            {
                min_ = dis[i];
                k = i;
            }
        }
        if (k == -1)
            break;
        vis[k] = 1;
        for (i = 0; i < n; i++)
        {
            if (!vis[i] && MAP[k][i].l != INF)
            {
                if (dis[k] + MAP[k][i].l < dis[i])
                {
                    dis[i] = dis[k] + MAP[k][i].l;
                    assist_a[i] = assist_a[k] + MAP[k][i].t;
                    pre[i] = (k);
                }
                else if (dis[k] + MAP[k][i].l == dis[i] && assist_a[k] + MAP[k][i].t < assist_a[i])
                {
                    assist_a[i] = assist_a[k] + MAP[k][i].t;
                    pre[i] = (k);
                }
            }
        }
    }
}

inline void dij2()
{
    fill(times, times + 501, INF);
    fill(pre.begin(), pre.end(), -1);
    fill(vis, vis + 501, 0);
    pre.clear();
    times[src] = 0;
    while (true)
    {
        int k = -1, min_ = INF;
        for (i = 0; i < n; i++)
        {
            if (!vis[i] && times[i] < min_)
            {
                min_ = times[i];
                k = i;
            }
        }
        if (k == -1)
            break;
        vis[k] = 1;
        for (i = 0; i < n; i++)
        {
            if (!vis[i] && MAP[k][i].t != INF)
            {
                if (times[k] + MAP[k][i].t < times[i])
                {
                    times[i] = times[k] + MAP[k][i].t;
                    assist_a[i] = assist_a[k] + 1;
                    pre[i] = k;
                }
                else if (times[k] + MAP[k][i].t == times[i] && assist_a[k] + 1 < assist_a[i])
                {
                    pre[i] = k;
                    assist_a[i] = assist_a[k] + 1;
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cin >> n >> m;
    for (i = 0; i < m; i++)
    {
        scanf("%d%d%d%d%d", &v1, &v2, &onew, &l, &t);
        if (!onew)
            MAP[v2][v1].l = l, MAP[v2][v1].t = t;
        MAP[v1][v2].l = l, MAP[v1][v2].t = t;
    }
    cin >> src >> dst;
    dij1();
    findPath(res_l);
    dij2();
    findPath(res_t);
    if (res_t == res_l)
    {
        printf("Distance = %d; Time = %d: ", dis[dst], times[dst]);
        i = 0;
        for (auto j : res_t)
        {
            if (i != 0)
                printf(" -> ");
            else
                i = 1;
            printf("%d", j);
        }
    }
    else
    {
        printf("Distance = %d: ", dis[dst]);
        i = 0;
        for (auto j : res_l)
        {
            if (i != 0)
                printf(" -> ");
            else
                i = 1;
            printf("%d", j);
        }
        printf("\nTime = %d: ", times[dst]);
        i = 0;
        for (auto j : res_t)
        {
            if (i != 0)
                printf(" -> ");
            else
                i = 1;
            printf("%d", j);
        }
    }
    return 0;
}