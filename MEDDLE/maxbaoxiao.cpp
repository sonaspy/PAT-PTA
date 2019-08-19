// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

struct Info1
{
    double tot;
    int valid;
} checks[35];

double max_sum, target;

void DFS(int i, double sum, int n)
{
    if (i == n)
    {
        if (sum > max_sum)
            max_sum = sum;
        return;
    }
    DFS(i + 1, sum, n);
    if (sum + checks[i].tot <= target && checks[i].valid)
        DFS(i + 1, sum + checks[i].tot, n);
}

int main()
{
    int N, i, j;
    char str[50], ch;
    while (scanf("%lf %d", &target, &N) != EOF && N)
    {
        int m;
        for (i = 0; i < N; i++)
        {
            checks[i].valid = 1, checks[i].tot = 0;
            scanf("%d", &m);
            for (j = 0; j < m; j++)
            {
                scanf("%s", str);
                double temp;
                sscanf(str, "%c:%lf", &ch, &temp);
                checks[i].tot += temp;
                if (temp > 600 || (ch != 'A' && ch != 'B' && ch != 'C'))
                    checks[i].valid = 0;
            }
            if (checks[i].tot > 1000)
                checks[i].valid = 0;
        }
        max_sum = 0;
        DFS(0, 0, N);
        printf("%.2f\n", max_sum);
    }
    return 0;
}