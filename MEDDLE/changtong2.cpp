// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
#define N 101
int union_v[N];
inline int findRoot(int x)
{
    return union_v[x] == -1 ? x : union_v[x] = findRoot(union_v[x]);
}
struct Edge
{
    int a, b;
    int cost;
    bool operator<(const Edge &A) const
    {
        return cost < A.cost;
    }
} edge[6000];
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n;
    while (scanf("%d", &n) != EOF && n != 0)
    {
        int flag, ans = 0, a, b, cnt = 0;
        for (int i = 0; i < n * (n - 1) / 2; i++)
        {
            scanf("%d%d%d%d", &edge[i].a, &edge[i].b, &edge[i].cost, &flag);
            if (flag)
                edge[i].cost = 0;
        }
        sort(edge, edge + n * (n - 1) / 2);
        fill(union_v, union_v + N, -1);
        for (int i = 0; i < n * (n - 1) / 2; i++)
        {
            a = edge[i].a, b = edge[i].b;
            a = findRoot(a), b = findRoot(b);
            if (a != b)
            {
                union_v[a] = b;
                ans += edge[i].cost;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}