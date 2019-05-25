// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

#define INF 1 << 30
using namespace std;
int n, m, s, d, vis[501], shortest_dis[501], ansCost = INF;
struct Node
{
    int dis = INF, cost = INF;
} MAP[501][501];
vector<int> path[501], tmpPath, resPath;

void dfs(int cur)
{
    tmpPath.push_back(cur);
    static int tmpCost = 0;
    if (cur == s)
    {
        if (tmpCost < ansCost)
        {
            ansCost = tmpCost;
            resPath = tmpPath;
        }
        return;
    }
    for (auto i : path[cur])
    {
        tmpCost += MAP[cur][i].cost;
        dfs(i);
        tmpCost -= MAP[cur][i].cost;
        tmpPath.pop_back();
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cin >> n >> m >> s >> d;
    fill(shortest_dis, shortest_dis + 501, INF);
    for (int i = 0; i < m; i++)
    {
        int c1, c2, d1, d2;
        scanf("%d%d%d%d", &c1, &c2, &d1, &d2);
        MAP[c1][c2].dis = d1, MAP[c2][c1].dis = d1, MAP[c1][c2].cost = d2, MAP[c2][c1].cost = d2;
    }
    shortest_dis[s] = 0;
    while (true)
    {
        int k = -1, _min = INF;
        for (int j = 0; j < n; j++)
        {
            if (!vis[j] && shortest_dis[j] < _min)
            {
                k = j;
                _min = MAP[s][j].dis;
            }
        }
        if (k == -1)
            break;
        vis[k] = 1;
        for (int j = 0; j < n; j++)
            if (!vis[j] && MAP[k][j].dis != INF)
            {
                if (shortest_dis[k] + MAP[k][j].dis < shortest_dis[j])
                {
                    shortest_dis[j] = shortest_dis[k] + MAP[k][j].dis;
                    path[j].clear();
                    path[j].push_back(k);
                }
                else if (shortest_dis[k] + MAP[k][j].dis <= shortest_dis[j])
                    path[j].push_back(k);
            }
    }
    dfs(d);
    for (int i = resPath.size() - 1; i > -1; i--)
        cout << resPath[i] << " ";
    cout << shortest_dis[d] << " " << ansCost;
    return 0;
}