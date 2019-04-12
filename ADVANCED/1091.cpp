// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
int const NX = 1286, NY = 128, NZ = 60;
char mat[NX][NY][NZ] = {0}; //3 dimensional pixels
int m, n, l, t, cnt, sum = 0;
int xx[6] = {1, -1, 0, 0, 0, 0}; //adjacent matrix
int yy[6] = {0, 0, 1, -1, 0, 0};
int zz[6] = {0, 0, 0, 0, 1, -1};
struct node
{
    int x, y, z; //3 dimensional coordinates
};
void bfs(int x, int y, int z)
{
    int __x, __y, __z, __cnt = 1; //use local variable
    deque<node> Q;
    Q.push_back({x, y, z});
    mat[x][y][z] = '0';
    while (!Q.empty())
    {
        node __node = Q.front();
        Q.pop_front();
        for (int i = 0; i < 6; ++i)
        {
            __x = __node.x + xx[i], __y = __node.y + yy[i], __z = __node.z + zz[i];
            if (__x >= 0 && __x < m && __y >= 0 && __y < n && __z >= 0 && __z < l && mat[__x][__y][__z] == '1')
            {
                Q.push_back({__x, __y, __z});
                mat[__x][__y][__z] = '0';
                ++__cnt;
            }
        }
    }
    cnt = __cnt;
}
char read()
{
    char a = getchar();
    while (a != '0' && a != '1')
        a = getchar();
    return a;
}
int main()
{
    scanf("%d%d%d%d", &m, &n, &l, &t);
    for (int k = 0; k < l; ++k)
    { //row-major order
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                mat[i][j][k] = read();
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < l; k++)
            {
                if (mat[i][j][k] == '1')
                {
                    bfs(i, j, k);
                    if (cnt >= t)
                        sum += cnt;
                }
            }
        }
    }
    printf("%d\n", sum);
    return 0;
} //attention