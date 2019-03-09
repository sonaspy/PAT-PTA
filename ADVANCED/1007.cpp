// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>

#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, a[10001], thissum = 0, maxsum = -1, start = 0, first, last, tmp;
    cin >> n;
    for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            thissum += a[i];
            if (!start)
                {
                    start = 1;
                    tmp = a[i];
                }
            if (thissum > maxsum)
                {
                    maxsum = thissum;
                    first = tmp;
                    last = a[i];
                }
            if (thissum < 0)
                {
                    start = 0;
                    thissum = 0;
                }
        }
    if (maxsum < 0)
        cout << 0 << " " << a[0] << " " << a[n - 1];
    else
        cout << maxsum << " " << first << " " << last;
    return 0;
}