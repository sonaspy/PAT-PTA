// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <map>
#include <vector>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    test();
    vector<pair<int, double>> p1, p2, res;
    map<int, double, greater<int>> mp;
    int n, e;
    double co;
    cin >> n;
    for (int i = 0; i < n; i++)
        {
            cin >> e >> co;
            p1.push_back(make_pair(e, co));
        }
    cin >> n;
    for (int i = 0; i < n; i++)
        {
            cin >> e >> co;
            p2.push_back(make_pair(e, co));
        }
    for (auto i : p1)
        {
            for (auto j : p2)
                {
                    co = i.second * j.second;
                    e = i.first + j.first;
                    mp[e] += co;
                }
        }
    for (auto i : mp)
        {
            if (i.second != 0)
                res.push_back(make_pair(i.first, i.second));
        }
    cout << res.size();
    for(auto i : res)
        printf(" %d %.1f",i.first,i.second);
    return 0;
}