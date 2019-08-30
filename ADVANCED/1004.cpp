// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, m, k, p, c, leafcnt, v;
    vector<int> tree[111];
    cin >> n >> m;
    if (n == 1)
    {
        cout << 1;
        return 0;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> p >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> c;
            tree[p].push_back(c);
        }
    }
    queue<int> q, nexq;
    for (auto i : tree[1])
        q.push(i);
    cout << 0;
    while (q.size())
    {
        leafcnt = 0;
        while (q.size())
        {
            v = q.front(), q.pop();
            if (tree[v].empty())
                leafcnt++;
            for (auto i : tree[v])
                nexq.push(i);
        }
        swap(q, nexq);
        printf(" %d", leafcnt);
    }
    return 0;
}