// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
typedef long long ll;
inline bool ispalin(string s)
{
    string s1 = s;
    reverse(s1.begin(), s1.end());
    return s1 == s;
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    ll num, num2, i;
    string n;
    cin >> n;
    for (i = 0; !ispalin(n) && i < 10; i++)
    {
        num = stoll(n);
        string n2(n);
        reverse(n2.begin(), n2.end());
        num2 = stoll(n2);
        printf("%s + %s = %s\n", n.c_str(), n2.c_str(), to_string(num + num2).c_str());
        n = to_string(num + num2);
    }
    ispalin(n) ? printf("%s is a palindromic number.\n", n.c_str()) : printf("Not found in 10 iterations.");
    return 0;
}