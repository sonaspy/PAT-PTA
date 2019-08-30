// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
// * 1e4
struct Node
{
    double store;
    double totalprice;
};
bool cmp(const Node &a, const Node &b) { return (a.totalprice * b.store) > (b.totalprice * a.store); }

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n;
    double need;
    double profit = 0.0;
    cin >> n >> need;
    struct Node nodes[n];
    for (int i = 0; i < n; i++)
        scanf("%lf", &nodes[i].store);
    for (int i = 0; i < n; i++)
        scanf("%lf", &nodes[i].totalprice);
    sort(nodes, nodes + n, cmp);
    for (int i = 0; i < n && need > 0; i++)
    {
        if (nodes[i].store <= need)
        {
            profit += nodes[i].totalprice;
            need -= nodes[i].store;
        }
        else
        {
            profit += 1.0 * need * nodes[i].totalprice / nodes[i].store;
            need = 0;
        }
    }
    printf("%.2f", profit);
    return 0;
}