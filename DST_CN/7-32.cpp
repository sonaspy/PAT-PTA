// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#define MAX 1001
#define test() freopen("in", "r", stdin)

using namespace std;

#define MAX 1001
int point[MAX][MAX];
int visited[MAX] = {0}, cnt[MAX] = {0}, n, m, flag = 1;
;
void dfs(int i)
{
    visited[i] = 1;
    for (int j = 1; j <= n; j++)
    {
        if (point[i][j] && !visited[j])
            dfs(j);
    }
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int p1, p2;
        scanf("%d%d", &p1, &p2);
        point[p1][p2] = 1, point[p2][p1] = 1, cnt[p1]++, cnt[p2]++;
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i] || cnt[i] % 2 == 1)
        {
            flag = 0;
            break;
        }
    }
    printf("%d\n", flag);
}