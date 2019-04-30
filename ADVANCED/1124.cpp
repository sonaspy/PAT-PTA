// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int m, n, s;
    cin >> m >> n >> s;
    string str;
    unordered_map<string, int> mp;
    bool flag = false;
    for (int i = 1; i <= m; i++)
    {
        cin >> str;
        if (mp.count(str))
            s++;
        if (i == s && !mp.count(str))
        {
            mp[str] = 1;
            cout << str << endl;
            flag = true;
            s += n;
        }
    }
    if (flag == false) cout << "Keep going...\n";
    return 0;
}