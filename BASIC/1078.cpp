// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <string>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    test();
    string s;
    char c;
    cin >> c;
    getchar();
    getline(cin, s);
    if (c == 'C')
    {
        for (int i = 0; i < s.size(); i++)
        {
            int cnt = 1;
            while (s[i] == s[i + 1])
                i++, cnt++;
            if (cnt > 1)
                cout << cnt;
            cout << s[i];
        }
    }
    else
    {
        for (int i = 0; i < s.size(); i++)
        {
            int cnt = 0;
            while (s[i] <= '9' && s[i] >= '0')
                cnt = cnt * 10 + s[i++] - '0';
            for (int j = 0; j < cnt; j++)
                cout << s[i];
            if (cnt == 0)
                cout << s[i];
        }
    }
    return 0;
}