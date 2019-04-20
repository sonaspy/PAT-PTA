// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

struct Node
{
    double p = 0.0;
    vector<int> sub;
} nodes[100001];
int n, num, tmp, root = 0, res = 0;
double price, per;
double ans = 99999999.999;

void BFS()
{
    queue<int> q;
    int v;
    bool f;
    double p;
    q.push(root);
    while (q.size())
    {
        v = q.front();
        q.pop();
        p = nodes[v].p;
        f = false;
        for (auto i : nodes[v].sub)
        {
            q.push(i);
            nodes[i].p = p + (p * per) / 100;
            f = true;
        }
        if (!f && p < ans)
            ans = p;
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cin >> n >> price >> per;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        for (int j = 0; j < num; j++)
        {
            scanf("%d", &tmp);
            nodes[i].sub.push_back(tmp);
        }
    }
    nodes[root].p = price;
    BFS();
    for (int i = 0; i < n; i++)
    {
        if (nodes[i].sub.empty() && nodes[i].p == ans)
            res++;
    }
    printf("%.4f %d", ans, res);
    return 0;
}