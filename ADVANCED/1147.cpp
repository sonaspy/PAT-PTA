// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)
using namespace std;
int m, n;
vector<int> v;
void postOrder(int id)
{
    if (id >= n)return;
    postOrder(id * 2 + 1);
    postOrder(id * 2 + 2);
    printf("%d%s", v[id], id == 0 ? "\n" : " ");
}
int main()
{
    //test();
    scanf("%d%d", &m, &n);
    v.resize(n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> v[j];
        if (is_heap(v.begin(), v.end(), greater<int>()))
            printf("Min Heap\n");
        else if (is_heap(v.begin(), v.end(), less<int>()))
            printf("Max Heap\n");
        else
            printf("Not Heap\n");
        postOrder(0);
    }
    return 0;
}