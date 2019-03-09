// author -  newguo@sonaspy.cn
// coding - utf_8

#include <cstdio>
#include<cstdlib>
#include<iostream>
#define test() freopen("in", "r", stdin)
#define MAXNUM 1 << 16

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int N, M, a1, a2, cost, sta,
        i, j, sum = 0, cur,
              MAP[102][102], reached[102], dis[102];
    memset(MAP, MAXNUM, sizeof(MAP));
    memset(reached, 0, sizeof(reached));
    scanf("%d", &N);
    M = (N - 1) * N / 2;
    for (int i = 0; i < M; i++)
        {
            scanf("%d%d%d%d", &a1, &a2, &cost, &sta);
            MAP[a1][a2] = sta ? 0 : cost;
            MAP[a2][a1] = sta ? 0 : cost;
        }
    // prim algorithm. start from 1.
    int source = 1;
    for (i = 1; i <= N; i++)
        dis[i] = MAP[source][i];
    dis[source] = 0, reached[source] = 1;
    for (int i = 1; i <= N; i++)
        {
            int min = MAXNUM;
            bool finded = false;
            for (j = 1; j <= N; j++)
                if (!reached[j] && dis[j] < min)
                    {
                        min = dis[j];
                        cur = j;
                        finded = true;
                    }
            if (!finded)
                break;
            sum += min;
            reached[cur] = 1;
            for (j = 1; j <= N; j++)
                if (!reached[j] && dis[j] > MAP[cur][j])
                    dis[j] = MAP[cur][j];
        }
    printf("%d\n", sum);
    return 0;
}