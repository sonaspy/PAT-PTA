// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <queue>
#include <cmath>
#include <numeric>

#define test() freopen("in", "r", stdin)

using namespace std;
typedef long long ll;
vector<ll> isPrime(5e4, 1);
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    ll num;
    cin >> num;
    for (int i = 2; i * i < 5e4; i++)
        for (int j = 2; j * i < 5e4; j++)
            isPrime[i * j] = 0;
    printf("%lld=", num);
    if (num == 1)
    {
        cout << 1;
        return 0;
    }
    bool first = true;
    for (int i = 2; num > 1; i++)
    {
        int cnt = 0, flag = 0;
        while (isPrime[i] && num % i == 0)
        {
            cnt++;
            num /= i;
            flag = 1;
        }
        if (flag)
        {
            if (!first)
                printf("*");
            printf("%d", i);
            first = false;
        }
        if (cnt >= 2)
            printf("^%d", cnt);
    }
    return 0;
} //attention