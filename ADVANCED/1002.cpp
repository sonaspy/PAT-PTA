// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <queue>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    test();
    int k, e;
    double co;
    queue<pair<int, double>> p1, p2, res;
    cin >> k;
    for (int i = 0; i < k; i++)
        {
            scanf("%d%lf", &e, &co);
            p1.push(make_pair(e, co));
        }
    cin >> k;
    for (int i = 0; i < k; i++)
        {
            scanf("%d%lf", &e, &co);
            p2.push(make_pair(e, co));
        }
    while (p1.size() && p2.size())
        {
            if (p1.front().first > p2.front().first)
                {
                    res.push(p1.front());
                    p1.pop();
                }
            else if (p1.front().first < p2.front().first)
                {
                    res.push(p2.front());
                    p2.pop();
                }
            else
                {
                    double x = p1.front().second + p2.front().second;
                    if (x)
                        res.push(make_pair(p1.front().first, x));
                    p1.pop(), p2.pop();
                }
        }
    while (p1.size())
        {
            res.push(p1.front());
            p1.pop();
        }
    while (p2.size())
        {
            res.push(p2.front());
            p2.pop();
        }
    cout << res.size();
    while (res.size())
        {
            printf(" %d %.1f", res.front().first, res.front().second);
            res.pop();
        }
    return 0;
}