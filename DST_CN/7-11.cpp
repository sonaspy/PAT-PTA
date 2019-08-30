// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
#define MAX_V 222
int n, m;
vector<vector<int>> mp(MAX_V, vector<int>(MAX_V, 1 << 30)), post(MAX_V), pre(MAX_V);
vector<pair<int, int>> keypath;
vector<int> indegree(MAX_V, 0), outdegree(MAX_V, 0), Flexible_time(MAX_V, 0), Earliest(MAX_V, 0), Latest(MAX_V, 1 << 30);
bool KeyAction()
{
    int dst, cnt = 0;
    deque<int> dq;
    for (int i = 1; i <= n; i++)
    {
        if (!indegree[i])
        {
            dq.push_back(i);
            Earliest[i] = 0;
        }
    }
    while (dq.size())
    {
        int V = dq.front();
        dq.pop_front();
        cnt++;
        for (auto i : post[V])
        {
            Earliest[i] = max(Earliest[i], mp[V][i] + Earliest[V]);
            if (--indegree[i] == 0)
                dq.push_back(i);
        }
    }
    if (cnt < n)
        return 0;
    dst = max_element(Earliest.begin(), Earliest.begin() + n + 1) - Earliest.begin();
    cout << (Latest[dst] = Earliest[dst]) << endl;
    dq.clear();
    dq.push_back(dst);
    while (dq.size())
    {
        int V = dq.front();
        dq.pop_front();
        for (auto i : pre[V])
        {
            Latest[i] = min(Latest[i], Latest[V] - mp[i][V]);
            if (--outdegree[i] == 0)
                dq.push_back(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (pre[i].empty())
            Flexible_time[i] = 0;
        else
        {
            for (auto j : pre[i])
            {
                Flexible_time[i] = max(Flexible_time[i], Latest[i] - Earliest[j] - mp[j][i]);
                if (!Flexible_time[i])
                    keypath.push_back(make_pair(j, i));
            }
        }
    }
    keypath.push_back(make_pair(keypath.back().second, dst));
    for (auto it : keypath)
    {
        cout << it.first << "->" << it.second << "\n";
    }
    return 1;
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int a1, a2, a3;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a1 >> a2 >> a3;
        outdegree[a1]++, indegree[a2]++;
        mp[a1][a2] = a3;
        pre[a2].push_back(a1), post[a1].push_back(a2);
    }
    if (!KeyAction())
        cout << 0;
    return 0;
}