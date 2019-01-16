// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>

#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, sum = 1, i = 1, cha;
    char c;
    cin >> n >> c;
    while (n > sum)
    {
        i += 2;
        sum += i * 2;
    }
    if (sum != n)
    {
        sum -= 2 * i;
        i -= 2;
    }
    cha = n - sum;
    for (int j = i; j >= 1; j -= 2)
    {
        for (int o = (i - j) / 2; o > 0; o--)
            cout << " ";
        for (int k = 0; k < j; k++)
            cout << c;
        for (int o = (i - j) / 2; o > 0; o--)
            cout << " ";
        cout << endl;
    }
    for (int j = 3; j <= i; j += 2)
    {

        for (int o = (i - j) / 2; o > 0; o--)
            cout << " ";
        for (int k = 0; k < j; k++)
            cout << c;
        for (int o = (i - j) / 2; o > 0; o--)
            cout << " ";
        cout << endl;
    }
    printf("%d\n", cha);
    return 0;
}