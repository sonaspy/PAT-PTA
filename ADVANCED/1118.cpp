// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)
#define MAXN 10001
using namespace std;
int n, k, num, i, j, tree[MAXN], tmp, exist[MAXN] = {0}, cnt1 = 0, cnt2 = 0, p1, p2;
inline int find_root(int id)
{
    return tree[id] == -1 ? id : tree[id] = find_root(tree[id]);
}
inline void Union__(int a, int b)
{
    int ra = find_root(a), rb = find_root(b);
    if (ra != rb)
        tree[rb] = ra;
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cin >> n;
    fill(tree, tree + MAXN, -1);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &num);
        scanf("%d", &tmp);
        exist[tmp] = 1;
        int r = find_root(tmp);
        for (j = 1; j < num; j++)
        {
            scanf("%d", &tmp);
            exist[tmp] = 1;
            Union__(r, tmp);
        }
    }
    for (i = 1; i < MAXN; i++)
    {
        if (exist[i])
        {
            cnt2++;
            if (tree[i] == -1)
                cnt1++;
        }
    }
    cout << cnt1 << " " << cnt2 << endl;
    cin >> k;
    for (i = 0; i < k; i++)
    {
        scanf("%d%d", &p1, &p2);
        cout << (find_root(p1) == find_root(p2) ? "Yes" : "No") << endl;
    }
    return 0;
}