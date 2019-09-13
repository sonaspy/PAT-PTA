// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>
#include "set_union.h"
using namespace std;

#ifndef __NEW_GRAPH__
#define __NEW_GRAPH__

namespace newgraph
{
#define MAXVSIZE 1111
#define INF_VAL 1 << 30
struct edge
{
    int w1, w2, w3, v1, v2;
    edge(int w1) : w1(w1), w2(INF_VAL), w3(INF_VAL), v1(-1), v2(-1) {}
    edge(int v1, int v2) : w1(INF_VAL), w2(INF_VAL), w3(INF_VAL), v1(v1), v2(v2) {}
    edge(int w1, int v1, int v2) : w1(w1), w2(INF_VAL), w3(INF_VAL), v1(v1), v2(v2) {}
};
struct __cmp1
{
    bool operator()(const edge *e1, const edge *e2) const { return e1->w1 > e1->w1; }
};
class udGraph
{
protected:
    int nv, connected_cnt, ev;
    unordered_set<edge *> memTable;
    unordered_set<int> adjTable[MAXVSIZE];
    vector<vector<edge *>> adjMatrix;
    vector<int> indeg, outdeg, vis, w1, w2;
    priority_queue<edge *, vector<edge *>, __cmp1> e_pq;
    spanningTree spt;
    void __clearArray()
    {
        fill(vis.begin(), vis.end(), 0);
        fill(w1.begin(), w1.end(), 0);
        fill(w2.begin(), w2.end(), 0);
    }
    void __prim(int v0)
    {
        int i, j, v, lowcost[nv], min_;
        for (i = 0; i < nv; i++)
            lowcost[i] = (adjMatrix[v0][i]) ? adjMatrix[v0][i]->w1 : INF_VAL;
        spt.pushv(v0);
        while (1)
        {
            v = -1, min_ = INF_VAL;
            for (i = 0; i < nv; i++)
            {
                if (!spt.exist(i) && lowcost[i] < min_)
                    v = i, min_ = lowcost[i];
            }
            if (v == -1)
                break;
            spt.pushv(v);
            spt.addsum(min_);
            for (j = 0; j < nv; j++)
                if (!spt.exist(j) && adjMatrix[v][j] && adjMatrix[v][j]->w1 < lowcost[j])
                    lowcost[j] = adjMatrix[v][j]->w1;
        }
    }
    void __kruskal()
    {
        edge *e;
        int v1, v2;
        while (e_pq.size())
        {
            e = e_pq.top(), e_pq.pop();
            v1 = e->v1, v2 = e->v1;
            if (spt.overlap(v1, v2))
                continue;
            spt.unite(v1, v2);
            spt.addsum(e->w1);
            spt.pushe(e);
            spt.pushv(v1), spt.pushv(v2);
        }
    }

    void __dfs(int v_id)
    {
        for (auto w : adjTable[v_id])
            if (!vis[w])
            {
                vis[w] = 1;
                __dfs(w);
            }
    }

public:
    udGraph()
    {
        adjMatrix = vector<vector<edge *>>(MAXVSIZE, vector<edge *>(MAXVSIZE, nullptr));
        w1 = w2 = vis = indeg = outdeg = vector<int>(MAXVSIZE, 0);
        nv = ev = connected_cnt = 0;
    }
    inline int connected_component()
    {
        if (connected_cnt)
            return connected_cnt;
        int cnt = 0;
        fill(vis.begin(), vis.end(), 0);
        for (int i = 0; i < nv; i++)
        {
            if (!vis[i])
            {
                vis[i] = 1;
                __dfs(i);
                cnt++;
            }
        }
        connected_cnt = cnt;
        return cnt;
    }
    inline bool hasPath(int v1, int v2)
    {
        fill(vis.begin(), vis.end(), 0);
        vis[v1] = 1;
        __dfs(v1);
        return vis[v2];
    }
    inline bool connected()
    {
        if (connected_cnt)
            return connected_cnt == 1;
        connected_component();
        return connected_cnt == 1;
    }
    void readData(vector<vector<int>> &g)
    {
        int n = g.size();
        this->nv = n;
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
                if (g[i][j] != INF_VAL)
                {
                    adjMatrix[j][i] = adjMatrix[i][j] = new edge(g[i][j], i, j);
                    adjTable[i].insert(j), adjTable[j].insert(i);
                    e_pq.push(adjMatrix[i][j]);
                    memTable.insert(adjMatrix[i][j]);
                }
    }
};

class dGraph : public udGraph
{

public:
    dGraph()
    {
        adjMatrix = vector<vector<edge *>>(MAXVSIZE, vector<edge *>(MAXVSIZE, nullptr));
        w1 = w2 = vis = indeg = outdeg = vector<int>(MAXVSIZE, 0);
    }
    void readData(vector<vector<int>> &g)
    {
        int n = g.size(), m = g[0].size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (g[i][j] != INF_VAL)
                {
                    adjMatrix[i][j] = new edge(g[i][j], i, j);
                    adjTable[i].insert(j);
                    memTable.insert(adjMatrix[i][j]);
                }
    }
};

class spanningTree
{
private:
    unordered_set<int> vset;
    unordered_set<edge *> eset;
    int _sum;
    _set_union st;

public:
    spanningTree()
    {
        _sum = 0;
    }
    inline void addsum(int v) { _sum += v; }
    inline void pushv(int v) { vset.insert(v); }
    inline void pushe(edge *e) { eset.insert(e); }
    inline void unite(int v1, int v2) { st.unite(v1, v2); }
    inline int size() { return vset.size(); }
    inline int sum() { return _sum; }
    bool overlap(int v1, int v2) { return st.same(v1, v2); }
    bool exist(int v) { return vset.count(v); }
};

}; // namespace newgraph

#endif