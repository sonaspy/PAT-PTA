#include <bits/stdc++.h>
using namespace std;
int coin[10001], n, m, vis[10001];
static bool found = false;
static vector<int> ansPath, tmp;
void dfs(int cur, int w)
{
    vis[cur] = 1;
    if (found || w > m)
        return;
    if (w == m)
    {
        found = true;
        ansPath = tmp;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            tmp.push_back(coin[i]);
            dfs(i, w + coin[i]);
            vis[i] = 0;
            tmp.pop_back();
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &coin[i]);
        sum += coin[i];
    }
    if (sum < m){printf("No Solution"); return 0;}
    sort(coin + 1, coin + n + 1);
    dfs(0, 0);
    if (found)
    {
        printf("%d", ansPath[0]);
        for (int i = 1; i < ansPath.size(); i++)
            printf(" %d", ansPath[i]);
    }
    else  printf("No Solution");
    return 0;
}