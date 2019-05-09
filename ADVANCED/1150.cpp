// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
int MAP[300][300] = {0}, n, m, a1, a2, d, k, ansid, ansd = 1 << 30, tmpd, p, vis[300], first, tmp, last, flag;
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &a1, &a2, &d);
        MAP[a1][a2] = d, MAP[a2][a1] = d;
    }
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        printf("Path %d: ", i);
        flag = 1, tmpd = 0;
        fill(vis, vis + n + 1, 0);
        scanf("%d%d", &p, &first);
        last = first;
        for (int j = 1; j < p; j++)
        {
            scanf("%d", &tmp);
            if (!MAP[last][tmp])
                flag = 0;
            tmpd += MAP[last][tmp];
            vis[tmp]++;
            last = tmp;
        }
        if (!flag)
        {
            printf("NA (Not a TS cycle)\n");
            continue;
        }
        printf("%d ", tmpd);
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
                flag = 2;
            else if (vis[i] > 1 && i != first)
                flag = 3;
        }
        if (flag == 2 || last != first)
        {
            printf("(Not a TS cycle)\n");
            continue;
        }
        if (tmpd < ansd)
        {
            ansd = tmpd;
            ansid = i;
        }
        printf("%s\n", flag == 3 ? "(TS cycle)" : "(TS simple cycle)");
    }
    printf("Shortest Dist(%d) = %d\n", ansid, ansd);
    return 0;
}