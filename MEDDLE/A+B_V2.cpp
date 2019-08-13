// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

unordered_map<string, int> mp;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    mp["zero"] = 0, mp["one"] = 1, mp["two"] = 2, mp["three"] = 3, mp["four"] = 4, mp["five"] = 5, mp["six"] = 6, mp["seven"] = 7, mp["eight"] = 8, mp["nine"] = 9;
    string experssion;
    while (getline(cin, experssion) && experssion != "zero + zero =")
    {
        stringstream ss(experssion);
        string s;
        int a1 = -1, a2 = -1, f = 0;
        while (ss >> s)
        {
            if (s != "+" && s != "=")
            {
                if (a1 == -1 && a2 == -1)
                    a1 = mp[s];
                else if (a1 > -1 && a2 == -1 && !f)
                    a1 = a1 * 10 + mp[s];
                else if (a2 == -1)
                    a2 = mp[s];
                else
                    a2 = a2 * 10 + mp[s];
            }
            else
                f = 1;
        }
        cout << a1 + a2 << endl;
    }
    return 0;
}