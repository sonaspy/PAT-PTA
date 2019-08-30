// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int64_t n, m, sum = 0, tmp;
    vector<int64_t> positive_c, negative_c, positive_p, negative_p;
    cin >> n;
    for (int64_t i = 0; i < n; i++)
    {
        scanf("%lld", &tmp);
        tmp < 0 ? negative_c.push_back(tmp) : positive_c.push_back(tmp);
    }
    cin >> m;
    for (int64_t i = 0; i < m; i++)
    {
        scanf("%lld", &tmp);
        tmp < 0 ? negative_p.push_back(tmp) : positive_p.push_back(tmp);
    }
    sort(negative_c.begin(), negative_c.end()), sort(negative_p.begin(), negative_p.end()), sort(positive_c.begin(), positive_c.end(), greater<int64_t>()), sort(positive_p.begin(), positive_p.end(), greater<int64_t>());
    for (int i = 0; i < positive_c.size() && i < positive_p.size(); i++)
        sum += positive_c[i] * positive_p[i];
    for (int i = 0; i < negative_c.size() && i < negative_p.size(); i++)
        sum += negative_c[i] * negative_p[i];
    cout << sum;
    return 0;
}