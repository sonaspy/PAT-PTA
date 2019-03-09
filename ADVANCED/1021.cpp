// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <vector>
#include <algorithm>
#define test() freopen("in", "r", stdin)
#define _MAX_NUM_ 10001
using namespace std;
int vis[_MAX_NUM_], n, deep[_MAX_NUM_];
vector<int> map[_MAX_NUM_];

void DFS(int id)
{
    vis[id] = 1;
    for (auto i : map[id])
        if (!vis[i])
            DFS(i);
}

void solve(int id, int root)
{
    static int depth = 0;
    vis[id] = 1, depth++;
    for (auto i : map[id])
        {
            if(!vis[i]) solve(i, root);
        }
    if(depth > deep[root])deep[root] = depth;
    depth--;
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cin >> n;
    for (int i = 0; i < n - 1; i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            map[a].push_back(b);
            map[b].push_back(a);
        }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
                {
                    cnt++;
                    DFS(i);
                }
        }
    if (cnt > 1)
        {
            printf("Error: %d components", cnt);
            return 0;
        }
    for (int i = 1; i <= n; i++)
        {
            fill(vis, vis + _MAX_NUM_, 0);
            solve(i, i);
        }
    int max = -1;
    for(int i = 1; i <= n; i++)
        {
            if(deep[i] > max) max = deep[i];
        }
    for(int i = 1; i <= n; i++)
        if(deep[i] == max) printf("%d\n",i);
    return 0;
}