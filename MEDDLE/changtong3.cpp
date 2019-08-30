// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)
using namespace std;

int root[1111];

inline int findroot(int n)
{
    return root[n] == -1 ? n : (root[n] = findroot(root[n]));
}
int main()
{
    //test();
    int n, m, a1, a2;
    while (scanf("%d%d", &n, &m) != EOF && n != 0)
    {
        fill(root, root + 1111, -1);
        int es = -1;
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d", &a1, &a2);
            a1 = findroot(a1);
            a2 = findroot(a2);
            if (a1 != a2)
                root[a2] = a1;
        }
        for (int i = 1; i <= n; i++)
        {
            if (root[i] == -1)
                es++;
        }
        printf("%d\n", es);
    }
    return 0;
}