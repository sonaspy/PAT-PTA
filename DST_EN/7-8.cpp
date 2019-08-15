// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
char c;
int union_my[100000];
inline int update_get(int a)
{
    return union_my[a] == -1 ? a : union_my[a] = update_get(union_my[a]);
}

inline void Union(int a, int b)
{
    int ra = update_get(a), rb = update_get(b);
    if (ra == rb)
        return;
    union_my[rb] = ra;
};

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    fill(union_my, union_my + 100000, -1);
    int n, a1, a2, sum = 0;
    cin >> n;
    while (true)
    {
        cin >> c;
        if (c == 'S')
            break;
        scanf("%d%d", &a1, &a2);
        if (c == 'C')
            (update_get(a1) == update_get(a2)) ? printf("yes\n") : printf("no\n");
        else
        {
            Union(a1, a2);
            update_get(a1), update_get(a2);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (union_my[i] == -1)
            sum++;
    }
    if (sum == 1)
        (cout << "The network is connected.");
    else
        printf("There are %d components.", sum);
    return 0;
}