// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)
using namespace std;

struct edge
{
    int v1, v2;
    int lens;
    bool operator<(const edge &t) const
    {
        return lens < t.lens;
    }
} edges[101];
int root[101];

inline int findroot(int n)
{
    return (root[n] == -1 ? n : root[n] = findroot(root[n]));
}
int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF && n != 0)
    {
        fill(root, root + m + 1, -1);
        for (int i = 0; i < n; i++)
            scanf("%d%d%d", &(edges[i].v1), &(edges[i].v2), &(edges[i].lens));
        sort(edges, edges + n);
        int ans = 0, es = 0, a, b;
        for (int i = 0; i < n; i++)
        {
            a = findroot(edges[i].v1);
            b = findroot(edges[i].v2);
            if (a != b)
            {
                root[a] = b;
                ans += edges[i].lens;
                es++;
            }
        }
        es == m - 1 ? printf("%d\n", ans) : printf("?\n");
    }
    return 0;
}