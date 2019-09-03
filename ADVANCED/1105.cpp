// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)
using namespace std;
inline int func(int N)
{
    int n = sqrt(N);
    for (; n; n--)
    {
        if (N % n == 0)
            return n;
    }
    return 1;
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int N, m, n;
    cin >> N;
    n = func(N);
    m = N / n;
    int b[m][n], a[N];
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
    sort(a, a + N, greater<int>());
    int i, j, left = 0, right = n - 1, up = 0, down = m - 1, x = 0, row = 0, col = 0, status = 1, done;
    while (x < N)
    {
        b[row][col] = a[x++];
        done = 0;
        do
        {
            switch (status)
            {
            case 1:
                if (++col > right)
                {
                    col = right, status = 2;
                    continue;
                }
                else
                {
                    done = 1;
                    break;
                }
            case 2:
                if (++row > down)
                {
                    row = down, status = 3;
                    continue;
                }
                else
                {
                    done = 1;
                    break;
                }
            case 3:
                if (--col < left)
                {
                    col = left, status = 4;
                    continue;
                }
                else
                {
                    done = 1;
                    break;
                }
            case 4:
                if (--row == up)
                {
                    down--, left++, up++, right--;
                    row = up;
                    status = 1;
                    continue;
                }
                else
                {
                    done = 1;
                    break;
                }
            }
        } while (!done);
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