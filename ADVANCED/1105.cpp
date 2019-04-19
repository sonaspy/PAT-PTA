// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)
#define OVER_B (t > N - 1)
using namespace std;
int func(int N)
{
    int n = sqrt(N);
    while (n > 0)
    {
        if (N % n == 0)
            return n;
        n--;
    }
    return 1;
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int N, m, n, t = 0;
    cin >> N;
    n = func(N);
    m = N / n;
    int b[m][n], a[N];
    for (int i = 0; i < N; i++)
        scanf("%d", &a[i]);
    sort(a, a + N, greater<int>());
    // m->row  n->column
    int level = (m + 1) / 2, i, j;
    for (i = 0; i < level; i++)
    {
        for (j = i; j < n - i && !OVER_B; j++)
            b[i][j] = a[t++];
        for (j = i + 1; j < m - 1 - i && !OVER_B; j++)
            b[j][n - 1 - i] = a[t++];
        for (j = n - 1 - i; i < j + 1 && !OVER_B; j--)
            b[m - 1 - i][j] = a[t++];
        for (j = m - 2 - i; i < j && !OVER_B; j--)
            b[j][i] = a[t++];
    }

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d", b[i][j]);
            if (j != n - 1)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
//attention