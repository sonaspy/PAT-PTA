
// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int k;
    string a, b;
    while (cin >> a >> b >> k && a != "0" && b != "0")
    {
        if(!k){cout << -1 << endl; continue;}
        int sum1 = 0, sum2 = 0;
        while (a.size() < 8)
            a = "0" + a;
        while (b.size() < 8)
            b = "0" + b;
        if (k > 0 && a.substr(8 - k, k) == b.substr(8 - k, k))
            printf("-1\n");
        else
            printf("%d\n", stoi(a) + stoi(b));
    }
    return 0;
}