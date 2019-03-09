// author -  newguo@sonaspy.cn
// coding - utf_8
#include <iostream>
#include <cmath>
using namespace std;
int m, x, y;
void print(double t)
{
    if (m == t)
        printf(" Ping");
    else if (m < t)
        printf(" Cong");
    else
        printf(" Gai");
}
int main(int argc, char const *argv[])
{   // i -> jia, j -> yi, k -> bing.
    scanf("%d %d %d", &m, &x, &y);
    for (int i = 99; 9 < i; i--)
    {
        int j = i % 10 * 10 + i / 10;
        double k = abs(j - i) * 1.0 / x;
        if (j == k * y)
        {
            cout << i;
            print(i);
            print(j);
            print(k);
            return 0;
        }
    }
    cout << "No Solution";
    return 0;
}