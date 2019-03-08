// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <algorithm>
#include <vector>
#define test() freopen("in", "r", stdin)

using namespace std;
#define INF 99999999
int cmax, n, sp, m, bikes[501], map[501][501], vis[501], dis[501], towback = INF, ansextra = INF;
vector<int> path[501], tmp, res; 

void DFS(int end){
    if(!end){
        int own = 0, extra = 0;
        for(int i = tmp.size()-1; i> -1; i--){
            own += bikes[tmp[i]] - cmax;
            if(own < 0){
                extra += (-own);
                own = 0;
            }
        }
        if(extra < ansextra){
            ansextra = extra;
            towback = own;
            res = tmp;
        }else if(extra == ansextra && own < towback){
            towback = own;
            res =tmp;
        }
        return;
    }
    tmp.push_back(end);
    for(int i = 0; i < path[end].size();i++)
        DFS(path[end][i]);
    tmp.pop_back();
}


int main(int argc, char const *argv[])
{
    /* code */
    test();
    cin >> cmax >> n >> sp >> m;
    cmax /= 2;
    for (int i = 1; i <= n; i++)
        scanf("%d", &bikes[i]);
    fill(map[0], map[0] + 501*501, INF);
    fill(dis, dis + 501, INF);
    for (int i = 0; i < m; i++)
    {
        int c1, c2, c3;
        scanf("%d %d %d", &c1, &c2, &c3);
        map[c1][c2] = c3;
        map[c2][c1] = c3;
    }
    dis[0] = 0;
    for (int i = 0; i <= n; i++)
    {
        int k = -1, min = INF;
        for (int j = 0; j <= n; j++)
        {
            if (!vis[j] && dis[j] < min)
            {
                min = dis[j];
                k = j;
            }
        }
        if (k == -1) break;
        vis[k] = 1;
        for (int j = 0; j <= n; j++)
        {
            if (!vis[j] && map[k][j] < INF)
            {
                int tmp = 0;
                if (dis[k] + map[k][j] < dis[j])
                {
                    path[j].clear();
                    dis[j] = dis[k] + map[k][j];
                    path[j].push_back(k);
                }
                else if(dis[k] + map[k][j] == dis[j])
                    path[j].push_back(k);
            }
        }
    }
    DFS(sp);
    cout << ansextra << " ";
    cout << 0;
    for(int i = res.size()-1; i > -1; i--)
        cout << "->" <<  res[i];
    cout << " " << towback;
    return 0;
}