#include <iostream>
#include <memory.h>

int degree[1005];
int father[1005];

int findFather(int x)
{
    if (x != father[x])
        father[x] = findFather(father[x]);
    return father[x];
}

void Union(int x, int y)
{
    int fx = findFather(x), fy = findFather(y);
    if (fx != fy)
        father[fy] = fx;
}

int main(int argc, char const *argv[])
{
    int n, m, x, y;
    while (scanf("%d", &n) != EOF && n)
    {
        memset(degree, 0, sizeof(degree));
        for (int i = 1; i <= n; ++i)
            father[i] = i;
        // memset(father, -1, sizeof(father));

        scanf("%d", &m);
        for (int i = 0; i < m; ++i)
        {
            scanf("%d %d", &x, &y);
            degree[x]++, degree[y]++;
            Union(x, y);
        }

        bool isEuler = true;
        for (int i = 1; i <= n; ++i)
            if (degree[i] & 1)
            {
                isEuler = false;
                break;
            }
        if (isEuler)
        {
            for (int i = 1; i <= n; ++i)
                findFather(i);
            int f = father[1];
            for (int i = 2; i <= n; ++i)
                if (father[i] != f && father[i] != i)
                {
                    isEuler = false;
                    break;
                }
        }
        printf("%d\n", isEuler);
    }
    return 0;
}