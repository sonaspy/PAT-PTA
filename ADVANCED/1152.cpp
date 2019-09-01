// author - sonaspy@outlook.com
// coding - utf_8

#include <iostream>
#include <string>
#include <cmath>
#define test() freopen("in", "r", stdin)

using namespace std;

inline bool isPrime(int num)
{
    if (num < 2 || (num > 2 && num % 2 == 0))
        return 0;
    for (int i = 3; i <= sqrt(num); i += 2)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, m, c;
    string num;
    cin >> n >> m >> num;
    c = num.size() - m;
    for (int i = 0; i <= c; i++)
    {
        string s = num.substr(i, m);
        int number = stoi(s);
        if (isPrime(number))
        {
            cout << s;
            return 0;
        }
    }
    cout << 404;
    return 0;
}