// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)
using namespace std;
int main()
{
    //test();
    int n, target, num, minSum = INT_MAX, i, j;
    cin >> n >> target;
    vector<int> sum(n + 1, 0);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &sum[i]);
        sum[i] += sum[i - 1];
    }
    for (i = 1; i < n + 1; i++)
    {
        j = lower_bound(sum.begin() + i, sum.end(), sum[i - 1] + target) - sum.begin();
        if (j < n + 1 && sum[j] - sum[i - 1] < minSum)
            minSum = sum[j] - sum[i - 1];
    }
    for (i = 1; i < n + 1; i++)
    {
        j = lower_bound(sum.begin() + i, sum.end(), sum[i - 1] + minSum) - sum.begin();
        if (sum[j] - sum[i - 1] == minSum)
            printf("%d-%d\n", i, j);
    }
    return 0;
}