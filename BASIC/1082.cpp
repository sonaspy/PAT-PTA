// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <cmath>
#include <string>

#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int min = 10000000, max = -1, a1, a2, n;
    string first, last, s;
    double distance = 0.0;
    cin >> n;
    for (int i = 0; i < n; i++)
        {
            cin >> s >> a1 >> a2;
            distance = pow(abs(a1) * abs(a1) + abs(a2) * abs(a2), 0.5);
            if (distance > max)
                {
                    max = distance;
                    first = s;
                }
            if (distance < min)
                {
                    min = distance;
                    last = s;
                }
        }
    cout << last << " " << first;
    return 0;
}