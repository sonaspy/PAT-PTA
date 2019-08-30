// author - sonaspy@outlook.com
// coding - utf_8

#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int N, D;
    double e;
    cin >> N >> e >> D;
    int n;
    double d;
    int possible = 0;
    int must = 0;
    for (int i = 0; i < N; i++)
        {
            int day = 0;
            cin >> n;
            for (int j = 0; j < n; j++)
                {
                    cin >> d;
                    if (d < e)
                        day++;
                }
            if (day > (n / 2))
                {
                    if (n > D)
                        must++;
                    else
                        possible++;
                }
        }
    printf("%.1lf%% %.1lf%%\n", (double)possible / N * 100, (double)must / N * 100);
    return 0;
}