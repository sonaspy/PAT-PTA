// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    string s;
    cin >> s;
    int n = s.size(), x = 0, y = 3, mindis = 1 << 30, X, Y;
    for (; y < n; y++)
    {
        if ((n + 2 - y) % 2 == 0)
            x = (n + 2 - y) / 2;
        else
            continue;
        if (x <= y && y - x < mindis)
        {
            mindis = y - x;
            X = x, Y = y;
        }
    }
    for (int i = 0; i < X - 1; i++)
    {
        putchar(s[i]);
        for (int j = 0; j < Y - 2; j++)
            putchar(' ');
        putchar(s[n - 1 - i]);
        putchar('\n');
    }
    printf("%s", s.substr(X - 1, Y).c_str());
    return 0;
}