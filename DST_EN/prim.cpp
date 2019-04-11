// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)
#define MAX_V (1 << 10)
#define NON_EXIST (1 << 30)
using namespace std;
struct MST
{
    vector<int> nodes;
    int Parent[MAX_V];
    MST()
    {
        fill(Parent, Parent + MAX_V, -1);
    }
} m_sp_tree;
int MAP[MAX_V][MAX_V];
inline bool Prim(int src)
{
    int dist[MAX_V];
    fill(dist, dist + MAX_V, NON_EXIST);
    dist[src] = 0;
    int sum_w = 0;
    while (true)
    {
        int k = -1, min_ = NON_EXIST;
        for (int i = 0; i < 6; i++)
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
        m_sp_tree.nodes.push_back(k);
        for (int i = 0; i < 6; i++)
        {
            if (dist[i] != -1 && dist[i] > MAP[k][i])
            {
                dist[i] = MAP[k][i];
                m_sp_tree.Parent[i] = k;
            }
        }
    }
    if (m_sp_tree.nodes.size() < 6)
        return false;
    return true;
}

int main(int argc, char const *argv[])
{
    /* code */
    test();
    int a1, a2, a3;
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
    Prim(1);
    return 0;
}