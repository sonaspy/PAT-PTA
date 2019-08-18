// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <set>
#include <queue>

using namespace std;

int N, E, v1, v2, v;
vector<int> vis(500, 0);
set<int> mp[500];

void DFS(int id)
{
    vis[id] = 1;
    cout << " " << id;
    for (auto i : mp[id])
    {
        if (!vis[i])
            DFS(i);
    }
}

void BFS(int id)
{
    queue<int> q;
    q.push(id);
    vis[id] = 1;
    while (q.size())
    {
        v = q.front(), q.pop();
        cout << " " << v;
        for (auto i : mp[v])
        {
            if (!vis[i])
            {
                vis[i] = 1;
                q.push(i);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    freopen("in", "r", stdin);
    cin >> N >> E;
    while (E--)
    {
        cin >> v1 >> v2;
        mp[v1].insert(v2), mp[v2].insert(v1);
    }
    for (int i = 0; i < N; i++)
        if (!vis[i])
        {
            cout << "{";
            DFS(i);
            cout << " }\n";
        }
    fill(vis.begin(), vis.end(), 0);
    for (int i = 0; i < N; i++)
        if (!vis[i])
        {
            cout << "{";
            BFS(i);
            cout << " }\n";
        }
    return 0;
}