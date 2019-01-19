// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <map>
#include <algorithm>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    test();
    int n;
    scanf("%d", &n);
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1, greater<int>());
    int ans = 0;
    int p = 1;
    while (ans <= n && a[p] > p)
    {
        ans++;
        p++;
    }
    printf("%d", ans);

    return 0;
}