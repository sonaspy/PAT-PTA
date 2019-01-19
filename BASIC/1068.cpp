// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <cmath>
#include <vector>
#define test() freopen("in", "r", stdin)
#define MAXN 2073741824
using namespace std;

struct Node
{
    int m, n, pix;
} tmp;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int m, n, tol, min;
    cin >> m >> n >> tol;
    int image[n + 2][m + 2];
    vector<Node> vec;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            scanf("%d", &image[i][j]);
    }
    for (int i = 0; i <= n + 1; i++)
    {
        image[i][0] = MAXN;
        image[0][i] = MAXN;
        image[n + 1][i] = MAXN;
        image[i][n + 1] = MAXN;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            min = MAXN;
            int ORI = image[i][j], RD = image[i + 1][j + 1], R = image[i][j + 1],
                D = image[i + 1][j], LD = image[i + 1][j - 1], L = image[i][j - 1],
                U = image[i - 1][j], LU = image[i - 1][j - 1], RU = image[i - 1][j + 1];
            if (abs(D - ORI) < min)
                min = abs(D - ORI);
            if (abs(U - ORI) < min)
                min = abs(U - ORI);
            if (abs(R - ORI) < min)
                min = abs(R - ORI);
            if (abs(L - ORI) < min)
                min = abs(L - ORI);
            if (abs(RD - ORI) < min)
                min = abs(RD - ORI);
            if (abs(RU - ORI) < min)
                min = abs(RU - ORI);
            if (abs(LD - ORI) < min)
                min = abs(LD - ORI);
            if (abs(LU - ORI) < min)
                min = abs(LU - ORI);
            if (min > tol)
            {
                tmp = {j, i, ORI};
                vec.push_back(tmp);
            }
        }
    }
    if (vec.size() == 0)
        printf("Not Exist");
    else if (vec.size() == 1)
        printf("(%d, %d): %d", vec[0].m, vec[0].n, vec[0].pix);
    else
        printf("Not Unique");
    return 0;
}