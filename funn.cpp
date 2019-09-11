#include <stdio.h>
#include <string.h>
#include <math.h>
int gcd(int a, int b)
{
    int temp;
    while (b)
    {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}
int main()
{
    double m;
    int max_de, r;
    scanf("%d", &max_de);
    scanf("%lf", &m);
    printf("%lf\n", m);
    double minn = abs(0 - m);
    int n = minn;
    m -= n;
    printf("%lf\n", minn);
    int a = 0, b = 1, lasta = 0, lastb = 1;
    for (int i = 1; i <= 100000; i++)
    {
        int sum = (int)(i * m + 0.5); //核心逼近分子
        if (sum <= i)
        {
            double f = sum * 1.0 / i;
            double k = abs(f - m);
            if (minn > k) //一步步缩小差距，使真实商与被给与的小数差值达到最小
            {
                minn = k;
                a = sum;
                b = i;
            }
            r = gcd(a, b);
            if (b / r >= max_de)
            {
                break;
            }
            lasta = a;
            lastb = b;
        }
    }
    if (b / r > max_de)
    {
        a = lasta;
        b = lastb;
    }
    r = gcd(a, b);
    printf("%d/%d\n", a / r + n * b / r, b / r);
}