// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#define test() freopen("in", "r", stdin)

using namespace std;
typedef long long ll;

ll stonum(string s, int radix)
{
    ll sum = 0, d;
    for (int i = s.size() - 1, c = 0; i > -1; i--, c++)
    {
        d = isdigit(s[i]) ? s[i] - '0' : s[i] - 'a' + 10;
        sum += d * pow(radix, c);
    }
    return sum;
}
int return_radix(string s, ll num)
{
    int res = -1;
    char it = *max_element(s.begin(), s.end());
    ll low = isdigit(it) ? it - '0' : it - 'a' + 10;low++;
    ll high = max(num, low);
    while (low <= high)
    {
        ll mid = (low + high) / 2;
        ll tmp = stonum(s, mid);
        if (tmp < 0 || tmp > num)
            high = mid - 1;
        else if (tmp < num)
            low = mid + 1;
        else
        {
            res = mid;
            break;
        }
    }
    return res;
}
int main(int argc, char const *argv[])
{
    /* code *///attention
    //test();
    int tag, radix, res;
    string s1, s2;
    cin >> s1 >> s2 >> tag >> radix;
    ll known = tag == 1 ? stonum(s1, radix) : stonum(s2, radix);
    res = return_radix((tag == 1 ? s2 : s1), known);
    if (res == -1)
        cout << "Impossible";
    else
        cout << res;
    return 0;
}