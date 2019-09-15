// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)
#define MAX_V (666)
#define NON_EXIST (1 << 30)
using namespace std;
int MAP[MAX_V][MAX_V];
const int n = 6;
int union_my[MAX_V];
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

struct MST
{
    vector<Edge> edges;
} mst;

void Kruskal()
{
    int sum_w = 0;
    while (pq.size() && mst.edges.size() < n - 1)
    {
        Edge tmp = pq.top();
        pq.pop();
        if (Union(tmp.v1, tmp.v2))
        {
            mst.edges.push_back(tmp);
            sum_w += tmp.w;
        }
    }
    if(mst.edges.size() < n-1) cout << "error";
    cout << sum_w;
}

void ReadEdge()
{
    for (int i = 0; i < MAX_V; i++)
        for (int j = i; j < MAX_V; j++)
        {
            if (MAP[i][j] < NON_EXIST)
            {
                pq.push(Edge(i, j, MAP[i][j]));
            }
        }
}

int main(int argc, char const *argv[])
{
    /* code */
    test();
    int a1, a2, a3;
    fill(union_my, union_my + MAX_V, -1);
    fill(*MAP, *MAP + MAX_V * MAX_V, NON_EXIST);
    for (int i = 0; i < 11; i++)
    {
        cin >> a1 >> a2 >> a3;
        a1--, a2--;
        if (a3 > 10)
            a3 /= 10;
        MAP[a1][a2] = a3;
        MAP[a2][a1] = a3;
    }
    ReadEdge();
    Kruskal();
    return 0;
}