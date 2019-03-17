// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <vector>
#include <algorithm>
#define test() freopen("in", "r", stdin)

using namespace std;
typedef long long ll;
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    ll n, m, sum = 0, tmp;
    vector<ll> c_1, c_2, p_1, p_2;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        scanf("%lld", &tmp);
        tmp < 0? c_2.push_back(tmp) : c_1.push_back(tmp);
    }
    cin >> m;
    for (ll i = 0; i < m; i++)
    {
        scanf("%lld", &tmp);
        tmp < 0 ? p_2.push_back(tmp) : p_1.push_back(tmp);
    }
    sort(c_2.begin(), c_2.end()), sort(p_2.begin(),p_2.end());
    sort(c_1.begin(), c_1.end(), greater<ll>()), sort(p_1.begin(), p_1.end(),greater<ll>());
    for(int i = 0; i < c_1.size() && i < p_1.size();i++)
        sum += c_1[i] * p_1[i];
    for (int i = 0; i < c_2.size() && i < p_2.size(); i++)
        sum += c_2[i] * p_2[i];
    cout << sum;
    return 0;
}