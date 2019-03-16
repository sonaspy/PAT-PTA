// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <algorithm>
#include<string>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    double a[3],ans = 1;
    string s = "WTL";
    for (int i = 0; i < 3; i++)
        {
            int k = 0;
            for (int j = 0; j < 3; j++)
                {
                    scanf("%lf", &a[j]);
                    if (a[j] > a[k])
                        k = j;
                }
            printf("%c ", s[k]);
            ans *= a[k];
        }
    printf("%.2f", (ans * 0.65 - 1) * 2);
    return 0;
}