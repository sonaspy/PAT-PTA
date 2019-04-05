// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
int main(int argc, char const *argv[])
{
    /* code */
    string s, ans;
    cin >> s;
    if (s[0] == '-')
        ans = "-";
    int indexE = s.find("E");
    string num = s.substr(1, indexE - 1);
    char x = s[indexE + 1];
    string exp = s.substr(indexE + 2, s.size() - indexE - 2);
    int E = stoi(exp);
    if (x == '+')
    {
        if (E < num.size() - 2)
            ans += num[0] + num.substr(2, E) + "." + num.substr(E + 2, num.size() - E - 2);
        else
        {
            num.erase(num.begin() + 1), ans += num;
            for (int i = 0; i < E - (num.size() - 1); i++)
                ans.push_back('0');
        }
    }
    else
    {
        ans += "0.";
        while (--E) ans.push_back('0');
        num.erase(num.begin() + 1), ans += num;
    }
    cout << ans << endl;
    return 0;
}