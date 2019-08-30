// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int n, m, x, y, cnt, level, v;
vector<int> MAP[10001], vis(10001, 0);
void BFS(int id)
{
    queue<int> q, nex_q;
    cnt = 1, level = 0;
    q.push(id);
    vis[id] = 1;
    while (q.size())
    {
        while (q.size())
        {
            v = q.front(), q.pop();
            for (auto i : MAP[v])
            {
                if (!vis[i])
                {
                    vis[i] = 1;
                    cnt++;
                    nex_q.push(i);
                }
            }
        }
        swap(nex_q, q);
        level++;
        if (level == 6)
            break;
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
        MAP[x].push_back(y), MAP[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        fill(vis.begin(), vis.end(), 0);
        BFS(i);
        printf("%d: %.2f%%\n", i, cnt * 100.0 / n);
    }
    return 0;
}