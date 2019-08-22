// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, t, cnt = 0, table[100001];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &t);
        table[t] = i;
    }
    for (int i = 0; i < n; i++)
    {
        if (table[i] != i)
        {
            while (table[0] != 0)
            {
                swap(table[0], table[table[0]]);
                cnt++;
            }
            if (i != table[i])
            {
                swap(table[0], table[i]);
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}