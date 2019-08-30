
// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

int v[1005], cnt[1005];
inline int find(int x)
{
    return v[x] == x ? x : v[x] = find(v[x]);
}
int main()
{
    int n, m, x, y, i;
    //freopen("input.txt","r",stdin);
    while (scanf("%d", &n) != EOF && n)
    {
        scanf("%d", &m);
        for (i = 0; i < 1005; i++)
            v[i] = i, cnt[i] = 0;
        while (m--)
        {
            scanf("%d%d", &x, &y);
            cnt[x]++, cnt[y]++;
            int fax = find(x), fay = find(y);
            if (fax != fay)
                v[fax] = fay;
        }
        int f = find(1), flag = 1;
        if (cnt[1] % 2)
        {
            printf("0\n");
            continue;
        }
        for (i = 2; i <= n; i++)
            if ((cnt[i] && find(i) != f) || cnt[i] % 2)
            {
                flag = 0;
                break;
            }
        printf("%d\n", flag);
    }
}