// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
string s, s1;
template <class T>
bool isparlindrome(T lo, T hi)
{
    if (lo < hi)
        for (; lo < --hi; ++lo)
            if (*lo != *hi)
                return false;
    return true;
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int res = 1;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++)
    {
        s1.clear(), s1.push_back(s[i]);
        for (int j = i + 1; j < s.size(); j++)
        {
            s1.push_back(s[j]);
            if (isparlindrome(s1.begin(), s1.end()) && s1.size() > res)
                res = s1.size();
        }
    }
    cout << res;
    return 0;
}