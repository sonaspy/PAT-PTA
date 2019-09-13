// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

using namespace std;

namespace newgraph
{
#define MAXVSIZE 1000
#define INF_VAL 1 << 30
struct theNode
{
    int w1, w2, w3, v1, v2;
    theNode(int w1) : w1(w1), w2(INF_VAL), w3(INF_VAL), v1(-1), v2(-1) {}
    theNode(int v1, int v2) : w1(INF_VAL), w2(INF_VAL), w3(INF_VAL), v1(v1), v2(v2) {}
    theNode(int w1, int v1, int v2) : w1(w1), w2(INF_VAL), w3(INF_VAL), v1(v1), v2(v2) {}
};
class udGraph
{
protected:
    unordered_set<theNode *> memTable;
    unordered_set<theNode *> adjTable[MAXVSIZE];
    vector<vector<theNode *>> adjMatrix;
    vector<int> indeg, outdeg, vis, w1, w2;
    void __clearArray()
    {
        fill(vis.begin(), vis.end(), 0);
        fill(w1.begin(), w1.end(), 0);
        fill(w2.begin(), w2.end(), 0);
    }

public:
    udGraph()
    {
        adjMatrix = vector<vector<theNode *>>(MAXVSIZE, vector<theNode *>(MAXVSIZE, nullptr));
        w1 = w2 = vis = indeg = outdeg = vector<int>(MAXVSIZE, 0);
    }
    void readData(vector<vector<int>> &g)
    {
        int n = g.size();
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
                if (g[i][j] != INF_VAL)
                {
                    adjMatrix[j][i] = adjMatrix[i][j] = new theNode(g[i][j]);
                    memTable.insert(adjMatrix[i][j]);
                }
    }
};

class dGraph : public udGraph
{

public:
    dGraph()
    {
    }
    void readData(vector<vector<int>> &g)
    {
        int n = g.size(), m = g[0].size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (g[i][j] != INF_VAL)
                {
                    adjMatrix[i][j] = new theNode(g[i][j], i, j);
                    memTable.insert(adjMatrix[i][j]);
                }
    }
};

}; // namespace newgraph