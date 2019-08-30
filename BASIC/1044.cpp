// author - sonaspy@outlook.com
// coding - utf_8

#include <iostream>
#include <string>
#include <stdlib.h>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    // test();
    string s, s1, s2,
           d1[13] = {"", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"},
                    d2[13] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
    int n, num, a, b;
    cin >> n;
    cin.get();
    for (int i = 0; i < n; i++)
        {
            getline(cin, s);
            if (!isalpha(s[0]))
                {
                    num = stoi(s);
                    if (num < 13)
                        cout << (!num ? "tret" : d1[num]) << endl;
                    else
                        {
                            a = num / 13;
                            b = num % 13;
                            cout << d2[a] << (!b ? "" : " ") << d1[b] << endl;
                        }
                }
            else
                {
                    if (s.size() == 3)
                        {
                            int flag, number = 0;
                            for (int j = 0; j < 13; j++)
                                if (s == d1[j])
                                    {
                                        flag = 1;
                                        number = j;
                                    }
                            for (int j = 1; j < 13; j++)
                                if (s == d2[j])
                                    {
                                        flag = 2;
                                        number = j;
                                    }
                            if (flag == 1)
                                cout << number << endl;
                            else
                                cout << number * 13 << endl;
                        }
                    else
                        {
                            s2 = s.substr(0, 3);
                            s1 = s.substr(4, 7);
                            int number = 0;
                            for (int j = 0; j < 13; j++)
                                if (s1 == d1[j])
                                    number += j;
                            for (int j = 1; j < 13; j++)
                                if (s2 == d2[j])
                                    number += 13 * j;
                            cout << number << endl;
                        }
                }
        }
    return 0;
}