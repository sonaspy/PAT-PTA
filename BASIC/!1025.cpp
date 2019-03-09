// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <map>
#include <algorithm>

#define test() freopen("in", "r", stdin)

using namespace std;
struct Node
{
    int local, data, next;
} nodes[100000];

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, k, add, start, walk;
    map<int, Node> m;
    cin >> start >> n >> k;
    walk = start;
    for (int i = 0; i < n; i++)
        {
            scanf("%d", &add);
            scanf("%d%d", &m[add].data, &m[add].next);
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
            if ((i + 1) % k == 0)
                reverse(nodes + i + 1 - k, nodes + i + 1);
        }
    for (int i = 0; i < n; i++)
        {
            printf("%05d %d ", nodes[i].local, nodes[i].data);
            if (i == n - 1)
                printf("-1");
            else
                printf("%05d\n", nodes[i + 1].local);
        }
    return 0;
}