// author - newguo@sonaspy.cn
// coding - utf_8

#define SIZE 100
#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
int main(int argc, char const *argv[])
{
    /* code */
    int array[10] = {2, 12, 24, 36, 48, 49, 2333, 6666, 23333, 99999};
    int key = 2333, flag = 0, low = 0, m, h = 9, times = 0;
    while (low <= h)
    {
        m = (low + h) / 2;
        times++;
        if (array[m] == key)
        {
            printf("Found-%d-%d", m, times);
            flag = 1;
            break;
        }
        else if (array[m] > key)
            h = m - 1;
        else
            low = m + 1;
    }
    if (flag == 0)
        printf("Not Found!");
    return 0;
}