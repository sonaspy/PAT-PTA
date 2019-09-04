// author -sonaspy@outlook.com
// coding - utf_8
#include <bits/stdc++.h>
#define test() freopen("in", "r", stdin)
#define MAXN 10005
using namespace std;
set<int> difGender[MAXN], sameGender[MAXN];
string c, d;
int main(int argc, char const *argv[])
{
    //test();
    int n, m, k, src, dst;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        cin >> c >> d;
        src = abs(stoi(c)), dst = abs(stoi(d));
        if (c.size() != d.size())
            difGender[src].insert(dst), difGender[dst].insert(src);
        else
            sameGender[src].insert(dst), sameGender[dst].insert(src);
    }
    scanf("%d", &k);
    for (int i = 0; i < k; ++i)
    {
        cin >> c >> d;
        src = abs(stoi(c)), dst = abs(stoi(d));
        vector<pair<int, int>> ans;
        for (auto &v1 : sameGender[src])
            for (auto &v2 : (c.size() == d.size() ? sameGender[v1] : difGender[v1]))
                if (v1 != dst && v2 != src && v1 != src && v2 != dst && sameGender[v2].count(dst))
                    ans.push_back(make_pair(v1, v2));
        printf("%lu\n", ans.size());
        for (auto i : ans)
            printf("%04d %04d\n", i.first, i.second);
    }
}