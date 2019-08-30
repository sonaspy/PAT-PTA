// author -sonaspy@outlook.com
// coding - utf_8

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <queue>

#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    long long a, b, c, d, e, f, n, g;
    scanf("%lld.%lld.%lld %lld.%lld.%lld", &a, &b, &c, &d, &e, &f);
    n = c + b * 29 + a * 29 * 17 + f + e * 29 + d * 29 * 17;
    g = n / (17 * 29);
    n %= (17 * 29);
    printf("%lld.%lld.%lld", g, n / 29, n % 29);
    return 0;
}