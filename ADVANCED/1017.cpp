// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>
#define test() freopen("in", "r", stdin)
using namespace std;
struct node
{
    int arrive, serv_t;
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
        int hh, mm, ss, serv_t;
        scanf("%d:%d:%d %d", &hh, &mm, &ss, &serv_t);
        int arrive = hh * 3600 + mm * 60 + ss;
        if (arrive > 17 * 3600)
            continue;
        tmp = {arrive, serv_t * 60};
        Customers.push_back(tmp);
    }
    sort(Customers.begin(), Customers.end(), cmp1);
    vector<int> window(k, 8 * 3600);
    double totalWait = 0.0;
    for (int i = 0; i < Customers.size(); i++)
    {
        int index = 0, min = window[0];
        for (int j = 1; j < k; j++)
        {
            if (window[j] < min)
            {
                min = window[j];
                index = j;
            }
        }
        if (Customers[i].arrive < window[index])
        {
            totalWait += (window[index] - Customers[i].arrive);
            window[index] += Customers[i].serv_t;
        }
        else
            window[index] = Customers[i].arrive + Customers[i].serv_t;
    }
    printf("%.1f", totalWait / (60.0 * Customers.size()));
    return 0;
}