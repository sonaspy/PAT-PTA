// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)
#define INF_MAX (1 << 30)
using namespace std;
struct node
{
    int l = INF_MAX, t = INF_MAX;
} mp[501][501];
int src, dst, n, m, i, v1, v2, onew, l, t, vis[501], dis[501], times[501], w2nd[501];
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

inline void dij4dis()
{
    fill(dis, dis + 501, INF_MAX);
    fill(vis, vis + 501, 0);
    fill(pre.begin(), pre.end(), -1);
    pre.clear();
    dis[src] = 0;
    w2nd[src] = 0;
    while (true)
    {
        int v = -1, min_ = INF_MAX;
        for (i = 0; i < n; i++)
        {
            if (!vis[i] && dis[i] < min_)
            {
                min_ = dis[i];
                v = i;
            }
        }
        if (v == -1)
            break;
        vis[v] = 1;
        for (i = 0; i < n; i++)
        {
            if (!vis[i] && mp[v][i].l != INF_MAX)
            {
                if (dis[v] + mp[v][i].l < dis[i])
                {
                    dis[i] = dis[v] + mp[v][i].l;
                    w2nd[i] = w2nd[v] + mp[v][i].t;
                    pre[i] = (v);
                }
                else if (dis[v] + mp[v][i].l == dis[i] && w2nd[v] + mp[v][i].t < w2nd[i])
                {
                    w2nd[i] = w2nd[v] + mp[v][i].t;
                    pre[i] = (v);
                }
            }
        }
    }
}

inline void dij4time()
{
    fill(times, times + 501, INF_MAX);
    fill(pre.begin(), pre.end(), -1);
    fill(vis, vis + 501, 0);
    pre.clear();
    times[src] = 0;
    while (true)
    {
        int v = -1, min_ = INF_MAX;
        for (i = 0; i < n; i++)
        {
            if (!vis[i] && times[i] < min_)
            {
                min_ = times[i];
                v = i;
            }
        }
        if (v == -1)
            break;
        vis[v] = 1;
        for (i = 0; i < n; i++)
        {
            if (!vis[i] && mp[v][i].t != INF_MAX)
            {
                if (times[v] + mp[v][i].t < times[i])
                {
                    times[i] = times[v] + mp[v][i].t;
                    w2nd[i] = w2nd[v] + 1;
                    pre[i] = v;
                }
                else if (times[v] + mp[v][i].t == times[i] && w2nd[v] + 1 < w2nd[i])
                {
                    pre[i] = v;
                    w2nd[i] = w2nd[v] + 1;
                }
            }
        }
    }
}
inline void output(deque<int> &dq)
{
    i = 0;
    for (auto j : dq)
    {
        if (i != 0) printf(" -> ");
        else i = 1;
        printf("%d", j);
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
        if (!onew) mp[v2][v1].l = l, mp[v2][v1].t = t;
        mp[v1][v2].l = l, mp[v1][v2].t = t;
    }
    cin >> src >> dst;
    dij4dis(), findPath(res_l), dij4time(), findPath(res_t);
    if (res_t == res_l)
    {
        printf("Distance = %d; Time = %d: ", dis[dst], times[dst]);
        output(res_t);
    }
    else
    {
        printf("Distance = %d: ", dis[dst]);
        output(res_l);
        printf("\nTime = %d: ", times[dst]);
        output(res_t);
    }
    return 0;
}