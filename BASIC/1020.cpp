// author - sonaspy@outlook.com
// coding - utf_8

#include <iostream>
#include <algorithm>
#define test() freopen("in", "r", stdin)

using namespace std;

struct moonpie
{
    double stock, total, price;
};

bool cmp(struct moonpie A, struct moonpie B)
{
    return A.price > B.price;
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int kinds, maxNeed;
    double profit = 0;
    cin >> kinds >> maxNeed;
    struct moonpie moonpies[kinds];
    for (int i = 0; i < kinds; i++)
        {
            cin >> moonpies[i].stock;
        }
    for (int i = 0; i < kinds; i++)
        {
            cin >> moonpies[i].total;
            moonpies[i].price = moonpies[i].total  / moonpies[i].stock;
        }
    sort(moonpies, moonpies + kinds, cmp);
    for (auto iter : moonpies)
        {
            if (maxNeed >= iter.stock)
                {
                    maxNeed -= iter.stock;
                    profit += iter.total;
                }
            else
                {
                    profit += iter.price * maxNeed;
                    break;
                }
        }
    printf("%.2f", profit);
    return 0;
}