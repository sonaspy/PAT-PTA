// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
inline bool ispalindromic(string s)
{
    auto lo = s.begin(), hi = s.end();
    for (; lo < --hi; ++lo)
        if (*lo != *hi)
            return false;
    return true;
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int64_t num, num2, i;
    string n;
    cin >> n;
    for (i = 0; !ispalindromic(n) && i < 10; i++)
    {
        num = stoll(n);
        string tmp(n);
        reverse(tmp.begin(), tmp.end());
        num2 = stoll(tmp);
        printf("%s + %s = %s\n", n.c_str(), tmp.c_str(), to_string(num + num2).c_str());
        n = to_string(num + num2);
    }
    ispalindromic(n) ? printf("%s is a palindromic number.\n", n.c_str()) : printf("Not found in 10 iterations.");
    return 0;
}