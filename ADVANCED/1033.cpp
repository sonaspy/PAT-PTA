// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<iostream>
#include<vector>
#include<algorithm>
#define test() freopen("in","r",stdin)
const int INF = 1 << 30;
using namespace std;
struct station
{
    double price, x;
    const bool operator<(const station b)const{return x < b.x;}
};
//attention
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    double cmax, d, davg;
    int n;
    cin >> cmax >> d >> davg >> n;
    vector<station> stas(n+1);
    stas[0]={0.0, d};
    for(int i = 1; i <= n;i++)
        scanf("%lf%lf", &stas[i].price, &stas[i].x);
    sort(stas.begin(),stas.end());
    if(stas[0].x != 0.0){cout << "The maximum travel distance = 0.00";return 0;}
    double x = 0.0, farmost = 0.0, nowprice = stas[0].price, totalPrice = 0.0, nowCanDrive = 0.0;
    while (x < d)
    {
        farmost = x + cmax * davg;
        double the_sta_x = 0, minPrice = INF;
        int flag = 0;//有比现在的价格更低的能到达的站
        for (int i = 1; i <= n && stas[i].x <= farmost; i++)
        {
            if (stas[i].x <= x)continue;//该站已过头
            if (stas[i].price < nowprice)
            {
                totalPrice += (stas[i].x - x - nowCanDrive) * nowprice / davg;//nowCanDrive(left tank could drive)
                nowCanDrive = 0.0;
                nowprice = stas[i].price;
                x = stas[i].x;
                flag = 1;
                break;
            }
            if (stas[i].price < minPrice)
            {
                minPrice = stas[i].price;
                the_sta_x = stas[i].x;
            }
        }
        if (flag == 0 && minPrice != INF)//没有比目前更便宜的能到达的站，但有能到达的最便宜的站
        {
            totalPrice += nowprice * (cmax - (nowCanDrive / davg));
            nowCanDrive = cmax * davg - (the_sta_x - x);
            nowprice = minPrice;
            x = the_sta_x;
        }
        if (flag == 0 && minPrice == INF)//没有能到达的站了
        {
            x += cmax * davg;
            printf("The maximum travel distance = %.2f", x);
            return 0;
        }
    }
    printf("%.2f", totalPrice);
    return 0;
}