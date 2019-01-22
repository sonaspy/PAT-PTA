// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>

#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    test();
    int k;
    cin >> k;
    int a[k], thisSum = 0, maxSum = -1, start_count = 0, firstNum = 0, lastNum = 0;
    int temp_first = 0;
    for (int i = 0; i < k; i++)
    {
        cin >> a[i];
        thisSum += a[i];
        if (!start_count)
        {
            temp_first = a[i];
            start_count = 1;
        }
        if (thisSum > maxSum)
        {
            maxSum = thisSum;
            firstNum = temp_first;
            lastNum = a[i];
        }
        else if (thisSum < 0)
        {
            thisSum = 0;
            start_count = 0;
        }
    }
    if (maxSum < 0)
        cout << 0 << " " << a[0] << " " << a[k - 1];
    else
        cout << maxSum << " " << firstNum << " " << lastNum;
    return 0;
}