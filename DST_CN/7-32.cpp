// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <vector>
#include <algorithm>
#define test() freopen("in", "r", stdin)

using namespace std;
#define MAXN 1001
int MAP[MAXN][MAXN], reached[MAXN] = {0}, degree[MAXN] = {0};
void DFS(int v, int n)
{
    reached[v] = 1;
    for (int j = 1; j <= n; j++)
        if (MAP[v][j] && !reached[j])
            DFS(j, n);
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int N, M, isOral = 1;
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            MAP[i][j] = 0;
    for (int i = 0; i < M; i++)
    {
        int c1, c2;
        scanf("%d%d", &c1, &c2);
        MAP[c1][c2] = 1;
        MAP[c2][c1] = 1;
        degree[c1]++;degree[c2]++;
    }
    DFS(1, N);
    for (int i = 1; i <= N; i++)
    {
        if (!reached[i] || degree[i] % 2)
        {
            isOral = 0;
            break;
        }
    }
    cout << isOral;
    return 0;
}