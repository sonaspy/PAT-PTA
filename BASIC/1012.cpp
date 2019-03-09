// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>

#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, num, sum = 0, f = -1, a1 = 0, a2 = 0, a3 = 0, a5 = 0,count = 0;
    double a4;
    bool s = false;
    cin >> n;
    for (int i = 0; i < n; i++)
        {
            scanf("%d", &num);
            if (num % 5 == 0 && num % 2 == 0)
                a1 += num;
            else if (num % 5 == 1)
                {
                    f *= -1;
                    s = true;
                    a2 += (f * num);
                }
            else if (num % 5 == 2)
                a3 += 1;
            else if (num % 5 == 3)
                {
                    sum += num;
                    count += 1;
                }
            else if (num % 5 == 4 && num > a5)
                a5 = num;
        }
    a4 = sum * 1.0 / count;
    if (a1 != 0)
        printf("%d", a1);
    else
        printf("N");
    if (s)
        printf(" %d", a2);
    else
        printf(" N");
    if (a3!=0)
        printf(" %d", a3);
    else
        printf(" N");
    if (count!=0)
        printf(" %.1f", a4);
    else
        printf(" N");
    if (a5!= 0)
        printf(" %d", a5);
    else
        printf(" N");
    return 0;
}