// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
typedef pair<uint64_t, uint64_t> pa;
unordered_map<uint64_t, uint64_t> mp;
vector<pa> v;
inline bool cmp(const pa &a, const pa &b)
{
    return a.second == b.second ? a.first < b.first : a.second > b.second;
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int N;
    long c1, c2;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        scanf("%ld%ld", &c1, &c2);
        mp[c1]++, mp[c2]++;
    }
    for (auto rec : mp)
    {
        v.push_back(make_pair(rec.first, rec.second));
    }
    sort(v.begin(), v.end(), cmp);
    int cnt = 0, val = v.front().second;
    for (; v[cnt].second == val; cnt++)
        ;
    cout << v.front().first << " " << val;
    if (cnt > 1)
        cout << " " << cnt;
    return 0;
}