// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

struct Node
{
    int data, next, id = -1;
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int c1, d, c2, src, n, k, step = 0, i;
    Node mp[100000];
    deque<Node> res, tmp;
    cin >> src >> n >> k;
    for (i = 0; i < n; i++)
    {
        scanf("%d%d%d", &c1, &d, &c2);
        mp[c1].data = d, mp[c1].id = c1, mp[c1].next = c2;
    }
    for (int walk = src; walk != -1; walk = mp[walk].next, step++)
    {
        if (step % k == 0)
        {
            res.insert(res.end(), tmp.rbegin(), tmp.rend());
            tmp.clear();
        }
        tmp.push_back(mp[walk]);
    }
    if (step % k == 0)
        res.insert(res.end(), tmp.rbegin(), tmp.rend());
    else
        res.insert(res.end(), tmp.begin(), tmp.end());
    for (i = 0; i < res.size() - 1; i++)
        printf("%05d %d %05d\n", res[i].id, res[i].data, res[i + 1].id);
    printf("%05d %d -1\n", res[i].id, res[i].data);
    return 0;
}