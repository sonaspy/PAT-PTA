// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int n, k, t;
typedef pair<vector<string>, int> Gang;
unordered_map<string, vector<string>> mp;
unordered_map<string, int> totalW, vis;
map<string, int> res;
void DFS(const string &s, Gang &p)
{
    vis[s] = true;
    p.first.push_back(s);
    p.second += totalW[s];
    for (auto &i : mp[s])
        if (!vis[i])
            DFS(i, p);
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        string s1, s2;
        cin >> s1 >> s2 >> t;
        mp[s1].push_back(s2), mp[s2].push_back(s1);
        totalW[s1] += t, totalW[s2] += t;
    }
    for (auto &i : mp)
    {
        if (!vis[i.first])
        {
            Gang tmpGang;
            tmpGang.second = 0;
            DFS(i.first, tmpGang);
            if (tmpGang.first.size() < 3 || tmpGang.second <= k * 2)
                continue;
            int max_t = 0;
            string head;
            for (auto &j : tmpGang.first)
                if (totalW[j] > max_t)
                {
                    max_t = totalW[j];
                    head = j;
                }
            res[head] = tmpGang.first.size();
        }
    }
    cout << res.size() << endl;
    for (auto &i : res)
        cout << i.first << " " << i.second << endl;
    return 0;
}