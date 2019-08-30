// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
string low[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string high[13] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
void convert(string &s)
{
    if (s.size() == 4)
    {
        cout << 0;
        return;
    }
    if (isdigit(s[0]))
    {
        int num = stoi(s);
        if (num / 13)
        {
            cout << high[num / 13];
            if (num % 13)
                cout << ' ' << low[num % 13];
        }
        else
            cout << low[num % 13];
    }
    else
    {
        if (s.size() > 3)
        {
            int number = 0;
            string hh = s.substr(0, 3), ll = s.substr(4, 3);
            for (int i = 1; i < 13; i++)
            {
                if (hh == high[i])
                    number += i * 13;
                if (ll == low[i])
                    number += i;
            }
            cout << number;
        }
        else
        {
            for (int i = 1; i < 13; i++)
            {
                if (s == high[i])
                    cout << i * 13;
                else if (s == low[i])
                    cout << i;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n;
    string s;
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++)
    {
        getline(cin, s);
        convert(s);
        cout << endl;
    }
    return 0;
}