// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, ori[100011], premax = INT_MIN;
    cin >> n;
    for (int i = 0; i < n; i++)
        scanf("%d", ori + i);
    vector<int> pivots, res(ori, ori + n);
    sort(res.begin(), res.end());
    for (int i = 0; i < n; i++)
    {
        if (res[i] == ori[i] && ori[i] > premax)
            pivots.push_back(res[i]);
        if (ori[i] > premax)
            premax = ori[i];
    }
    cout << pivots.size() << endl;
    if (pivots.size())
    {
        printf("%d", pivots[0]);
        for (int i = 1; i < pivots.size(); i++)
            printf(" %d", pivots[i]);
    }
    cout << endl;
    return 0;
}