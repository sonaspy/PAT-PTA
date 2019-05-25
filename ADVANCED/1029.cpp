
// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>
#define test() freopen("in", "r", stdin)
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    int a[200005], n, m, b, rank = -1;
    cin >> n;
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    a[n] = INT_MAX;
    sort(a, a + n);
    cin >> m;
    int midpos = (n + m - 1) / 2, a_cur = 0;
    for (int j = 0; j < m; j++)
    {
        scanf("%d", &b);
        for (; a[a_cur] < b; a_cur++)
        {
            rank++;
            if (rank == midpos)
            {
                cout << a[a_cur];
                return 0;
            }
        }
        rank++;
        if (rank == midpos)
        {
            cout << b;
            return 0;
        }
    }
    for (; a_cur < n; a_cur++)
    {
        rank++;
        if (rank == midpos)
        {
            cout << a[a_cur];
            return 0;
        }
    }
    return 0;
} //attention