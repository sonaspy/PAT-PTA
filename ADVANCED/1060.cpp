// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <string>

#define test() freopen("in", "r", stdin)

using namespace std;
int sig_n;

string solve(string &d)
{
    string res = "0.";
    bool isZero = true;
    for (auto i : d)
    {
        if (i != '0' && i != '.')
        {
            isZero = false;
            break;
        }
    }
    if (isZero)
    {
        for (int i = 0; i < sig_n; i++)
            res.push_back('0');
        res += "*10^0";
        return res;
    }
    int i = -1;
    while (d[++i] == '0')
        ;
    d = d.substr(d[i] == '.' ? i - 1 : i, d.size() - i + 1);
    // d is a whole decimal fraction.
    if (d.substr(0, 2) == "0.")
    {
        string dd = d.substr(2, d.size() - 2);
        int i = -1;
        while (dd[++i] == '0') ;
        res += dd.substr(i, dd.size() - i);
        if (res.size() - 2 > sig_n)
            res = res.substr(0, sig_n + 2);
        else
        {
            for (int i = 0; i < sig_n + 2 - res.size(); i++)
                res.push_back('0');
        }
        res += "*10^" + to_string(-1 * i);
    }
    // d is not fraction.
    else
    {
        int point = 0; // decimal point cur.
        while (point < d.size() && d[point++] != '.') ;
        res += d.substr(0, point - 1) + d.substr((point == d.size() ? point - 1 : point), d.size() - point+1);
        if (res.size() - 2 > sig_n)
            res = res.substr(0, sig_n + 2);
        else
            for (int i = 0; i < sig_n + 2 - res.size(); i++)
                res.push_back('0');

        res += "*10^" + to_string((point == d.size() ? point : point - 1));
    }
    // above ternary expressions all are judging if the number has fractoin part.
    return res;
    
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    string d1, d2, s1, s2;
    cin >> sig_n >> d1 >> d2;
    s1 = solve(d1), s2 = solve(d2);
    if (s1 == s2) cout << "YES " << s1;
    else cout << "NO " << s1 << " " << s2;
    return 0;
}