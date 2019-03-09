// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <cmath>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, r, overflow;
    char c;
    cin >> n >> c;
    r = (sqrt((n + 1) / 2));
    overflow = n - (2 * pow(r, 2) - 1);
    for (int i = r; i > 0; i--)
    {
        for (int j = 0; j < r - i; j++)
            printf(" ");
        for (int j = 0; j < 2 * i - 1; j++)
            cout << c;
        printf("\n");
    }
    for (int i = 2; i <= r; i++)
    {
        for (int j = 0; j < r - i; j++)
            printf(" ");
        for (int j = 0; j < 2 * i - 1; j++)
            cout << c;
        printf("\n");
    }
    cout << overflow;
    return 0;
}