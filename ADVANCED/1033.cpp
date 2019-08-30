// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

const int INF = 1 << 30;
using namespace std;
struct Station
{
    double price, x;
    const bool operator<(const Station b) const { return x < b.x; }
};
//attention
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    double cmax, d, davg;
    int n;
    cin >> cmax >> d >> davg >> n;
    vector<Station> stations(n + 1);
    stations[0] = {0.0, d};
    for (int i = 1; i <= n; i++)
        scanf("%lf%lf", &stations[i].price, &stations[i].x);
    sort(stations.begin(), stations.end());
    if (stations[0].x != 0.0)
    {
        cout << "The maximum travel distance = 0.00";
        return 0;
    }
    double x = 0.0, farmost = 0.0, nowprice = stations[0].price, sum_amount = 0.0, nowCanDrive = 0.0;
    while (x < d)
    {
        farmost = x + cmax * davg;
        double the_sta_x = 0, minPrice = INF;
        int flag = 0; //There are stations available for less than the current price
        for (int i = 1; i <= n && stations[i].x <= farmost; i++)
        {
            if (stations[i].x <= x) //The station is already passed
                continue;
            if (stations[i].price < minPrice)
            {
                minPrice = stations[i].price;
                the_sta_x = stations[i].x;
            }
            if (stations[i].price < nowprice) //There are cheaper stations to get to than at present
            {
                sum_amount += (stations[i].x - x - nowCanDrive) / davg * nowprice; //nowCanDrive(left tank could drive)
                nowCanDrive = 0.0;
                nowprice = stations[i].price;
                x = stations[i].x;
                flag = 1;
                break;
            }
        }
        if (!flag && minPrice != INF) //There are no cheaper stations to get to, but there are the cheapest stations to get to
        {
            sum_amount += nowprice * (cmax - (nowCanDrive / davg));
            nowCanDrive = cmax * davg - (the_sta_x - x);
            nowprice = minPrice;
            x = the_sta_x;
        }
        else if (!flag && minPrice == INF) //There is no station available
        {
            x += cmax * davg;
            printf("The maximum travel distance = %.2f", x);
            return 0;
        }
    }
    printf("%.2f", sum_amount);
    return 0;
}