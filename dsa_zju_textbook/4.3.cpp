// author - sonaspy@outlook.com
// coding - utf_8

#include <iostream>
#include <algorithm>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, m, h[1001], a;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        {
            scanf("%d", &h[i]);
            make_heap(h + 1, h + i + 1, greater<int>());
        }
    for (int i = 0; i < m; i++)
        {
            scanf("%d", &a);
            for (int j = a; j > 1; j /= 2)
                printf("%d ", h[j]);
            printf("%d\n", h[1]);
        }
    return 0;
}