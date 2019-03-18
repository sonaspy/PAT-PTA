// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <string>
#include <algorithm>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    string s;
    int res = 1;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++)
        for (int j = i + 1; j < s.size(); j++)
        {
            string s1 = s.substr(i, j - i + 1), s2 = s1;
            reverse(s2.begin(), s2.end());
            if (s1 == s2 && int(s1.length()) > res)
                res = s1.size();
        }
    cout << res;
    return 0;
}