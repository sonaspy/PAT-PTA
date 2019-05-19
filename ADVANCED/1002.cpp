// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <deque>
#define test() freopen("in", "r", stdin)

using namespace std;
deque<pair<int, double>> p1, p2, res;
inline void solve(deque<pair<int, double>> &p)
{
    while (p.size())
    {
        res.push_back(p.front());
        p.pop_front();
    }
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int k, e;
    double cof;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        scanf("%d%lf", &e, &cof);
        p1.push_back(make_pair(e, cof));
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        scanf("%d%lf", &e, &cof);
        p2.push_back(make_pair(e, cof));
    }
    while (p1.size() && p2.size())
    {
        if (p1.front().first > p2.front().first)
        {
            res.push_back(p1.front());
            p1.pop_front();
        }
        else if (p1.front().first < p2.front().first)
        {
            res.push_back(p2.front());
            p2.pop_front();
        }
        else
        {
            double x = p1.front().second + p2.front().second;
            if (x) res.push_back(make_pair(p1.front().first, x));
            p1.pop_front(), p2.pop_front();
        }
    }
    solve(p1), solve(p2);
    cout << res.size();
    for (auto i : res)
        printf(" %d %.1f", i.first, i.second);
    return 0;
}