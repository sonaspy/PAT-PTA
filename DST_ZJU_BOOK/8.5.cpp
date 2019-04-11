// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)
#define MAX_V (1001)
#define NON_EXIST (1 << 30)
using namespace std;
int n, m, MAP[MAX_V][MAX_V], a1, a2, a3, a4, sum_w = 0, cnt, union_my[MAX_V];
inline int root_get(int a)
{
    if (union_my[a] == -1)
        return a;
    return union_my[a] = root_get(union_my[a]);
}

inline bool Union(int a, int b)
{
    int ra = root_get(a), rb = root_get(b);
    if (ra == rb)
        return false;
    union_my[rb] = ra;
    return true;
};
struct Edge
{
    int v1, v2, w;
    Edge(int v1, int v2, int w) : v1(v1), v2(v2), w(w) {}
    bool operator<(const Edge &b) const
    {
        return w > b.w;
    }
};
priority_queue<Edge, vector<Edge>> pq;

inline void Kruskal()
{
    fill(union_my, union_my + MAX_V, -1);
    cnt = 0;
    while (pq.size() && cnt < n - 1)
    {
        Edge tmp = pq.top();
        pq.pop();
        if (Union(tmp.v1, tmp.v2))
        {
            sum_w += tmp.w;
            cnt++;
        }
    }
    if (cnt < n - 1)
    {
        cout << "Impossible";
        exit(0);
    }
}

inline void Prim(int src)
{
    int dist[MAX_V];
    fill(dist, dist + MAX_V, NON_EXIST);
    dist[src] = 0;
    cnt = 0;
    while (true)
    {
        int k = -1, min_ = NON_EXIST;
        for (int i = 1; i <= n; i++)
        {
            if (dist[i] != -1 && dist[i] < min_)
            {
                k = i;
                min_ = dist[i];
            }
        }
        if (k == -1)
            break;
        sum_w += dist[k];
        dist[k] = -1;
        cnt++;
        for (int i = 1; i <= n; i++)
        {
            if (dist[i] != -1 && dist[i] > MAP[k][i])
                dist[i] = MAP[k][i];
        }
    }
    if (cnt < n)
    {
        cout << "Impossible";
        exit(0);
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cin >> n;
    fill(*MAP, *MAP + MAX_V * MAX_V, NON_EXIST);
    for (int i = 0; i < (n * (n - 1)) / 2; i++)
    {
        cin >> a1 >> a2 >> a3 >> a4;
        if (a4 == 1)
            a3 = 0;
        //pq.push(Edge(a1, a2, a3));
        MAP[a1][a2] = a3;
        MAP[a2][a1] = a3;
    }
    Prim(1);
    cout << sum_w;
    return 0;
}