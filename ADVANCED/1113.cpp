// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    long long n, a[100000], ini = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        scanf("%lld", a + i);
    sort(a, a + n);
    cout << (n % 2 == 0 ? 0 : 1) << " ";
    cout << accumulate(a + n / 2, a + n, ini) - accumulate(a, a + n / 2, ini);
    return 0;
}