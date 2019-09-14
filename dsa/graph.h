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
    bool operator()(const edge *e1, const edge *e2) const { return e1->w1 > e2->w1; }
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
    inline int vsize() { return vset.size(); }
    inline int esize() { return eset.size(); }
    inline int sum() { return _sum; }
    bool overlap(int v1, int v2) { return st.same(v1, v2); }
    bool exist(int v) { return vset.count(v); }
    inline void clear() { _sum = 0, st.clear(), vset.clear(), eset.clear(); }
};

class udGraph
{
protected:
    int nv, connected_cnt, ev;
    unordered_set<edge *> memTable;
    unordered_set<int> table[MAXVSIZE];
    vector<vector<edge *>> matrix;
    vector<int> indeg, outdeg, vis, w1, w2, tmppath, respath, pre[MAXVSIZE];
    priority_queue<edge *, vector<edge *>, __cmp1> e_pq;
    spanningTree stp;
    void __clearArray()
    {
        fill(vis.begin(), vis.end(), 0);
        fill(w1.begin(), w1.end(), 0);
        fill(w2.begin(), w2.end(), 0);
    }
    void __prim()
    {
        if (connected_cnt > 1)
            return;
        stp.clear();
        int i, j, v, length[nv], min_, v1;
        vector<int> parent(nv, 0);
        for (i = 0; i < nv; i++)
        {
            parent[i] = 0;
            length[i] = (matrix[0][i]) ? matrix[0][i]->w1 : INF_VAL;
        }
        parent[0] = -1, length[0] = 0;
        stp.pushv(0);
        while (1)
        {
            v = -1, min_ = INF_VAL;
            for (i = 0; i < nv; i++)
            {
                if (!stp.exist(i) && length[i] < min_)
                    v = i, min_ = length[i];
            }
            v1 = parent[v];
            stp.pushe(matrix[v1][v]);
            stp.pushv(v);
            stp.addsum(min_);
            if (stp.vsize() == nv)
                break;
            for (j = 0; j < nv; j++)
                if (!stp.exist(j) && matrix[v][j] && matrix[v][j]->w1 < length[j])
                {
                    length[j] = matrix[v][j]->w1;
                    parent[j] = v;
                }
        }
    }

    void __kruskal()
    {
        if (connected_cnt > 1)
            return;
        stp.clear();
        edge *e;
        int v1, v2;
        while (e_pq.size() && stp.esize() < nv - 1)
        {
            e = e_pq.top(), e_pq.pop();
            v1 = e->v1, v2 = e->v2;
            if (stp.overlap(v1, v2))
                continue;
            stp.unite(v1, v2), stp.pushv(v1), stp.pushv(v2);
            stp.addsum(e->w1);
            stp.pushe(e);
        }
    }

    void __dfs(int v_id)
    {
        for (auto w : table[v_id])
            if (!vis[w])
            {
                vis[w] = 1;
                __dfs(w);
            }
    }

public:
    udGraph()
    {
        matrix = vector<vector<edge *>>(MAXVSIZE, vector<edge *>(MAXVSIZE, nullptr));
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
    void init(vector<vector<int>> &g)
    {
        int n = g.size();
        this->nv = n;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (g[i][j] != INF_VAL)
                {
                    matrix[j][i] = matrix[i][j] = new edge(g[i][j], i, j);
                    table[i].insert(j), table[j].insert(i);
                    this->ev++;
                    e_pq.push(matrix[i][j]);
                    memTable.insert(matrix[i][j]);
                }
        connected();
    }
    inline int stpsum()
    {
        return stp.sum();
    }
    void __getPath(int walk, int &src)
    {
        tmppath.push_back(walk);
        if (walk == src)
        {
            // some condition
            if (1)
                respath = tmppath;
            return;
        }
        for (auto j : pre[walk])
            __getPath(j, src);
        tmppath.pop_back();
    }
    vector<int> dijkstra(int src, int dst, vector<int> &cost)
    {
        vector<int> cost2, cost3, pathsum;
        pathsum[src] = 1;
        int v, min_, w;
        unordered_set<int> vset;
        fill(cost.begin(), cost.end(), INF_VAL);
        cost[src] = 0;
        vset.insert(src);
        while (1)
        {
            min_ = INF_VAL, v = -1;
            for (int i = 0; i < nv; i++)
            {
                if (!vset.count(i) && cost[i] < min_)
                    min_ = cost[i], v = i;
            }
            if (v == -1)
                break;
            vset.insert(v);
            for (w = 0; w < nv; w++)
            {
                if (!vset.count(w) && matrix[v][w]) // one type weight
                {
                    if (matrix[v][w]->w1 + cost[v] < cost[w]) // 1.
                    {
                        cost[w] = matrix[v][w]->w1 + cost[v];
                        //cost2[w] = matrix[v][w]->w2 + cost2[v];
                        pre[w].clear(), pre[w].push_back(v);
                        pathsum[w] = pathsum[v];
                    }
                    else if (matrix[v][w]->w1 + cost[v] == cost[w]) //2.
                    {
                        pre[w].push_back(v);
                        pathsum[w] += pathsum[v];
                    }
                    //or 1.same
                    //2. else if (matrix[v][w]->w1 + cost[v] == cost[w] && matrix[v][w]->w2 + cost2[v] < cost2[w])
                    // {
                    //  cost2[w] = matrix[v][w]->w2 + cost2[v];
                    //  pre[w] = v; pahtsum[w] = pathsum[v];
                    // }
                    // 3. else if (matrix[v][w]->w1 + cost[v] == cost[w] && matrix[v][w]->w2 + cost2[v] == cost2[w])
                    // {
                    //    pre[w].push_back(v);
                    //    pathsum[w] += pathsum[v];
                    // }........ analog
                }
            }
        }
        tmppath.clear(), respath.clear();
        __getPath(dst, src);
        reverse(respath.begin(), respath.end());
        return respath;
    }
    bool Floyd(vector<vector<int>> &mp, vector<vector<int>> &path)
    {
        int i, j, k;
        fill(path.begin(), path.end(), vector<int>(path.size(), -1));
        for (i = 0; i < nv; i++)
        {
            for (j = 0; j < nv; j++)
            {
                mp[i][j] = matrix[i][j] ? matrix[i][j]->w1 : INF_VAL;
                mp[i][j] = i == j ? 0 : mp[i][j];
            }
        }
        for (k = 0; k < nv; k++)
        {
            for (i = 0; i < nv; i++)
            {
                for (j = 0; j < nv; j++)
                {
                    if (mp[i][k] != INF_VAL && mp[k][j] != INF_VAL && mp[i][j] > mp[i][k] + mp[k][j])
                        mp[i][j] = mp[i][k] + mp[k][j], path[i][j] = k;
                    if (i == j && mp[i][j] < 0)
                        return false;
                }
            }
        }
        return true;
    }

    inline void makestp(int f)
    {
        f ? __kruskal() : __prim();
        cout << stp.vsize() << " " << stp.esize() << endl;
    }
    inline int vsize() { return this->nv; }
    inline int esize() { return this->ev; }
};

class dGraph : public udGraph
{

public:
    dGraph()
    {
        matrix = vector<vector<edge *>>(MAXVSIZE, vector<edge *>(MAXVSIZE, nullptr));
        w1 = w2 = vis = indeg = outdeg = vector<int>(MAXVSIZE, 0);
    }
    void init(vector<vector<int>> &g)
    {
        int n = g.size(), m = g[0].size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (g[i][j] != INF_VAL)
                {
                    matrix[i][j] = new edge(g[i][j], i, j);
                    table[i].insert(j);
                    memTable.insert(matrix[i][j]);
                }
    }
};

}; // namespace newgraph

#endif