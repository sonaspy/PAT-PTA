// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, a[100011], premax = INT_MIN;
    cin >> n;
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    vector<int> pivots, b(a, a + n);
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        if (b[i] == a[i] && b[i] > premax)
            pivots.push_back(b[i]);
        if (b[i] > premax)
            premax = b[i];
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
} //attention