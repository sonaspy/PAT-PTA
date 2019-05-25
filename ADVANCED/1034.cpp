// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

typedef pair<unordered_set<string>, int> Gang;
int n, k, t;
unordered_map<string, vector<string>> mp;
unordered_map<string, int> mp1;
unordered_map<string, bool> vis;
map<string, int> res;
//attention
void DFS(const string &s, Gang &p)
{
    vis[s] = true;
    p.first.insert(s);
    p.second += mp1[s];
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
        mp1[s1] += t, mp1[s2] += t;
    }
    for (auto &i : mp)
    {
        if (!vis[i.first])
        {
            Gang myGang;
            myGang.second = 0;
            DFS(i.first, myGang);
            if (myGang.first.size() < 3 || myGang.second <= k * 2)
                continue;
            int max_t = 0;
            string head;
            for (auto &j : myGang.first)
                if (mp1[j] > max_t)
                {
                    max_t = mp1[j];
                    head = j;
                }
            res[head] = myGang.first.size();
        }
    }
    cout << res.size() << endl;
    for (auto &i : res)
        cout << i.first << " " << i.second << endl;
    return 0;
}