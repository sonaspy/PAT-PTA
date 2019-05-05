// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
struct node
{
    string data;
    int l, r;
} a[100];
string dfs(int root)
{
    if (a[root].l == -1 && a[root].r == -1)
        return a[root].data;
    if (a[root].l == -1 && a[root].r != -1)
        return "(" + a[root].data + dfs(a[root].r) + ")";
    if (a[root].l != -1 && a[root].r != -1)
        return "(" + dfs(a[root].l) + a[root].data + dfs(a[root].r) + ")";
    return "";
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int f[100] = {0}, n, root = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].data >> a[i].l >> a[i].r;
        if (a[i].l != -1)
            f[a[i].l] = 1;
        if (a[i].r != -1)
            f[a[i].r] = 1;
    }
    while (f[root])
        root++;
    string ans = dfs(root);
    ans = (ans[0] == '(') ? ans.substr(1, ans.size() - 2) : ans;
    cout << ans;
    return 0;
}//attention