// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <queue>
#include <map>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    test();
    int n, ceof, expr;
    queue<pair<int, int>> Q1, Q2, add;
    vector<pair<int, int>> v1, v2;
    map<int, int, greater<int>> mul;
    cin >> n;
    for (int i = 0; i < n; i++)
        {
            cin >> ceof >> expr;
            if (!ceof)
                continue;
            v1.push_back(make_pair(ceof, expr));
            Q1.push(make_pair(ceof, expr));
        }
    cin >> n;
    for (int i = 0; i < n; i++)
        {
            cin >> ceof >> expr;
            if (!ceof)
                continue;
            v2.push_back(make_pair(ceof, expr));
            Q2.push(make_pair(ceof, expr));
        }
    while (Q1.size() && Q2.size())
        {
            if (Q1.front().second > Q2.front().second)
                {
                    add.push(Q1.front());
                    Q1.pop();
                }
            else if (Q1.front().second < Q2.front().second)
                {
                    add.push(Q2.front());
                    Q2.pop();
                }
            else
                {
                    int a1 = Q1.front().first + Q2.front().first;
                    if (a1)
                        add.push(make_pair(a1, Q1.front().second));
                    Q1.pop(), Q2.pop();
                }
        }
    while (Q1.size())
        {
            add.push(Q1.front());
            Q1.pop();
        }
    while (Q2.size())
        {
            add.push(Q2.front());
            Q2.pop();
        }
    for (int i = 0; i < v1.size(); i++)
        {
            for (int j = 0; j < v2.size(); j++)
                {
                    int a1, a2;
                    a1 = v1[i].first * v2[j].first;
                    a2 = v1[i].second + v2[j].second;
                    if (a1)
                        mul[a2] += a1;
                }
        }
    if (mul.empty())
        cout << "0 0";
    else
        {
            int f = 1;
            for (auto iter : mul)
                {
                    if (iter.second)
                        {
                            if (!f)
                                cout << " ";
                            cout << iter.second << " " << iter.first;
                            f = 0;
                        }
                }
        }
    cout << endl;
    if (add.empty())
        cout << "0 0";
    else
        {
            while (add.size())
                {
                    cout << add.front().first << " " << add.front().second;
                    add.pop();
                    cout << (add.empty() ? "" : " ");
                }
        }
    return 0;
}