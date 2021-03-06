// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int *inorder = new int[1001], *levelorder = new int[1001];
int n, cur = 0;
static void Travel(int id)
{
    if (n - 1 < id) return;
    Travel(id * 2 + 1);
    levelorder[id] = inorder[cur++];
    Travel(id * 2 + 2);
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cin >> n;
    for (int i = 0; i < n; ++i)
        scanf("%d", inorder + i);
    sort(inorder, inorder + n);
    Travel(0);
    printf("%d", levelorder[0]);
    for (int i = 1; i < n; i++)
        printf(" %d", levelorder[i]);
    return 0;
}