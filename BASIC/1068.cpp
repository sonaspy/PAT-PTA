// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <cmath>
#include <unordered_map>
#include <algorithm>
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
    int m, n, tol, min, m1, n1, count = 0, pix;
    cin >> m >> n >> tol;
    int image[n + 2][m + 2];
    unordered_map<int, int> mp;
    for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
                {
                    scanf("%d", &image[i][j]);
                    mp[image[i][j]] += 1;
                }
        }
    for (int i = 0; i <= n + 1; i++)
        {
            image[i][0] = MAXN;
            image[0][i] = MAXN;
            image[n + 1][i] = MAXN;
            image[i][n + 1] = MAXN;
        }// add guards surround matrix.
    for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
                {
                    min = MAXN;
                    int ORI = image[i][j], RD = image[i + 1][j + 1], R = image[i][j + 1],
                        D = image[i + 1][j], LD = image[i + 1][j - 1], L = image[i][j - 1],
                        U = image[i - 1][j], LU = image[i - 1][j - 1], RU = image[i - 1][j + 1];
                    int myints[] = {min, abs(D - ORI), abs(U - ORI), abs(R - ORI), abs(L - ORI), abs(RD - ORI), abs(RU - ORI), abs(LD - ORI), abs(LU - ORI)};
                    min = *min_element(myints, myints + 9);
                    if (min > tol && mp[ORI] == 1)
                        {
                            m1 = j, n1 = i, pix = ORI;
                            count++;
                        }
                }
        }
    if (count == 0)
        printf("Not Exist");
    else if (count == 1)
        printf("(%d, %d): %d", m1, n1, pix);
    else
        printf("Not Unique");
    return 0;
}