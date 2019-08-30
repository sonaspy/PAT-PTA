// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
int coin[10001], n, target, coin_sum = 0;
static vector<int> path;
inline void dfs(int cur)
{
    if (coin_sum > target)
        return;
    if (coin_sum == target)
    {
        printf("%d", path[0]);
        for (int i = 1; i < path.size(); i++)
            printf(" %d", path[i]);
        exit(0);
    }
    for (int i = cur + 1; i <= n; i++)
        if (coin_sum + coin[i] <= target)
        {
            path.push_back(coin[i]);
            coin_sum += coin[i];
            dfs(i);
            coin_sum -= coin[i];
            path.pop_back();
        }
}
int main()
{
    //test();
    scanf("%d%d", &n, &target);
    long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", coin + i);
        sum += coin[i];
    }
    if (sum < target)
        goto end;
    sort(coin + 1, coin + n + 1);
    dfs(0); // 0 point , 0 sum.
end:
    printf("No Solution");
    return 0;
}