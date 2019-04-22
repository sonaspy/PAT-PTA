// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)
#define MAXBOUND 20
using namespace std;
struct nodes
{
    int l = -1, r = -1, id = 0, isleft = -1, p, cur = 0;
} nodes[22];
int n, c1, c2, root, i, iscmt = 1, tree[22], ans;
inline void level()
{
    queue<int> q;
    int id, v;
    fill(tree, tree + 22, -1);
    tree[0] = root;
    q.push(root);
    while (q.size())
    {
        v = q.front();
        q.pop();
        if (nodes[v].l != -1)
            q.push(nodes[v].l);
        if (nodes[v].r != -1)
            q.push(nodes[v].r);
        if (nodes[v].isleft == 1)
        {
            id = nodes[nodes[v].p].cur * 2 + 1;
            nodes[v].cur = id;
            if (id < MAXBOUND)
                tree[id] = nodes[v].id;
        }
        else if (nodes[v].isleft == 0)
        {
            id = nodes[nodes[v].p].cur * 2 + 2;
            nodes[v].cur = id;
            if (id < MAXBOUND)
                tree[id] = nodes[v].id;
        }
        if (q.empty())
            ans = v;
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    string s1, s2;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> s1 >> s2;
        nodes[i].id = i;
        if (s1 != "-")
        {
            nodes[i].l = stoi(s1);
            nodes[nodes[i].l].p = i;
            nodes[nodes[i].l].isleft = 1;
        }
        if (s2 != "-")
        {
            nodes[i].r = stoi(s2);
            nodes[nodes[i].r].p = i;
            nodes[nodes[i].r].isleft = 0;
        }
    }
    for (i = 0; i < n && nodes[i].isleft != -1; i++)
        ;
    root = i;
    level();
    for (i = 0; i < n; i++)
        if (tree[i] == -1)
        {
            iscmt = 0;
            break;
        }
    cout << (iscmt ? "YES " : "NO ");
    cout << (iscmt ? ans : root);
    return 0;
}