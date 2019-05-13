// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#define INF 9999999
#define MAXN 10001
#define test() freopen("in", "r", stdin)

using namespace std;

int n, m, mp[MAXN][MAXN] = {0};
void Floyd()
{
    int i, j, k;
    for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
            {
                if (k == i || k == j || i == j)
                    continue;
                if (mp[i][j] > mp[i][k] + mp[k][j])
                    mp[i][j] = mp[i][k] + mp[k][j];
            }
}

void Solve(int src)
{
    int i, Sum = 0;
    for (i = 1; i <= n; i++)
    {
        if (mp[src][i] == INF)
        {
            printf("Cc(%d)=0.00\n", src);
            return;
        }
    }
    for (i = 1; i <= n; i++)
        Sum += mp[src][i];
    printf("Cc(%d)=%.2f\n", src, (n - 1) * 1.0 / Sum);
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cin >> n >> m;
    int i, j, K, x, y;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (i != j)
                mp[i][j] = INF;
    for (i = 0; i < m; i++)
    {
        scanf("%d%d", &x, &y);
        mp[x][y] = mp[y][x] = 1;
    }
    Floyd();
    cin >> K;
    for (i = 0; i < K; i++)
    {
        scanf("%d", &x);
        Solve(x);
    }
    return 0;
}