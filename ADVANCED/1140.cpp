// author -sonaspy@outlook.com
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
        for (auto j = res.begin(); j < res.end(); j++)
        {
            int cnt = 1;
            while (j < res.end() - 1 && *j == *(j + 1))
                cnt++, j++;
            tmp += *j + to_string(cnt);
        }
        res = tmp;
    }
    cout << res;
    return 0;
}
