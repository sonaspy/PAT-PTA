// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#define test() freopen("in", "r", stdin)

using namespace std;

int tmp, n, colorn, strip[10001], mp[201];
static int length = 0, maxlen = 0;
void DFS(int start, int fav_c)
{
    for (int i = start; i < n; i++)
    {
        int now_fav = mp[strip[i]];
        if (now_fav >= fav_c)
        {
            length++;
            DFS(i + 1, now_fav);
        }
    }
    if (length > maxlen)
        maxlen = length;
    length--;
}
int main(int argc, char const *argv[])
{
    /* code */
    test();
    cin >> colorn >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        mp[tmp] = i + 1;
    }
    cin >> n;
    for (int i = 0; i < n; i++) scanf("%d", &strip[i]);
    DFS(0, 1);
    cout << maxlen;
    return 0;
}

// #include <iostream>
// using namespace std;
// int book[201], a[10001], dp[10001];
// int main()
// {
//     int n, m, x, l, num = 0, maxn = 0;
//     scanf("%d %d", &n, &m);
//     for (int i = 1; i <= m; i++)
//     {
//         scanf("%d", &x);
//         book[x] = i;
//     }
//     scanf("%d", &l);
//     for (int i = 0; i < l; i++)
//     {
//         scanf("%d", &x);
//         if (book[x] >= 1)
//             a[num++] = book[x];
//     }
//     for (int i = 0; i < num; i++)
//     {
//         dp[i] = 1;
//         for (int j = 0; j < i; j++)
//             if (a[i] >= a[j])
//                 dp[i] = max(dp[i], dp[j] + 1);
//         maxn = max(dp[i], maxn);
//     }
//     printf("%d", maxn);
//     return 0;
// }//attention