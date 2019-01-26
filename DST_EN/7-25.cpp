//题意是在所有点中寻找一个点，使得这个点到其他所有点的最短路径中最大的那条边长度是和其他相比最小的
#include <iostream>
#include <string.h>
#define INF 0x3f3f3f3f
int n, m, mp[105][105];
void Floyd()
{
    int i, j, k;
    for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                if (mp[i][k] != INF && mp[k][j] != INF && mp[i][j] > mp[i][k] + mp[k][j])
                    mp[i][j] = mp[i][k] + mp[k][j];
}
int main()
{
    int i, j, a, b, d;
    scanf("%d%d", &n, &m);
    memset(mp, INF, sizeof(mp));
    for (i = 0; i < m; i++)
    {
        scanf("%d%d%d", &a, &b, &d);
        mp[a][b] = mp[b][a] = d;
    }
    Floyd();
    int min = INF;
    int f = -1;
    for (i = 1; i <= n; i++)
    {
        int tmpMax = 0;
        for (j = 1; j <= n; j++)
        {
            if (j == i)continue;
            if (mp[i][j] == INF)
            { 
                printf("0");
                return 0;
            }
            if (mp[i][j] > tmpMax)
                tmpMax = mp[i][j];
        }
        if (tmpMax > 0 && tmpMax < min)
        { 
            min = tmpMax;
            f = i;
        }
    }
    printf("%d %d\n", f, min);
    return 0;
}