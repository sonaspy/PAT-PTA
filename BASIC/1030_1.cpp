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
    long n, p, num, a[100001];
    cin >> n >> p;
    for (long i = 0; i < n; i++)
        scanf("%ld", &a[i]);
    sort(a, a + n);
    long i, j, maxm = 0, cnt = 0, temp;
    for (i = 0; i < n; i++)
    {
        temp = a[i] * p;
        for (j = cnt; j < n; j++)
        {
            if (a[j] > temp)
                break;
            if (maxm < j - i + 1)
                maxm = j - i + 1;
        }
        cnt = j;
    }
    printf("%ld", maxm);
    return 0;
}