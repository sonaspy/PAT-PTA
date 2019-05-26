// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

struct Node
{
    string user_id, password;
    bool isMod;
};
vector<Node> userlist;
unordered_map<char, char> mp;
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n;
    cin >> n;
    mp['1'] = '@', mp['0'] = '%', mp['l'] = 'L', mp['O'] = 'o';
    for (int i = 0; i < n; i++)
    {
        string s, s1;
        cin >> s >> s1;
        userlist.push_back({s, s1, false});
    }
    int isMod = 0;
    for (int i = 0; i < userlist.size(); i++)
    {
        for (int j = 0; j < userlist[i].password.size(); j++)
        {
            if (mp.count(userlist[i].password[j]))
            {
                userlist[i].isMod = true;
                userlist[i].password[j] = mp[userlist[i].password[j]];
            }
        }
        if (userlist[i].isMod)
            isMod++;
    }
    if (isMod)
    {
        cout << isMod << endl;
        for (auto i : userlist)
            if (i.isMod)
                printf("%s %s\n", i.user_id.c_str(), i.password.c_str());
    }
    else
        cout << "There " << (n > 1 ? "are " : "is ") << n << " account" << (n > 1 ? "s" : "") << " and no account is modified";
    return 0;
}