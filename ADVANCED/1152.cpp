// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <string>
#include <cmath>
#define test() freopen("in", "r", stdin)

using namespace std;

bool isPrime(int num)
{
    if (num == 1)
        return false;
    for (int i = 2; i <= sqrt(num); i++)
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
    int n, m;
    cin >> n >> m;
    string num;
    cin >> num;
    for (int i = 0; i < num.size() - m + 1; i++)
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