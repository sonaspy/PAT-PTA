// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <regex>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <vector>
#define test() freopen("in", "r", stdin)

using namespace std;
typedef pair<unordered_set<string>, int> mypair;
int n, k, t;
unordered_map<string, vector<string>> mp;
unordered_map<string, int> mp1;
unordered_map<string, bool> vis;
vector<mypair> gangs;
map<string, int> res;
//attention
void DFS(const string &s, mypair& p)
{
    vis[s] = true;
    p.first.insert(s);
    p.second += mp1[s];
    for (auto i : mp[s])
    {
        if (!vis[i])
            DFS(i, p);
    }
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
    for (auto i : mp)
    {
        if (!vis[i.first])
        {
            mypair myp;
            myp.second = 0;
            DFS(i.first, myp);
            gangs.push_back(myp);
        }
    }
    for (auto i : gangs)
    {
        if (i.first.size() < 3 || i.second / 2 <= k)continue;
        int max = 0;
        string head;
        for (auto j : i.first)
            if (mp1[j] > max)
            {
                max = mp1[j];
                head = j;
            }
        res[head] = i.first.size();
    }
    cout << res.size() << endl;
    for(auto i : res)cout << i.first << " " <<i.second <<endl;
    return 0;
}