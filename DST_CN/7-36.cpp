// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#define INF 9999999
#define MAXN 10001
#define test() freopen("in", "r", stdin)

using namespace std;

int N, M, Map[MAXN][MAXN], Dist[MAXN];

void Floyd(){
    int i, j ,k;
    for (k = 1; k <= N; k++)
        for (i = 1; i <= N; i++)
            for (j = 1; j <= N; j++)
            {
                if (k == i || k == j || i == j)
                    continue;
                if (Map[i][j] > Map[i][k] + Map[k][j])
                {
                    Map[i][j] = Map[i][k] + Map[k][j];
                }
            }
}

void solute(int source){
    int i;
    Dist[source] = 0;
    for (i = 1; i <= N; i++)
    {
            Dist[i] = Map[source][i];
        if (Dist[i] == INF)
        {
            cout << "solute(" << source << ")=0.00" << endl;
            return;
        }
    }
    int Sum = 0;
    for (i = 1; i <= N; i++)
        Sum += Dist[i];
    printf("solute(%d)=%.2f\n", source, (N - 1) * 1.0 / Sum);
}

int main(int argc, char const *argv[])
{
    /* code */
  //test();
    cin >> N >> M;
    int i, j;
    for (i = 1; i <= N; i++)
        for (j = 1; j <= N; j++)
            if (i != j) Map[i][j] = INF;
    for (i = 0; i < M; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        Map[x][y] = Map[y][x] = 1;
    }
    Floyd();
    int K;
    cin >> K;
    for (i = 0; i < K; i++)
    {
        int x;
        cin >> x;
        solute(x);
    }
    return 0;
}

