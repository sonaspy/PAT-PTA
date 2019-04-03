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
    vector<int> m_containter;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &n1);
        for (int j = 0; j < n1; j++)
        {
            scanf("%d", &tmp);
            v[i].insert(tmp);
        }
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        m_containter.clear();
        scanf("%d%d", &a1, &a2);
        set_intersection(v[a1].begin(), v[a1].end(), v[a2].begin(), v[a2].end(), back_inserter(m_containter));
        nc = m_containter.size();
        m_containter.clear();
        set_union(v[a1].begin(), v[a1].end(), v[a2].begin(), v[a2].end(), back_inserter(m_containter));
        nt = m_containter.size();
        printf("%.1f%%\n", nc*100.0/ nt);
    }
    return 0;
}