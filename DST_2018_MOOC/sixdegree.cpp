#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define MAXN 10005
int pic[MAXN][MAXN];
int flag[MAXN];
int N,M;

int bfs(int n)
{
    flag[n] = 1;
    int cnt = 1; //6层范围内的数
    int level = 0;
    int last = n; //最后一个结点
    int tail = 0; //尾巴
    queue<int> q;
    q.push(n);
    int temp; //  临时结点
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        for (int i = 1; i <= N; ++i)
        {
            if (pic[temp][i] && flag[i] == 0)
            { //有边且未被访问过
                flag[i] = 1;
                q.push(i);
                cnt++;
                tail = i;
            }
        }
        if (temp == last)
        {
            level++;
            last = tail;
        }
        if (level == 6)
            break;
    }
    return cnt;
}

int main(void)
{
    scanf("%d%d", &N, &M);
    int x, y;
    for (int i = 1; i <= M; ++i)
    {
        scanf("%d%d", &x, &y);
        pic[x][y] = 1;
        pic[y][x] = 1;
    }

    for (int i = 1; i <= N; ++i)
    {
        memset(flag, 0, sizeof(flag));
        int num = bfs(i);
        printf("%d: %.2f\n", i, num * 100.0 / N);
    }
    return 0;
}