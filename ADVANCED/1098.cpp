// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)
const int MAXN = 111;
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
        sort(b, b + i + 2);
    }
    else
    {
        cout << "Heap Sort\n";
        for (j = n - 1; j > 0 && b[j - 1] <= b[j]; --j)
            ;
        make_heap(b, b + j + 1);
        pop_heap(b, b + j + 1);
    }
    printf("%d", b[0]);
    for (int i = 1; i < n; i++)
        printf(" %d", b[i]);

    return 0;
}