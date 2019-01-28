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
    int n, a[100001], firstCur[100000], lastCur[100000], len[100000], j = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i < n; i++)
    {
        if (a[i] > a[i - 1])
            lastCur[j] = i;
        else
        {
            len[j] = lastCur[j] - firstCur[j] + 1;
            firstCur[++j] = i;
            lastCur[j] = i;
        }
    }
    int cc, maxlen = -1;
    for (int i = 0; i < n; i++)
        if (len[i] > maxlen)
        {
            cc = i;
            maxlen = len[i];
        }
    for (int i = firstCur[cc]; i <= lastCur[cc]; i++)
    {
        if (i == firstCur[cc])
            cout << a[i];
        else
            cout << " " << a[i];
    }
    return 0;
}