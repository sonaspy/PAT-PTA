// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n;
    int64_t num, n1, n2;
    string snum;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        snum = to_string(num);
        n1 = stoll(snum.substr(0, snum.size() / 2)), n2 = stoll(snum.substr(snum.size() / 2));
        cout << (n1 != 0 && n2 != 0 && num % (n1 * n2) == 0 ? "Yes\n" : "No\n");
    }
    return 0;
}