// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
int indegree[1001] = {0}, nonfirst = 0, topOrder[1001] = {0}, n, m, k, a1, a2;
vector<int> MAP[1001];
bool Judge()
{
    vector<int> indgr(indegree, indegree + 1001);
    for (int i = 0; i < n; i++)
    {
        int V = topOrder[i];
        if (indgr[V])
            return false;
        for (auto w : MAP[V])
            indgr[w]--;
    }
    return true;
}
int main(int argc, char const *argv[])
{
    /* code */
    test();
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &a1, &a2);
        MAP[a1].push_back(a2);
        indegree[a2]++;
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
            scanf("%d", &topOrder[j]);
        if (!Judge())
        {
            if (nonfirst)
                cout << " ";
            cout << i;
            nonfirst = 1;
        }
    }

    return 0;
}