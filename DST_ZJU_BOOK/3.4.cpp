// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <algorithm>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, a[100001], firstCur[100], lastCur[100], len[100], j = 0, cc = 0, maxlen = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i < n; i++)
    {
        if (a[i] > a[i - 1])
        {
            lastCur[j] = i;
            len[j] = i - firstCur[j] + 1;
            if (len[j] > maxlen)
            {
                cc = j;
                maxlen = len[j];
            }
        }
        else
        {
            firstCur[++j] = i;
            lastCur[j] = i;
        }
    }
    cout << a[firstCur[cc]];
    for (int i = firstCur[cc]+1; i <= lastCur[cc]; i++)
        cout << " " << a[i];
    return 0;
}