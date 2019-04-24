// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
int coin[10001], n, target, vis[10001], solved = 0;
static vector<int> ansPath, tmp;
inline void dfs(int cur, int coin_sum)
{
    vis[cur] = 1;
    if (coin_sum == target)
    {
        solved = 1;
        ansPath = tmp;
        return;
    }
    for (int i = 1; i <= n; i++)
        if (!vis[i] && !solved && coin_sum + coin[i] <= target)
        {
            tmp.push_back(coin[i]);
            dfs(i, coin_sum + coin[i]);
            vis[i] = 0;
            tmp.pop_back();
        }
}

int main()
{
    //test();
    scanf("%d%d", &n, &target);
    long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &coin[i]);
        sum += coin[i];
    }
    if (sum < target){printf("No Solution"); return 0; }
    sort(coin + 1, coin + n + 1);
    dfs(0, 0); // 0 point , 0 sum.
    if (solved)
    {
        printf("%d", ansPath[0]);
        for (int i = 1; i < ansPath.size(); i++)
            printf(" %d", ansPath[i]);
    }
    else printf("No Solution");
    return 0;
} //attention