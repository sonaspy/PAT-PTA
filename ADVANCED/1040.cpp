// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
deque<char> s1, s2;
string s;
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int res = 1;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++)
    {
        s1.clear(), s2.clear(), s1.push_back(s[i]), s2.push_front(s[i]);
        for (int j = i + 1; j < s.size(); j++)
        {
            s1.push_back(s[j]), s2.push_front(s[j]);
            if (s1 == s2 && int(s1.size()) > res)
                res = s1.size();
        }
    }
    cout << res;
    return 0;
}