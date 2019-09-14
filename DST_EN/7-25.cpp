// author - newguo@sonaspy.cn
// coding - utf_8

#define SIZE 100
#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

#define INF 0x3f3f3f3f
int n, m;
int mp[105][105];
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

    test();
    int i, j;
    scanf("%d%d", &n, &m);
    memset(mp, INF, sizeof(mp));
    for(int i = 0; i < n ; i++)mp[i][i] = 0;
    for (i = 0; i < m; i++)
    {
        int a, b, d;
        scanf("%d%d%d", &a, &b, &d);
        mp[a][b] = mp[b][a] = d;
    }
    Floyd();
    int min = INF;
    int f = -1;
    for (i = 1; i <= n; i++)
    {
        int max = 0;
        int flag = 1;
        for (j = 1; j <= n; j++)
        {
            if (j == i)
                continue;
            if (mp[i][j] == INF)
            {
                flag = 0;
                break;
            }
            max = mp[i][j] > max ? mp[i][j] : max;
        }
        if (!flag)
            continue;
        if (max && max < min)
        {
            min = max;
            f = i;
        }
    }
    if (min == INF)
        printf("0\n");
    else
        printf("%d %d\n", f, min);
    return 0;
}