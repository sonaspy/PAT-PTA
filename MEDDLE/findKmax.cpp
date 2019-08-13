// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
void FindMaxK(int a[], int lo, int hi, int k)
{
    if (lo - hi == k - 1)
        return;
    int key = a[lo];
    int i = lo, j = hi;
    while (i != j)
    {
        while (j > i && a[j] >= key)
            --j;
        swap(a[i], a[j]);
        while (i < j && a[i] <= key)
            ++i;
        swap(a[i], a[j]);
    }
    if (hi - i + 1 == k)
        return;
    else if (hi - i + 1 > k)
        FindMaxK(a, i + 1, hi, k);
    FindMaxK(a, lo, i - 1, k - (hi - i + 1));
}
int a[1000];
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    int k;
    scanf("%d", &k);
    FindMaxK(a, 0, n - 1, k);
    sort(a + n - k - 1, a + n);
    for (int i = n - 1; i >= n - k; --i)
        printf("%d\n", a[i]);
    return 0;
}