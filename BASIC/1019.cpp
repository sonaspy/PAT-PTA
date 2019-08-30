// author - sonaspy@outlook.com
// coding - utf_8

#include <iostream>
#include <string>
#include <algorithm>
#define test() freopen("in", "r", stdin)

using namespace std;

string  convert(string & tmp)
{
    string s;
    if (tmp.size() == 1)
        s = "000" + tmp;
    else if (tmp.size() == 2)
        s = "00" + tmp;
    else if (tmp.size() == 3)
        s = "0" + tmp;
    else
        s = tmp;
    return s;
}

int main(int argc, char const *argv[])
{
    /* code */
    string s, tmp;
    cin >> s;
    if (count(s.begin(), s.end(), s[0]) == 4)
        cout << s << " - " << s << " = "
             << "0000";
    else
        {
            int t1, t2, t3;
            while (t3 != 6174)
                {
                    s = convert(s);
                    sort(s.begin(), s.end(), greater<int>());
                    cout << s << " - ";
                    t1 = stoi(s);
                    sort(s.begin(), s.end());
                    t2 = stoi(s);
                    cout << s << " = ";
                    t3 = t1 - t2;
                    tmp = to_string(t3);
                    s = convert(tmp);
                    cout << s << endl;
                }
        }
    return 0;
}