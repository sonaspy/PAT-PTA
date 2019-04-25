// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
#define MAX_N 140000
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, s[MAX_N] = {0}, r[MAX_N] = {0}, tmp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        s[tmp]++;
    }
    for (int i = MAX_N - 2; i > -1; i--)
        r[i] = r[i + 1] + s[i + 1];
    for (int i = MAX_N - 2; i > -1; i--)
        if (r[i] >= i)
        {
            cout << i;
            return 0;
        }
    cout << 0;
    return 0;
}