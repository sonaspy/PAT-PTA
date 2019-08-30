// author - sonaspy@outlook.com
// coding - utf_8

#include <iostream>
#include <vector>
#include <queue>
#include<cstring>
#define test() freopen("in", "r", stdin)
using namespace std;
vector<int> map[10001];
int bfs(int start)
{
    int end = start, cnt = 1, level = 0;
    queue<int> q;
    bool vis[10001];
    memset(vis, false, sizeof(vis));
    q.push(start);
    vis[start] = true;
    while(q.size())
        {
            int temp = q.front(), t;
            q.pop();
            for(auto i : map[temp])
                {
                    if(!vis[i])
                        {
                            vis[i] = true;
                            q.push(i);
                            t = i;
                            cnt++;
                        }
                }
            if(temp == end)
                {
                    end = t;
                    level++;
                    if(level == 6) break;
                }
        }
    return cnt;
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        {
            scanf("%d%d", &a, &b);
            map[a].push_back(b);
            map[b].push_back(a);
        }
    for (int i = 1; i <= n; i++)
        printf("%d: %.2lf%%\n", i, bfs(i) * 1.0 / n * 100.0);
    return 0;
}