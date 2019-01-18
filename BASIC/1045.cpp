// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <algorithm>
#define test() freopen("in", "r", stdin)

using namespace std;

int main()
{
    int N;
    scanf("%d", &N);
    int num[N], num_sorted[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &num[i]);
        num_sorted[i] = num[i];
    }
    sort(num_sorted, num_sorted + N);
    int count = 0, max = 0;
    int res[N];

    for (int i = 0; i < N; i++)
    {
        if (num[i] > max)
            max = num[i];
        if (max == num[i] && num[i] == num_sorted[i])
            res[count++] = num[i];
    }
    printf("%d\n", count);
    for (int i = 0; i < count; i++)
        if (i == 0)
            printf("%d", res[i]);
        else
            printf(" %d", res[i]);
    printf("\n");
    return 0;
}