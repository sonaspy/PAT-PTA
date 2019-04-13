// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, i, j, a[105], b[105];
    cin >> n;
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    for (int i = 0; i < n; i++)
        scanf("%d", b + i);
    for (i = 0; i < n - 1 && b[i] <= b[i + 1]; i++)
        ;
    for (j = i + 1; a[j] == b[j] && j < n; j++)
        ;
    if (j == n)
    {
        cout << "Insertion Sort\n";
        sort(a, a + i + 2);
    }
    else
    {
        cout << "Merge Sort\n";
        int step = 1, find_step = 0;
        while (!find_step)
        {
            find_step = 1;
            for (i = 0; i < n; i++)
            {
                if (a[i] != b[i])
                {
                    find_step = 0;
                    break;
                }
            }
            step *= 2;
            for (i = 0; i < n / step; i++)
                sort(a + i * step, a + (i + 1) * step);
            sort(a + i * step, a + n);
        }
    }
    printf("%d", a[0]);
    for (j = 1; j < n; j++)
        printf(" %d", a[j]);
    return 0;
}