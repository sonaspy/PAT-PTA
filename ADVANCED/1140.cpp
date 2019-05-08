// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int num, n;
    string res, tmp;
    cin >> num >> n;
    res = to_string(num);
    for (int i = 0; i < n - 1; i++)
    {
        tmp.clear();
        for (int j = 0; j < res.size(); j++)
        {
            int cnt = 1;
            while (j < res.size() - 1 && res[j] == res[j + 1])
                cnt++, j++;
            tmp += res[j] + to_string(cnt);
        }
        res = tmp;
    }
    cout << res;
    return 0;
}
