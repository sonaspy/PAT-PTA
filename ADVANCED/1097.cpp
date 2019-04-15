// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
struct Node
{
    int id = -1, data, next;
} nodes[100000];
int st[10000] = {0};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    vector<Node *> ls, rm;
    int src, n, a1, a2, a3, walk, abs_d, size_;
    cin >> src >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &a1, &a2, &a3);
        nodes[a1].next = a3;
        nodes[a1].id = a1;
        nodes[a1].data = a2;
    }
    walk = src;
    while (walk != -1 && nodes[walk].id != -1)
    {
        abs_d = abs(nodes[walk].data);
        if (!st[abs_d])
        {
            st[abs_d] = 1;
            ls.push_back(nodes + walk);
        }
        else
            rm.push_back(nodes + walk);
        walk = nodes[walk].next;
    }
    for (int i = 0; i < ls.size(); i++)
    {
        printf("%05d %d ", ls[i]->id, ls[i]->data);
        i == ls.size() - 1 ? printf("-1\n") : printf("%05d\n", ls[i + 1]->id);
    }
    for (int i = 0; i < rm.size(); i++)
    {
        printf("%05d %d ", rm[i]->id, rm[i]->data);
        i == rm.size() - 1 ? printf("-1\n") : printf("%05d\n", rm[i + 1]->id);
    }
    return 0;
}