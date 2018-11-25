#include <stdio.h>
#include <vector>
#define inf 99999999
using namespace std;
//int mark[1010];
int visit[1010];
int indegree[1010];
vector<int> adj[1010]; //邻接表
int main()
{
    int n, i, j, count;
    scanf("%d", &n);
    count = n;
    int a[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            indegree[i] = -1;
            count--; //除去负数后需要输出的个数
            continue;
        }
        j = a[i] % n;
        if (j != i)
        { //
            indegree[i] = (i - j + n) % n;
            int k;
            for (k = 0; k < indegree[i]; k++)
            {
                adj[(j + k) % n].push_back(i);
            }
        }
    }
    int store[1010], size = 0;
    for (i = 0; i < count; i++)
    {
        int min = inf, index = -1;
        for (j = 0; j < n; j++)
        { //每次找出符合要求最小的
            if (visit[j] == 0 && indegree[j] == 0)
            {
                if (a[j] < min)
                {
                    min = a[j];
                    index = j;
                }
            }
        }
        visit[index] = 1;
        store[size++] = min;
        for (j = 0; j < adj[index].size(); j++)
        {
            int next = adj[index][j];
            indegree[next]--;
        }
    }
    for (i = 0; i < size; i++)
    {
        printf("%d", store[i]);
        if (i < size - 1)
        {
            printf(" ");
        }
    }
}