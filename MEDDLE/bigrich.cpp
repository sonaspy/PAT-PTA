// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        int a[n];
        for (int i = 0; i < n; i++)
            scanf("%d", a + i);
        for (int i = 0; i < n && i < m; i++)
        {
            make_heap(a, a + n - i);
            pop_heap(a, a + n - i);
            if(i != 0) printf(" ");
            printf("%d", a[n-1-i]);
        }
        printf("\n");
    }
    return 0;
}