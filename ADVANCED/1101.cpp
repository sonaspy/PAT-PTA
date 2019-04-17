// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, a[100011], premax = 0;
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
    if (pivots.size())
    {
        cout << pivots.size() << endl;
        printf("%d", pivots[0]);
        for (int i = 1; i < pivots.size(); i++)
            printf(" %d", pivots[i]);
    }
    else
        cout << 0;
    return 0;
}//attention