// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    string s1, s2;
    unordered_map<char, int> mp;
    while (getline(cin, s1) && getline(cin, s2) && s1 != "#")
    {
        mp.clear();
        for (auto i : s1)
            mp[i] = 0;
        for (auto i : s2)
        {
            if (mp.count(i))
                mp[i]++;
        }
        for (auto i : s1)
            printf("%c %d\n", i, mp[i]);
    }
    return 0;
}