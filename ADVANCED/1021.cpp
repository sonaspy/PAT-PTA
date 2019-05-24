// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
#define _MAX_NUM_ 10001
int vis[_MAX_NUM_], n, deep[_MAX_NUM_], depth = 0;
vector<int> MAP[_MAX_NUM_];
void dfs_count(int walk)
{
    vis[walk] = 1;
    for (auto i : MAP[walk])
        if (!vis[i])
            dfs_count(i);
}

void dfs(int walk, int root)
{
    vis[walk] = 1, depth++;
    for (auto i : MAP[walk])
    {
        if (!vis[i])
            dfs(i, root);
    }
    deep[root] = max(deep[root], depth);
    depth--;
}
// void bfs(int walk, int root){
//     deque<int> q, nexq;
//     int d = 0;
//     q.push_back(walk);
//     while (q.size())
//     {
//         while (q.size())
//         {
//             walk = q.front(), q.pop_front();
//             vis[walk] = 1;
//             for (auto i : MAP[walk])
//                 if (!vis[i])
//                     nexq.push_back(i);
//         }
//         swap(nexq, q);
//         d++;
//     }
//     deep[root] = d;
// }
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        MAP[a].push_back(b), MAP[b].push_back(a);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            cnt++;
            dfs_count(i);
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
        dfs(i, i);
    }
    int max = *max_element(deep + 1, deep + n + 1);
    for (int i = 1; i <= n; i++)
        if (deep[i] == max)
            printf("%d\n", i);
    return 0;
}