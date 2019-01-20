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
    string s1, s2, num;
    char c;
    cin >> c;
    getchar();
    getline(cin, s1);
    if (c == 'C')
    {
        for (int i = 0; i < s1.size(); i++)
        {
            int count = 1;
            for (; i < s1.size() && isalpha(s1[i]) && s1[i + 1] == s1[i]; i++)
                count++;
            if (count > 1)
                s2.push_back(count + '0');
            s2.push_back(s1[i]);
        }
        cout << s2;
    }
    else
    {
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] >= '0' && s1[i] <= '9')
            {
                int cur, len;
                cur = i;
                for (; i < s1.size() && s1[i] >= '0' && s1[i] <= '9'; i++)
                    ;
                num = s1.substr(cur, i - cur);
                len = stoi(num);
                for (int j = 0; j < len; j++)
                    s2.push_back(s1[i]);
            }
            else
                s2.push_back(s1[i]);
        }
        cout << s2;
    }
    return 0;
}