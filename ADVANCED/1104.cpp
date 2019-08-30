// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n;
    cin >> n;
    double sum = 0.0, temp;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lf", &temp);
        sum += temp * i * (n - i + 1);
    }
    printf("%.2f", sum);
    return 0;
}