
// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>
#define test() freopen("in", "r", stdin)
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int a[400005], n, m, b, rank = -1;
    cin >> n;
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    cin >> m;
    for (int i = n; i < n + m; i++)
        scanf("%d", a + i);
    nth_element(a, a + (n + m - 1) / 2, a + n + m);
    cout << a[(n + m - 1) / 2];
    return 0;
}