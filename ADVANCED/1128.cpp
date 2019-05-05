// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int k, n, v[1111];
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &n);
        bool flag = true;
        for (int j = 0; j < n; j++)
        {
            scanf("%d", v + j);
            for (int t = 0; t < j; t++)
            {
                if (v[j] == v[t] || abs(v[j] - v[t]) == abs(j - t))
                {
                    flag = false;
                    break;
                }
            }
        }
        cout << (flag == true ? "YES\n" : "NO\n");
    }
    return 0;
}