// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

#define test() freopen("in", "r", stdin)

using namespace std;
struct Node
{
    int local, data, next;
} nodes[100000];

int main(int argc, char const *argv[])
{
    /* code */
    test();
    int n, k, adr, addr_1st, walk;
    unordered_map<int, Node> m;
    vector<Node> l1, l2, l3, res;
    cin >> addr_1st >> n >> k;
    walk = addr_1st;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &adr);
        scanf("%d%d", &m[adr].data, &m[adr].next);
    }
    for (int i = 0; i < n; i++)
    {
        nodes[i] = {walk, m[walk].data, 0};
        walk = m[walk].next;
        if (walk == -1)
        {
            n = i + 1;
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (nodes[i].data < 0)
            l1.push_back(nodes[i]);
        else if (nodes[i].data >= 0 && nodes[i].data <= k)
            l2.push_back(nodes[i]);
        else if (nodes[i].data > k)
            l3.push_back(nodes[i]);
    }
    res.insert(res.begin(), l1.begin(), l1.end());
    res.insert(res.end(), l2.begin(), l2.end());
    res.insert(res.end(), l3.begin(), l3.end());

    for (int i = 0; i < n; i++)
    {
        printf("%05d %d ", res[i].local, res[i].data);
        if (i == n - 1)
            printf("-1");
        else
            printf("%05d\n", res[i + 1].local);
    }
    return 0;
}