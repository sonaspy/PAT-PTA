// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

struct node
{
    int arrive, serv_t;
    bool operator<(const node &b) const { return arrive < b.arrive; }
};
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
        Customers.push_back({arrive, serv_t * 60});
    }
    sort(Customers.begin(), Customers.end());
    vector<int> w_endt(k, 8 * 3600); // each window's end serve time
    double totalWait = 0.0;
    for (int i = 0; i < Customers.size(); i++)
    {
        int id = -1, earliest = 1 << 30;
        for (int j = 0; j < k; j++)
        {
            if (w_endt[j] < earliest)
            {
                earliest = w_endt[j];
                id = j;
            }
        }
        if (Customers[i].arrive < w_endt[id])
        {
            totalWait += (w_endt[id] - Customers[i].arrive);
            w_endt[id] += Customers[i].serv_t;
        }
        else
            w_endt[id] = Customers[i].arrive + Customers[i].serv_t;
    }
    printf("%.1f", totalWait / (60.0 * Customers.size()));
    return 0;
}