// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int64_t stonum(string s, int radix)
{
    int64_t sum = 0;
    for (int i = s.size() - 1, c = 0; i > -1; i--, c++)
        sum += (isdigit(s[i]) ? s[i] - '0' : s[i] - 'a' + 10) * pow(radix, c);
    return sum;
}
int return_radix(string s, int64_t num)
{
    int res = -1;
    char it = *max_element(s.begin(), s.end());
    int64_t lo = isdigit(it) ? it - '0' + 1 : it - 'a' + 11;
    int64_t hi = max(num, lo), mid, tmp;
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        tmp = stonum(s, mid);
        if (tmp == num)
            return mid;
        else if (0 < tmp && tmp < num)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return res;
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int tag, radix, res;
    string s1, s2;
    cin >> s1 >> s2 >> tag >> radix;
    int64_t known = tag == 1 ? stonum(s1, radix) : stonum(s2, radix);
    res = return_radix((tag == 1 ? s2 : s1), known);
    cout << (res == -1 ? "Impossible" : to_string(res));
    return 0;
}
//attention