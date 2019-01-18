// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#define test() freopen("in", "r", stdin)

using namespace std;

bool isPrime(long long n)
{
    for (long long i = 2; i < int(sqrt(n)); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    /* code */
    // test();
    int L, K;
    cin >> L >> K;
    string s;
    cin >> s;
    for (int i = 0; i < s.length() - K +1; i++)
    {
        string s1;
        s1 = s.substr(i, K);
        long long num;
        num = stoll(s1);
        if (isPrime(num))
        {
            cout << s1;
            return 0;
        }
    }
    cout << 404;
    return 0;
}