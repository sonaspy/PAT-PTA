// author - newguo@sonaspy.cn
// coding - utf_8
#include <bits/stdc++.h>
#define test() freopen("in", "r", stdin)
#define MAXN 10005
using namespace std;
set<int> difGender[MAXN], sameGender[MAXN];
char c[10], d[10];
int main(int argc, char const *argv[])
{
    //test();
    int n, m, k, src, dst, lenc, lend;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        scanf("%s%s", c, d);
        lenc = strlen(c), lend = strlen(d);
        src = abs(atoi(c)), dst = abs(atoi(d));
        if (lenc != lend)
            difGender[src].insert(dst), difGender[dst].insert(src);
        else
            sameGender[src].insert(dst), sameGender[dst].insert(src);
    }
    scanf("%d", &k);
    for (int i = 0; i < k; ++i)
    {
        scanf("%s%s", c, d);
        lenc = strlen(c), lend = strlen(d);
        src = abs(atoi(c)), dst = abs(atoi(d));
        vector<pair<int, int>> ans;
        for (auto v1 : sameGender[src])
            for (auto v2 : (lenc == lend ? sameGender[v1] : difGender[v1]))
                if (v1 != dst && v2 != src && v1 != src && v2 != dst && sameGender[v2].count(dst))
                    ans.push_back(make_pair(v1, v2));
        printf("%lu\n", ans.size());
        for (auto i : ans)
            printf("%04d %04d\n", i.first, i.second);
    }
}