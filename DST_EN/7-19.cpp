


#include <iostream>
#include<algorithm>
#define MAX 300000
#define INF 99999999
#define test() freopen("in", "r", stdin)
using namespace std;
int root[505], costs[505];
struct Route
{
    int c1, c2, cost, status;
    void read()
    {
        scanf("%d%d%d%d", &c1, &c2, &cost, &status);
    }
    bool operator<(const Route &r)
    {
        return r.status == status ? cost < r.cost : status > r.status;
    }
} routes[MAX];

int getroot(int n)
{
    return root[n] == n ? n : root[n] = getroot(root[n]);
}
int main(int argc, char const *argv[])
{
    /* code */
    int N, M, i, j, num;
    scanf("%d%d", &N, &M);
    for (i = 0; i < M; ++i)
        routes[i].read();
    sort(routes, routes + M);
    int ans = 0;
    for (i = 1; i <= N; ++i)
        {
            for (j = 1; j <= N; ++j)
                root[j] = j;
            costs[i] = 0;
            num = N - 2;
            for (j = 0; j < M; ++j)
                {
                    if (routes[j].c1 == i || routes[j].c2 == i)
                        continue;
                    int r1 = getroot(routes[j].c1), r2 = getroot(routes[j].c2);
                    if (r1 == r2)
                        continue;
                    --num;
                    root[r2] = r1;
                    if (!routes[j].status)
                        costs[i] += routes[j].cost;
                }
            if (num > 0)
                costs[i] = INF;
            ans = max(ans, costs[i]);
        }
    if (ans)
        {
            bool flag = 0;
            for (i = 1; i <= N; ++i)
                {
                    if (costs[i] == ans)
                        {
                            printf("%s%d", flag ? " " : "", i);
                            flag = 1;
                        }
                }
            return 0;
        }
    printf("0");
    return 0;
}