// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
vector<int> mp[10010];
unordered_set<int> Color;
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, m, v1, v2, k, c;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &v1, &v2);
        mp[v1].push_back(v2), mp[v2].push_back(v1);
    }
    cin >> k;
    while (k--)
    {
        vector<int> color(n);
        Color.clear();
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &color[i]);
            Color.insert(color[i]);
        }
        for (int i = 0; i < n; i++)
        {
            for (auto j : mp[i])
                if (color[j] == color[i])
                {
                    flag = false;
                    goto end;
                }
        }
    end:
        !flag ? printf("No\n") : printf("%lu-coloring\n", Color.size());
    }
    return 0;
}