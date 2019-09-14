#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
vector<int> adj[1010];
int visit[1010];
int layer[1010];
int cou = 0;
void init(int n)
{
    int i;
    cou = 0;
    for (i = 1; i <= n; i++)
    {
        visit[i] = 0;
    }
}
void bfs(int s)
{
    visit[s] = 1;
    layer[s] = 0;
    int i;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        cou++;
        int head = q.front();
        q.pop();
        for (i = 0; i < adj[head].size(); i++)
        {
            int next = adj[head][i];
            if (visit[next] == 0)
            {
                layer[next] = layer[head] + 1;
                q.push(next);
                visit[next] = 1;
            }
        }
    }
}
int main()
{
    int n, m, i, c1, c2, k, j;
    scanf("%d %d", &n, &m);
    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &c1, &c2);
        adj[c1].push_back(c2);
        adj[c2].push_back(c1);
    }
    scanf("%d", &k);
    int index[k];
    for (i = 0; i < k; i++)
    {
        scanf("%d", &index[i]);
    }
    for (i = 0; i < k; i++)
    {
        //		scanf("%d",&index[i]); break之后 k-1个数字还没读取
        init(n);
        bfs(index[i]);
        if (cou != n)
        {
            break;
        }
        int sum = 0;
        for (j = 1; j <= n; j++)
        {
            sum = sum + layer[j];
        }
        printf("Cc(%d)=%.2lf\n", index[i], (double)(n - 1) / sum);
    }
    if (cou != n)
    {
        for (i = 0; i < k; i++)
        {
            printf("Cc(%d)=0.00\n", index[i]);
        }
    }
}