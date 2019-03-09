// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>

#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int m, n, a, b, replace;
    cin >> m >> n;
    int image[m][n];
    cin >> a >> b >> replace;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &image[i][j]);
            if (image[i][j] >= a && image[i][j] <= b)
                image[i][j] = replace;
            printf("%03d", image[i][j]);
            if (j == n - 1)
                printf("\n");
            else
                printf(" ");
        }

    return 0;
}