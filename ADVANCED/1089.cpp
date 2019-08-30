// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, i, j, a[105], b[105], block;
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
        int len = 2, gotcha = 0;
        for (; !gotcha; len *= 2)
        {
            gotcha = equal(a, a + n, b);
            for (block = 0; block < n / len; block++)
                sort(a + block * len, a + block * len + len);
            sort(a + block * len, a + n);
        }
    }
    printf("%d", a[0]);
    for (j = 1; j < n; j++)
        printf(" %d", a[j]);
    return 0;
}