// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <algorithm>

#define test() freopen("in", "r", stdin)
using namespace std;
int main()
{
    //test();
    int n, target, num, minSum = 1 << 30, i, j;
    cin >> n >> target;
    int sum[10005] = {0};
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &sum[i]);
        sum[i] += sum[i - 1];
    }
    for (i = 1; i <= n; i++)
    {
        j = lower_bound(sum + i, sum + n + 1, sum[i - 1] + target) - sum;
        if (j < n + 1 && sum[j] - sum[i - 1] < minSum)
            minSum = sum[j] - sum[i - 1];
    }
    for (i = 1; i <= n; i++)
    {
        j = lower_bound(sum + i, sum + n + 1, sum[i - 1] + minSum) - sum;
        if (sum[j] - sum[i - 1] == minSum)
            printf("%d-%d\n", i, j);
    }
    return 0;
}