// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, m;
    cin >> n;
    unordered_map<string, set<int>> search_mp[5];
    for (int i = 0; i < n; i++)
    {
        int id;
        string keyword, author, title, publisher, year;
        vector<string> keywords;
        cin >> id;
        getchar(), getline(cin, title), getline(cin, author), getline(cin, keyword), getline(cin, publisher);
        cin >> year;
        keyword.push_back(' ');
        for (int i = 0, t = 0; i < keyword.size(); i++)
            if (keyword[i] == ' ')
            {
                keywords.push_back(keyword.substr(t, i - t));
                t = i + 1;
            }
        search_mp[0][title].insert(id), search_mp[1][author].insert(id);
        for (auto j : keywords)
            search_mp[2][j].insert(id);
        search_mp[3][publisher].insert(id), search_mp[4][year].insert(id);
    }
    cin >> m;
    getchar();
    for (int i = 0; i < m; i++)
    {
        string s;
        getline(cin, s);
        cout << s << endl;
        int s_id = s[0] - '0' - 1;
        s = s.substr(3, s.size() - 3);
        if (search_mp[s_id][s].empty())
        {
            cout << "Not Found" << endl;
            continue;
        }
        for (auto j : search_mp[s_id][s])
            printf("%07d\n", j);
    }
    return 0;
}