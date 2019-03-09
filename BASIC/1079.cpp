// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <string>
#include <algorithm>
#define test() freopen("in", "r", stdin)

using namespace std;

bool is_palindromic(string s)
{
    for (int i = 0; i <= s.size() / 2; i++)
        {
            if (s[i] != s[s.size() - 1 - i])
                return false;
        }
    return true;
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int a, b, c, count;
    string s1, s2;
    cin >> a;
    s1 = to_string(a);
    if (is_palindromic(s1))
        cout << a << " is a palindromic number.";
    else
        {
            for (count = 0; count < 10; count++)
                {
                    s2.clear();
                    s2 = s1;
                    reverse(s2.begin(), s2.end());
                    b = stoi(s2);
                    c = a + b;
                    cout << s1 << " + " << s2 << " = " << c << endl;
                    s1.clear();
                    s1 = to_string(c);
                    a = c;
                    if (is_palindromic(s1))
                        {
                            cout << c << " is a palindromic number.\n";
                            break;
                        }
                }
            if (count == 10)
                cout << "Not found in 10 iterations.\n";
        }
    return 0;
}