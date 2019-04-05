// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
int n, level, num, k, tmp, vis[1010], sum_f, le[1010];
vector<int> BUCKET[1010];
inline void solve(int src)
{
    fill(vis, vis + 1010, 0);
    fill(le, le + 1010, 0);
    deque<int> Q;
    sum_f = 0;
    Q.push_back(src);
    vis[src] = 1;
    while (Q.size())
    {
        src = Q.front(), Q.pop_front();
        if (le[src] < level)
            for (int ip : BUCKET[src])
            {
                if (!vis[ip])
                {
                    ++sum_f;
                    vis[ip] = 1;
                    le[ip] = le[src] + 1;
                    Q.push_back(ip);
                }
            }
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cin >> n >> level;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &num);
        for (int j = 0; j < num; ++j)
        {
            scanf("%d", &tmp);
            BUCKET[tmp].push_back(i);
        }
    }
    cin >> k;
    for (int i = 0; i < k; ++i)
    {
        scanf("%d", &tmp);
        solve(tmp);
        cout << sum_f << endl;
    }
    return 0;
}