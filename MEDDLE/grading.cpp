// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int P, T, G[4], GJ;
    double ans;
    cin >> P >> T >> G[1] >> G[2] >> G[3] >> GJ;
    if (abs(G[1] - G[2]) <= T)
    {
        printf("%.1f", (G[1] + G[2]) * 1.0 / 2);
    }
    else if (abs(G[3] - G[1]) <= T && abs(G[3] - G[2]) <= T)
    {
        printf("%.1f", *max_element(G + 1, G + 4) * 1.0);
    }
    else if (abs(G[3] - G[1]) <= T && abs(G[3] - G[2]) > T)
    {
        printf("%.1f", (G[3] + G[1]) * 1.0 / 2);
    }
    else if (abs(G[3] - G[1]) > T && abs(G[3] - G[2]) <= T)
    {
        printf("%.1f", (G[3] + G[2]) * 1.0 / 2);
    }
    else
        printf("%.1f", GJ * 1.0);
    return 0;
}