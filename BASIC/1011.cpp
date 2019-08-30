// author - sonaspy@outlook.com
// coding - utf_8

#include<iostream>
#include <math.h>
#define test() freopen("in","r",stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    long a,b,c;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        {
            cin >> a >> b >> c;
            if (a+b > c)printf("Case #%d: true",i);
            else
                printf("Case #%d: false", i);
        }
    return 0;
}