// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
int main(int argc, char const *argv[])
{
    /* code */
    test();
    string s, ans;
    cin >> s;
    if (s[0] == '-') ans += '-';
    int indexE = s.find("E");
    string num = s.substr(1, indexE - 1);
    char x = s[indexE + 1];
    cout << indexE <<endl;
    string exp = s.substr(indexE + 2, s.size() - indexE - 2);
    int e = stoi(exp);
    if (x == '+')
    { 
        if (e < num.size() - 2)
            ans += num[0] + num.substr(2, e) + "." + num.substr(e + 2, num.size() - e - 2);
        else
        {
            num.erase(num.begin()+1), ans += num;
            for (int i = 0; i < e - (num.size() -1) ; i++)
                ans += "0";
        }
    }
    if (x == '-')
    { 
        ans += "0.";
        while (--e) ans += "0";
        num.erase(num.begin() + 1), ans += num;
    }
    cout << ans << endl;
    return 0;
}