// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
struct Node
{
    int id = -1, data, next;
} nodes[100000];
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    vector<Node *> l1, l2;
    int src1, src2, n, a1, a3, walk;
    char a2;
    cin >> src1 >> src2 >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %c %d", &a1, &a2, &a3);
        nodes[a1].next = a3;
        nodes[a1].id = a1;
        nodes[a1].data = a2;
    }
    walk = src1;
    while (walk != -1 && nodes[walk].id != -1)
    {
        l1.push_back(nodes + walk);
        walk = nodes[walk].next;
    }
    walk = src2;
    while (walk != -1 && nodes[walk].id != -1)
    {
        l2.push_back(nodes + walk);
        walk = nodes[walk].next;
    }
    bool f = false;
    for (a1 = l1.size() - 1, a3 = l2.size() - 1; a1 > -1 && a3 > -1 && l1[a1] == l2[a3]; a1--, a3--)
        f = true;
    if (!f)
        cout << -1;
    else
        cout << l1[a1 + 1]->id;
    return 0;
}