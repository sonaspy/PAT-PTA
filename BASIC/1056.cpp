// author - sonaspy@outlook.com
// coding - utf_8

#include <iostream>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, tmp, sum = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                {
                    if (i != j)
                        {
                            tmp = a[i] * 10 + a[j];
                            sum += tmp;
                        }
                }
        }
    cout << sum;
    return 0;
}