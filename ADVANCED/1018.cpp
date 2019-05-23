// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>
#define test() freopen("in", "r", stdin)
using namespace std;
#define INF 1 << 30
#define PBMC 0
int perfect, n, sp, m, ans_plus = INF, ansextra = INF;
vector<int> pre[501], tmp_Path, res, dis(501, INF), vis(501, 0), bikes(501, 0);
vector<vector<int>> MAP(501, vector<int>(501, INF));

void dfs(int dst)
{
    if (dst == PBMC)
    {
        int surplus = 0, extra = 0;
        for (auto i = tmp_Path.rbegin(); i != tmp_Path.rend(); i++)
        {
            surplus += bikes[*i] - perfect;
            if (surplus < 0)
            {
                extra -= surplus;
                surplus = 0;
            }
        }
        if (extra < ansextra)
            ansextra = extra, ans_plus = surplus, res = tmp_Path;
        else if (extra == ansextra && surplus < ans_plus)
            ans_plus = surplus, res = tmp_Path;
        return;
    }
    tmp_Path.push_back(dst);
    for (int i : pre[dst])
        dfs(i);
    tmp_Path.pop_back();
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cin >> perfect >> n >> sp >> m;
    perfect /= 2;
    for (int i = 1; i < n + 1; i++)
        scanf("%d", &bikes[i]);
    for (int i = 0; i < m; i++)
    {
        int c1, c2, c3;
        scanf("%d %d %d", &c1, &c2, &c3);
        MAP[c1][c2] = MAP[c2][c1] = c3;
    }
    dis[PBMC] = 0;
    while (true)
    {
        int k = -1, min = INF;
        for (int j = 0; j < n + 1; j++)
        {
            if (!vis[j] && dis[j] < min)
            {
                min = dis[j];
                k = j;
            }
        }
        if (k == -1)
            break;
        vis[k] = 1;
        for (int j = 0; j < n + 1; j++)
        {
            if (!vis[j] && MAP[k][j] < INF)
            {
                if (dis[k] + MAP[k][j] < dis[j])
                {
                    pre[j].clear();
                    dis[j] = dis[k] + MAP[k][j];
                    pre[j].push_back(k);
                }
                else if (dis[k] + MAP[k][j] == dis[j])
                    pre[j].push_back(k);
            }
        }
    }
    dfs(sp);
    cout << ansextra << " " << PBMC;
    for (int i = res.size() - 1; i > -1; i--)
        cout << "->" << res[i];
    cout << " " << ans_plus;
    return 0;
}