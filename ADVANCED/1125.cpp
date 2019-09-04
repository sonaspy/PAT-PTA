// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
priority_queue<double, vector<double>, greater<double>> pq;
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    double tmp, a1, a2;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &tmp);
        pq.push(tmp);
    }
    while (pq.size() >= 2)
    {
        a1 = pq.top(), pq.pop(), a2 = pq.top(), pq.pop();
        pq.push((a1 + a2) / 2.0);
    }
    cout << int(pq.top());

    return 0;
}