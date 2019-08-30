
// author - sonaspy@outlook.com
// coding - utf_8
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
int main()
{
    char s[50];
    int c = 0;
    string a, res;
    cin >> a;
    map<char, int> p;
    p['*'] = p['/'] = 1;
    p['('] = p[')'] = 2;
    for (int i = 0; i < a.size(); i++)
        {
            if (((i==0|| a[i - 1] == '(') && (a[i] == '+' || a[i] == '-')) || a[i] == '.' || isdigit(a[i]))
                {
                    if (a[i] != '+')
                        res.push_back(a[i]);
                    while (a[i + 1] == '.' || isdigit(a[i+1]))
                        res.push_back(a[++i]);
                    res.push_back(' ');
                }
            else
                {
                    if (a[i] == ')')
                        {
                            while (c && s[c - 1] != '(')
                                {
                                    res.push_back(s[c-1]), res.push_back(' ');
                                    c--;
                                }
                            c--;
                        }
                    else if (!c || p[a[i]] > p[s[c - 1]])// priority cur > stack top, then push
                        s[c++] = a[i];
                    else
                        {
                            while (c && s[c - 1] != '(')
                                {
                                    res.push_back(s[c - 1]), res.push_back(' ');
                                    c--;
                                }
                            s[c++] = a[i];
                        }
                }
        }
    while (c)
        {
            res.push_back(s[c - 1]), res.push_back(' ');
            c--;
        }
    res.pop_back();
    cout << res;
}