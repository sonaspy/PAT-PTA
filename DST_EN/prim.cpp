// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)
#define MAX_V (1001)
#define NON_EXIST (1 << 30)
#define COLLECTED (-88)
using namespace std;
int n, m, MAP[MAX_V][MAX_V], a1, a2, a3, a4, union_v[MAX_V];
inline int root_get(int a)
{
    if (union_v[a] == -1)
        return a;
    return union_v[a] = root_get(union_v[a]);
}

inline bool Union(int a, int b)
{
    int ra = root_get(a), rb = root_get(b);
    if (ra == rb)
        return false;
    union_v[rb] = ra;
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
struct MST
{
    int sum_w = 0, root;
    vector<Edge> edges;
    unordered_set<int> nodes;
} mst;

priority_queue<Edge, vector<Edge>> pq;

inline void isThereASpaningTree()
{
    if (mst.nodes.size() < n)
    {
        cout << "Impossible";
        exit(0);
    }
}
inline void Kruskal()
{
    while (pq.size() && mst.edges.size() < n - 1)
    {
        Edge tmp = pq.top();
        pq.pop();
        if (Union(tmp.v1, tmp.v2))
        {
            mst.sum_w += tmp.w;
            mst.edges.push_back(tmp);
            mst.nodes.insert(tmp.v1);
            mst.nodes.insert(tmp.v2);
        }
    }
    isThereASpaningTree();
}

inline void Prim(int src)
{
    int dist[MAX_V], last = -1, pre[MAX_V];
    fill(dist, dist + MAX_V, NON_EXIST);
    fill(pre, pre + MAX_V, -1);
    dist[src] = 0;
    while (true)
    {
        int k = -1, min_ = NON_EXIST;
        for (int i = 1; i <= n; i++)
        {
            if (dist[i] != COLLECTED && dist[i] < min_)
            {
                k = i;
                min_ = dist[i];
            }
        }
        if (k == -1)
            break;
        mst.sum_w += dist[k];
        mst.nodes.insert(k);
        if (pre[k] != -1)
            mst.edges.push_back(Edge(pre[k], k, dist[k]));
        dist[k] = COLLECTED;
        for (int i = 1; i <= n; i++)
        {
            if (dist[i] != COLLECTED && MAP[k][i] < dist[i])
            {
                dist[i] = MAP[k][i];
                pre[i] = k;
            }
        }
    }
    isThereASpaningTree();
}

int main(int argc, char const *argv[])
{
    /* code */
    test();
    cin >> n;
    fill(*MAP, *MAP + MAX_V * MAX_V, NON_EXIST);
    fill(union_v, union_v + MAX_V, -1);
    for (int i = 0; i < (n * (n - 1)) / 2; i++)
    {
        cin >> a1 >> a2 >> a3 >> a4;
        if (a4 == 1)
            a3 = 0;
        pq.push(Edge(a1, a2, a3));
        MAP[a1][a2] = a3;
        MAP[a2][a1] = a3;
    }
    Prim(1);
    //Prim(1);
    for (auto i : mst.edges)
    {
        cout << i.v1 << " -> " << i.v2 << " = " << i.w << endl;
    }
    cout << mst.sum_w;
    return 0;
}