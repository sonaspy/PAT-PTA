// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    string system[20] = {" ", "Yi", "Wan", "Qian", "Bai", "Shi"},
           nums[20] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"},
           s, res;
    cin >> s;
    if (s[0] == '-')
    {
        res += "Fu ";
        s = s.substr(1, s.size() - 1);
    }
    if(s == "0"){cout << "ling" <<endl;return 0;}
    int mp[] = {0, 5, 4, 3, 2, 5, 4, 3, 1}, c = s.size() - 1, last = -1;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != '0' || ((c != 4 && c != 0) && s[i] == '0' && s[i + 1] != '0'))
            res += (nums[s[i] - '0']) + " ";
        if ((c == 4 || s[i] != '0') && c!= 0)
            res += system[mp[c]] + " ";
        c--;
    }
    res.pop_back();
    cout << res;
    return 0;
}