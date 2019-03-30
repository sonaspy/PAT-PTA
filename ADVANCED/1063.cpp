// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>
#define test() freopen("in", "r", stdin)

using namespace std;
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, m, n1, a1, a2, tmp, nc, nt;
    cin >> n;
    set<int> v[n + 1];
    vector<int> v1;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &n1);
        for (int j = 0; j < n1; j++)
        {
            scanf("%d", &tmp);
            v[i].insert(tmp);
        }
    }
    cin >> m;w
    for (int i = 0; i < m; i++)
    {
        v1.clear();
        scanf("%d%d", &a1, &a2);
        set_intersection(v[a1].begin(), v[a1].end(), v[a2].begin(), v[a2].end(), back_inserter(v1));
        nc = v1.size();
        v1.clear();
        set_union(v[a1].begin(), v[a1].end(), v[a2].begin(), v[a2].end(), back_inserter(v1));
        nt = v1.size();
        printf("%.1f%%\n", nc*100.0/ nt);
    }
    return 0;
}