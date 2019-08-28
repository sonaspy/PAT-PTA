// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    double g1, g2, g;
    int n, m, num;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> g1;
        vector<int> v;
        for (int j = 0; j < n - 1; j++)
        {
            cin >> num;
            if (num >= 0 && num <= m)
                v.push_back(num);
        }
        sort(v.begin(), v.end());
        v[0] = 0, v[v.size() - 1] = 0;
        g2 = accumulate(v.begin(), v.end(), 0) * 1.0 / (v.size() - 2);
        g = (g1 + g2) * 0.5;
        cout << int(g + 0.5) << endl;
    }
    return 0;
}