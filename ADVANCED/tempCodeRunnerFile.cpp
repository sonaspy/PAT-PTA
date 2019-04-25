// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    test();
    int n, s[111111] = {0}, r[111111] = {0}, tmp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        s[tmp]++;
    }
    for (int i = 100000; i > 0; i--)
        r[i] = r[i + 1] + s[i+1];
    for (int i = 100000; i > 0; i--)
        if (r[i] == i)
        {
            cout << i;
            return 0;
        }
    return 0;
}