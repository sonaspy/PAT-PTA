// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

bool isPrime(int num)
{
    if ((num > 2 && num % 2 == 0) || num < 2)
        return false;
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
    int num, radix;
    vector<int> arr;
    while (true)
    {
        cin >> num >> radix;
        if (num < 0)
            return 0;
        if (!isPrime(num))
            printf("No\n");
        else
        {
            arr.clear();
            while (num)
            {
                arr.push_back(num % radix);
                num /= radix;
            }
            for (int i = arr.size() - 1, c = 0; i > -1; i--, c++)
                num += arr[i] * pow(radix, c);
            printf("%s", isPrime(num) ? "Yes\n" : "No\n");
        }
    }
    return 0;
}