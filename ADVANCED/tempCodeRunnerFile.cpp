// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
struct node
{
    int id, father = -1, mother = -1, m_es = 0, t_area = 0;
    vector<int> sub;
} nodes[10000];

int main(int argc, char const *argv[])
{
    /* code */
    test();
    int n, id, num, i, j, tmp;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &id), nodes[id].id = id, scanf("%d%d%d", &nodes[id].father, &nodes[id].mother, &num);
        for (j = 0; j < num; j++)
        {
            scanf("%d", &tmp);
            nodes[id].sub.push_back(tmp);
        }
        scanf("%d%d", &nodes[id].m_es, &nodes[id].t_area);
    }
    return 0;
}