
#include <stdio.h>
int map[1002], degree[1002] = {0}; //记录每个点的度数
int n, m;

int findroot(int x)
{
    return map[x] == -1 ? x : map[x] = findroot(map[x]);
}
void Union(int x, int y)
{
    int fx = findroot(x), fy = findroot(y);
    if (fx != fy)
        map[fy] = fx;
}
inline bool iserlur()
{
    int i, cnt = 0;
    for (i = 1; i <= n; i++)
        cnt += map[i] == -1 ? 1 : 0;
    if (cnt != 1) return false;
    for (i = 1; i <= n; i++)
        if (degree[i] & 1) return false;
    return true;
}
int main()
{
    int i, x, y;
    for (i = 0; i < 1002; i++)
        map[i] = -1;
    scanf("%d%d", &n, &m);
    for (i = 1; i <= m; i++)
    {
        scanf("%d%d", &x, &y);
        Union(x, y);
        degree[x]++, degree[y]++;
    }
    if (iserlur())
        printf("1\n");
    else
        printf("0\n");
    return 0;
}