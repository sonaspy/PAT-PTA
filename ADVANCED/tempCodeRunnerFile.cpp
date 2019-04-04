// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

string s;
int valid;
double ans;
inline void Solve()
{
    smatch r[2];
    regex rg[2];
    string ss[2];
    rg[0] = ("[+-]\\d+\\.\\d+"), rg[1] = ("[+-][0-9]+[^.]");
    for (int i = 0; i < 2; i++)
    {
        regex_search(s, r[i], rg[i]);
        ss[i] = r[i].str();
    }
    if (ss[0].size() - 3 - stoi(ss[1]) <= 0 )
        valid = 0;
    else valid = ss[0].size() - 3 - stoi(ss[1]);
    ans = stod(ss[0]) * pow(10, stoi(ss[1]));
}
int main(int argc, char const *argv[])
{
    /* code */
    test();
    cin >> s;
    Solve();
    cout.setf(ios::fixed);
    cout << setprecision(valid) << ans;
    return 0;
}