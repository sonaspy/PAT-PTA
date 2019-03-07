// author - newguo@sonaspy.cn 
// coding - utf_8 

#include <iostream>
#include <vector>
#include <algorithm>
#define test() freopen("in","r",stdin)
using namespace std;
struct node
{
    int arrive, time;
} tmp;
bool cmp1(node a, node b)
{
    return a.arrive < b.arrive;
}
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    vector<node> Customers;
    for (int i = 0; i < n; i++)
    {
        int hh, mm, ss, time;
        scanf("%d:%d:%d %d", &hh, &mm, &ss, &time);
        int arrive = hh * 3600 + mm * 60 + ss;
        if (arrive > 17 * 3600)
            continue;
        tmp = {arrive, time * 60};
        Customers.push_back(tmp);
    }
    sort(Customers.begin(), Customers.end(), cmp1);
    vector<int> window(k, 8 * 3600);
    double totalWait = 0.0;
    for (int i = 0; i < Customers.size(); i++)
    {
        int ti = 0, minfinish = window[0];
        for (int j = 1; j < k; j++)
        {
            if (window[j] < minfinish)
            {
                minfinish = window[j];
                ti = j;
            }
        }
        if (window[ti] <= Customers[i].arrive)
            window[ti] = Customers[i].arrive + Customers[i].time;
        else
        {
            totalWait += (window[ti] - Customers[i].arrive);
            window[ti] += Customers[i].time;
        }
    }
    printf("%.1f", totalWait / 60.0 / Customers.size());
    return 0;
}