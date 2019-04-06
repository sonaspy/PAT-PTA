// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
int n, min_s = 1 << 30;
string s[101];

inline bool isEqual(int cur)
{
    for (int i = 1; i < n; i++)
        if (s[i][cur] != s[0][cur])
            return false;
    return true;
}

int main(int argc, char const *argv[])
{
    /* code */
    test();
    cin >> n;
    cin.get();
    deque<char> res;
    for (int i = 0; i < n; i++)
    {
        getline(cin, s[i]);
        if (s[i].size() < min_s)
            min_s = s[i].size();
        reverse(s[i].begin(), s[i].end());
    }
    for (int i = 0; i < min_s; i++)
    {
        if (!isEqual(i))
            break;
        else
            res.push_front(s[0][i]);
    }
    if (res.empty())
        cout << "nai";
    for (auto i : res)
        cout << i;
    return 0;
}