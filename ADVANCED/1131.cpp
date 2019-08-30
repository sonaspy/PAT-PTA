// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
vector<int> mp[10000];
int vis[10000], minStops, mintrans, src, dst, stops;
unordered_map<int, int> whichLine;
vector<int> ansPath, tPath;
int get_trans_t(vector<int> &a)
{
    int T = 0, lastLine = 0, curline;
    for (int i = 1; i < a.size(); i++)
    {
        curline = whichLine[a[i - 1] * 10000 + a[i]];
        if (curline != lastLine)
            T++;
        lastLine = curline;
    }
    return T;
}
void dfs(int station)
{
    if (station == dst)
    {
        int trans = get_trans_t(tPath);
        if (stops < minStops || (stops == minStops && trans < mintrans))
            minStops = stops, mintrans = trans, ansPath = tPath;
        return;
    }
    for (auto i : mp[station])
        if (!vis[i])
        {
            tPath.push_back(i), vis[i] = 1, stops++;
            dfs(i);
            vis[i] = 0, tPath.pop_back(), stops--;
        }
}
int main(int argc, char const *argv[])
{
    int n, m, k, pre, temp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &m, &pre);
        for (int j = 1; j < m; j++)
        {
            scanf("%d", &temp);
            mp[pre].push_back(temp), mp[temp].push_back(pre);
            whichLine[pre * 10000 + temp] = whichLine[temp * 10000 + pre] = i + 1;
            pre = temp;
        }
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        scanf("%d%d", &src, &dst);
        minStops = 1 << 30, mintrans = 1 << 30;
        tPath.clear(), tPath.push_back(src), stops = 0;
        vis[src] = 1, dfs(src), vis[src] = 0;
        printf("%d\n", minStops);
        int lastLine = 0, start, curline;
        for (int j = 1; j < ansPath.size(); j++)
        {
            curline = whichLine[ansPath[j - 1] * 10000 + ansPath[j]];
            if (curline != lastLine)
            {
                if (lastLine)
                    printf("Take Line#%d from %04d to %04d.\n", lastLine, start, ansPath[j - 1]);
                lastLine = curline;
                start = ansPath[j - 1];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n", lastLine, start, dst);
    }
    return 0;
}