// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <math.h>
#include <vector>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    int n, count = 0;
    vector<int> prime;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        bool isprime = true;
        for (int j = 2; j <= sqrt(i); j++)
        {
            if (i % j == 0)
            {
                isprime = false;
                break;
            }
        }
        if (isprime)
            prime.push_back(i);
    }
    for (int i = 0; i < prime.size() - 1; i++)
        if (prime[i + 1] - prime[i] == 2)
            count++;
    cout << count;
    return 0;
}