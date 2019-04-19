// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)
using namespace std;
int x[30], y[30], res[30], pp[500] = {0};
int prime[500];
int main()
{
    test();
    string a, b;
    int i, j = 0, k = 0, c = 0;
    for (i = 2; i * i < 500; i++)
        for (j = 2; j * i < 500; j++)
            pp[i * j] = 1;
    for (i = 2; i < 300; i++)
        if (pp[i] == 0)
            prime[c++] = i;
    while (cin >> a >> b && a != "0" && b != "0")
    {
        memset(x, 0, sizeof(x));
        memset(y, 0, sizeof(y));
        j = 0, k = 0;
        for (i = 0; i < a.size(); i++)
        {
            if (a[i] == ',')
                j++;
            else
                x[j] = x[j] * 10 + a[i] - '0';
        }
        for (i = 0; i < b.size(); i++)
        {
            if (b[i] == ',')
                k++;
            else
                y[k] = y[k] * 10 + b[i] - '0';
        }
        reverse(x, x + j + 1);
        reverse(y, y + k + 1);
        int len = max(j, k) + 1;
        for (int i = 0; i <= len; i++)
            res[i] = x[i] + y[i];

        for (int i = 0; i < len; i++)
        {
            if (res[i] >= prime[i])
            {
                res[i] -= prime[i];
                res[i + 1]++;
                if (i == len - 1)
                    len++;
            }
        }
        for (int i = len - 1; i > 0; i--)
            cout << res[i] << ",";
        cout << res[0] << endl;
    }
    return 0;
}