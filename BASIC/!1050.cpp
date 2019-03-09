// author -  newguo@sonaspy.cn
// coding - utf_8
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int N, min = 9999, m, n; // m 行  n 列
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++)
        scanf("%d", &v[i]);
    sort(v.begin(), v.end(), greater<int>());
    n = sqrt(N);
    while(N % n != 0)
        n--;
    m = N /n;
    int i, j, k = -1, a[m][n];
    for (i = 0; k < m * n - 1; i++)
        {
            for (j = i; j < n - i && k < m * n - 1; j++)
                a[i][j] = v[++k];
            for (j = i + 1; j < m - i && k < m * n - 1; j++)
                a[j][n - i - 1] = v[++k];
            for (j = n - i - 2; j >= i && k < m * n - 1; j--)
                a[m - i - 1][j] = v[++k];
            for (j = m - 2 - i; j >= i + 1 && k < m * n - 1; j--)
                a[j][i] = v[++k];
        }
    for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                {
                    cout << a[i][j];
                    if (j != n - 1)
                        printf(" ");
                }
            printf("\n");
        }
    return 0;
}
