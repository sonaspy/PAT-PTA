// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

bool cmp(string s1, string s2) { return s1 + s2 < s2 + s1; }
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, j = -1;
    cin >> n;
    string s, res;
    vector<string> l(n);
    for (int i = 0; i < n; i++)
        cin >> l[i];
    sort(l.begin(), l.end(), cmp);
    for (auto i : l)
        res += i;
    while (res[++j] == '0')
        ;
    if (j == res.size())
        cout << 0;
    else
        cout << res.substr(j, res.size() - j);
    return 0;
}