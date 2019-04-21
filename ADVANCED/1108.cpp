// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

// double ans = 0;
// double now;
// int cnt = 0;
// inline bool convert(string &s)
// {
//     regex myfloat("[-]?[0-9]+\\.[0-9]+");
//     regex myint("[-]?[0-9]+");
//     smatch s1, s2;
//     size_t x = s.find('.', 0);
//     bool hasfloat = (x != s.npos);
//     if (hasfloat && !regex_match(s, s1, myfloat))
//         return false;
//     else if (!hasfloat && !regex_match(s, s2, myint))
//         return false;
//     now = stold(s);
//     if (now > 1000 || now < -1000 || (hasfloat && x < s.size() - 3))
//         return false;
//     cnt++;
//     ans += now;
//     return true;
// }

int main(int argc, char const *argv[])
{
    /* code */
    int n, cnt = 0, illegal;
    char a[50], b[50];
    double temp, sum = 0.0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%s", a);
        sscanf(a, "%lf", &temp);
        sprintf(b, "%.2f", temp);
        illegal = 0;
        if (strncmp(a, b, strlen(a)))
            illegal = 1;
        if (illegal || temp < -1000 || temp > 1000)
        {
            printf("ERROR: %s is not a legal number\n", a);
            continue;
        }
        sum += temp;
        cnt++;
    }
    if (cnt == 1)
        printf("The average of 1 number is %.2f", sum);
    else if (cnt > 1)
        printf("The average of %d numbers is %.2f", cnt, sum / cnt);
    else
        printf("The average of 0 numbers is Undefined");
    return 0;
}//attention