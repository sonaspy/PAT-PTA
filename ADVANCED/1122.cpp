// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, m, cnt, k, a[210][210] = {0}, i, flag;
    cin >> n >> m;
    for (i = 0; i < m; i++)
    {
        int t1, t2;
        scanf("%d%d", &t1, &t2);
        a[t1][t2] = a[t2][t1] = 1;
    }
    cin >> cnt;
    while (cnt--)
    {
        cin >> k;
        vector<int> v(k);
        unordered_set<int> s;
        flag = 1;
        for (i = 0; i < k; i++)
        {
            scanf("%d", &v[i]);
            if (i > 0 && !a[v[i - 1]][v[i]])
                flag = 0;
            s.insert(v[i]);
        }
        if (s.size() < n || k - 1 != n || v.front() != v.back())
            flag = 0;
        printf("%s\n", flag ? "YES" : "NO");
    }
    return 0;
}