#include<ngpp.h>
using namespace std;
int mp[11][11];
bool visited[11];
void dfs(int n, int v)
{ //只进行递,不进行归
    for (int i = 0; i < v; i++)
        if (!visited[i] && mp[n][i])
        {
            visited[i] = true;
            printf("%d ", i);
            dfs(i, v);
        }
    return;
}

void bfs(int n, int v)
{
    queue<int> Q;
    visited[n] = true;
    Q.push(n);
    while (!Q.empty())
    {
        int fnt = Q.front();
        Q.pop();
        for (int i = 0; i < v; i++)
            if (!visited[i] && mp[fnt][i])
            {
                printf("%d ", i);
                visited[i] = true;
                Q.push(i);
            }
    }
    return;
}

int main()
{
    int n, e, a, b;
    scanf("%d%d", &n, &e);
    for (int i = 0; i < e; i++)
    {
        scanf("%d%d", &a, &b);
        mp[a][b] = mp[b][a] = 1;
    }
    memset(visited, false, sizeof(visited)); //必须进行重新赋值为false
    for (int i = 0; i < n; i++)
        if (!visited[i])
        {
            visited[i] = true;
            printf("{ %d ", i); //必须先输出遍历的起始数字
            dfs(i, n);
            printf("}\n");
        }
    memset(visited, false, sizeof(visited)); //必须进行重新赋值为false
    for (int i = 0; i < n; i++)
        if (!visited[i])
        {
            printf("{ %d ", i); //必须先输出遍历的起始数字
            bfs(i, n);
            printf("}\n");
        }
    return 0;
}