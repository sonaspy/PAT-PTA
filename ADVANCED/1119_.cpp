// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int n, pre[35], post[35], in[35], c = 0, flag = 1;

void check(int prel, int prer, int postl, int postr)
{
    if (prel > prer)
    {
        flag = 0;
        return;
    }
    else if (prel == prer)
    {
        in[++c] = pre[prel];
        return;
    }
    int i = postl;
    while (i <= postr && post[i] != pre[prel + 1])
        i++;
    check(prel + 1, prel + 1 + i - postl, postl, i);
    in[++c] = pre[prel];
    check(prel + i - postl + 2, prer, i + 1, postr - 1);
}
int main()
{
    //test();
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &pre[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &post[i]);
    check(1, n, 1, n);
    puts(flag ? "Yes" : "No");
    for (int i = 1; i <= c; i++)
        printf("%d%c", in[i], (i == c ? '\n' : ' '));
    return 0;
} //attention