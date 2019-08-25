// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

inline bool isPrime(int a)
{
    if (a < 2 || (a > 2 && a % 2 == 0))
        return 0;
    for (int i = 3; i <= sqrt(a); i += 2)
        if (a % i == 0)
            return 0;
    return 1;
}
bool isSexPrime(int a)
{
    if (isPrime(a) && (isPrime(a - 6) || isPrime(a + 6)))
        return 1;
    return 0;
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n;
    cin >> n;
    if (isSexPrime(n))
        cout << "Yes\n"
             << (isPrime(n - 6) ? n - 6 : n + 6);
    else
    {
        cout << "No\n";
        while (!isSexPrime(n))
            n++;
        cout << n;
    }
    return 0;
}