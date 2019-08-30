// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)
#define MAX_V (666)
#define NON_EXIST (1 << 30)
using namespace std;
int indegree[MAX_V] = {0};
vector<int> MAP[MAX_V];
const int n = 6;
void TopSort()
{
    deque<int> dq;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (!indegree[i])
            dq.push_back(i);
    while (dq.size())
    {
        int v = dq.front();
        dq.pop_front();
        cout << v << endl;
        cnt++;
        for (auto i : MAP[v])
        {
            if (--indegree[i] == 0)
                dq.push_back(i);
        }
    }
    if (cnt < n)
        cout << "Cyclic";
}

int main(int argc, char const *argv[])
{
    /* code */
    test();
    int a1, a2, a3;
    for (int i = 0; i < 11; i++)
    {
        cin >> a1 >> a2 >> a3;
        if (a3 > 10)
            a3 /= 10;
        MAP[a1].push_back(a2);
        indegree[a2]++;
    }
    TopSort();
    return 0;
}