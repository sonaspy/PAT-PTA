// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <cmath>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    test();
    double max = 0;
    int n, c1, c2;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> c1 >> c2;
        if (sqrt(c1 * c1 + c2 * c2) >= max)
            max = sqrt(c1 * c1 + c2 * c2);
    }
    printf("%.2lf", max);
    return 0;
}