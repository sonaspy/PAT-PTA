// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

inline bool isParlin(unsigned long long num)
{
    string s = to_string(num), s1 = s;
    reverse(s.begin(), s.end());
    return s == s1;
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    unsigned long long num;
    int n, cnt = 0;
    cin >> num >> n;
    while (cnt < n && !isParlin(num))
    {
        cnt++;
        string s = to_string(num);
        reverse(s.begin(), s.end());
        num += stoull(s);
    }
    cout << num << endl << cnt;
    return 0;
}