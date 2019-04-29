// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, m, cnt, k, a[210][210] = {0}, i;
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
        for (i = 0; i < k; i++)
        {
            scanf("%d", &v[i]);
            s.insert(v[i]);
        }
        if (s.size() < n || k - 1 != n || v.front() != v.back())
        {
            printf("NO\n");
            continue;
        }
        for (i = 0; i < k - 1 && a[v[i]][v[i + 1]]; i++)
            ;
        printf("%s\n", i == k - 1 ? "YES" : "NO");
    }
    return 0;
}//attention