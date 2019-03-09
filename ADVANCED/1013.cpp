// author -  newguo@sonaspy.cn
// coding - utf_8
/*
给出n个城市，城市间有m条路，k个要检查的城市
假如这k个城市被攻占，所有相关的路线全部瘫痪，要使其他城市保持连通，至少需要修缮多少条路

添加最少的路线，就是连通分量数-1(例：n个互相独立的连通分量组成一个连通图，只需要连n-1条线就可以)
这道题最重要就是求除去图的一个节点后 剩余的连通分量的数目
利用邻接矩阵v存储路线，用visit数组表示城市是否被遍历过
对于每个被占领的城市，将其表示为遍历过的状态true即可
利用深度优先遍历dfs计算连通分量数目
*/
#include <iostream>
#define test() freopen("in", "r", stdin)

using namespace std;
int n, m, k, a, b;
int map[1001][1001], vis[1001];
void dfs(int v)
{
    vis[v] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i] && map[v][i])
            dfs(i);
    }
}
int main(int argc, char const *argv[])
{
    /* code */
    //test(); attention
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &a, &b);
        map[a][b] = 1, map[b][a] = 1;
    }
    for (int i = 0; i < k; i++)
    {
        fill(vis, vis + 1001, 0);
        int check, cnt = 0;
        cin >> check;
        vis[check] = true;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j])
            {
                dfs(j);
                cnt++;
            }
        }
        printf("%d\n", cnt - 1);
    }
    return 0;
}