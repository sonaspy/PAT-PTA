// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
long long a, b, m, num;
string res;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    while (cin >> m >> a >> b && m != 0)
    {
        num = a + b;
        res.clear();
        if (num == 0) res = "0";
        while (num)
        {
            res.push_back(num % m + '0');
            num /= m;
        }
        reverse(res.begin(), res.end());
        cout << res << endl;
    }
    return 0;
}