// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    string s;
    int n = 0, c;
    cin >> s;
    for (auto i : s)
    {
        if (isdigit(i))
            c = i - '0';
        else
            c = i - 'a' + 10;
        cout << c << ' ';
        n += c;
    }
    cout << endl;
    cout << n << endl;
    bitset<32> b(n);
    s = b.to_string();
    for (int i = 0; i < s.size(); i++)
    {
        if (i != 0 && i % 8 == 0)
            cout << " ";
        cout << s[i];
    }
    return 0;
}