// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    string s, s1, res;
    s1.resize(1048576), s.resize(1048576);
    s1.clear(), s.clear();
    int maxtime = -1, c;
    getline(cin, s);
    unordered_map<string, int> mp;
    for (auto &i : s)
    {
        if (isupper(i))
            s1.push_back(i + 32);
        else if (isalnum(i))
            s1.push_back(i);
        else
            s1.push_back(' ');
    }
    stringstream ss(s1);
    while (ss >> s)
    {
        mp[s]++;
        c = mp[s];
        if (c > maxtime)
        {
            maxtime = c;
            res = s;
        }
    }
    cout << res << " " << maxtime;
    return 0;
}