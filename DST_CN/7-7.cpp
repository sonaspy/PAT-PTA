// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int n, m, x, y, cnt, vis[10001] = {0}, level, last, tail;
vector<int> MAP[10001];
void BFS(int walk)
{
    deque<int> dq;
    cnt = 1, level = 0, last = walk;
    dq.push_back(walk);
    vis[walk] = 1;
    while (dq.size() && level < 6)
    {
        int t = dq.front();
        dq.pop_front();
        for (auto i : MAP[t])
        {
            if (!vis[i])
            {
                vis[i] = 1;
                cnt++;
                dq.push_back(i);
                tail = i;
            }
        }
        if (t == last)
        {
            level++;
            last = tail;
        }
    }
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &x, &y);
        MAP[x].push_back(y);
        MAP[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        fill(vis, vis + n + 1, 0);
        BFS(i);
        printf("%d: %.2f%%\n", i, cnt * 100.0 / n);
    }

    return 0;
}