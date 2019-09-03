// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    long long n, a[100000];
    cin >> n;
    for (int i = 0; i < n; i++)
        scanf("%lld", a + i);
    nth_element(a, a + n / 2, a + n);
    cout << n % 2 << " ";
    cout << accumulate(a + n / 2, a + n, 0) - accumulate(a, a + n / 2, 0);
    return 0;
}