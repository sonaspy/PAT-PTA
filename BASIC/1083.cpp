// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <map>
#include <cmath>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    test();
    int n, num, d_value;
    map<int, int, greater<int>> mp;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> num;
        d_value = abs(num - i);
        mp[d_value] += 1;
    }
    for (auto iter : mp)
    {
        if (iter.second != 1)
            cout << iter.first << " " << iter.second << endl;
    }
    return 0;
}