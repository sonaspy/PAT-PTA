// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    string s, zoj = "ZOJ";
    cin >> s;
    unordered_map<char, int> mp;

    for (auto i : s)
    {
        mp[i]++;
    }
    while (mp.size())
    {
        for (auto i : zoj)
        {
            if (mp.count(i))
            {
                mp[i]--;
                if (mp[i] == 0)
                    mp.erase(i);
                cout << i;
            }
        }
    }
    return 0;
}