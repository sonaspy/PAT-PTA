// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
// m*p >= M
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, ans = 0, right;
    long long p, a[100001];
    cin >> n >> p;
    for (int i = 0; i < n; i++) scanf("%lld", a + i);
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        right = upper_bound(a + i, a + n, a[i] * p) - a;
        ans = max(right - i, ans);
    }
    cout << ans;
    return 0;
}