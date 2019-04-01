// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    test();
    int n, t, cnt = 0, T[10001];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &t);
        T[t] = i;
    }
    for (int i = 0; i < n; i++)
    {
        if (T[i] != i)
        {
            while (T[0] != 0)
            {
                swap(T[0], T[T[0]]);
                cnt++;
                cout << i << ":op1\n";
            }
            if (T[i] != i)
            {
                swap(T[0], T[i]);
                cnt++;
                cout << i << ":op2\n";
            }
        }
    }
    cout << cnt;
    return 0;
}
//attention
