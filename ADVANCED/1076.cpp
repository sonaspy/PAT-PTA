// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
int n, threshold, num, k, tmp, vis[1010], sum_f, le;
vector<int> mp[1010];
inline void solve(int src)
{
    fill(vis, vis + 1010, 0);
    deque<int> Q, nexq;
    sum_f = 0;
    Q.push_back(src);
    vis[src] = 1;
    le = 0;
    while (Q.size())
    {
        le++;
        while (Q.size())
        {
            src = Q.front(), Q.pop_front();
            if (le <= threshold)
                for (auto &v : mp[src])
                {
                    if (!vis[v])
                    {
                        vis[v] = 1;
                        ++sum_f;
                        nexq.push_back(v);
                    }
                }
        }
        swap(nexq, Q);
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cin >> n >> threshold;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &num);
        for (int j = 0; j < num; ++j)
        {
            scanf("%d", &tmp);
            mp[tmp].push_back(i);
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