// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <string>
#include <algorithm>
#define test() freopen("in", "r", stdin)

using namespace std;

bool judge(string s)
{
    if(s == "-") return false;
    int cd = count(s.begin(), s.end(), '.');
    if (cd > 1 || count(s.begin(), s.end(), '-') > 1)
        return false;
    for (auto i : s)
        if (!isdigit(i) && i != '.' && i != '-')
            return false;
    if (cd == 1)
    {
        int i = 0;
        for (; i < s.size() && s[i] != '.'; i++)
            ;
        if (s.size() - i - 1 > 2)
            return false;
    }
    double a = stof(s);
    if (a < -1000 || a > 1000)
        return false;
    return true;
}

int main(int argc, char const *argv[])
{
    /* code */
    test();
    string s;
    int n, count = 0;
    cin >> n;
    double sum = 0.00;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        bool flag = judge(s);
        if (!flag)
            printf("ERROR: %s is not a legal number\n", s.c_str());
        else
        {
            sum += stof(s);
            count++;
        }
    }
    if (count == 0)
        printf("The average of 0 numbers is Undefined\n");
    else if(count == 1)
        printf("The average of %d number is %0.2lf", count, sum / count);
    else
        printf("The average of %d numbers is %0.2lf", count, sum / count);
    return 0;
}