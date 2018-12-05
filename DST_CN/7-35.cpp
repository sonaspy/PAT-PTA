// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <cstring>
#include <cstdlib>
#define test() freopen("in", "r", stdin)

using namespace std;

double preExp();

int main(int argc, char const *argv[])
{
    /* code */
    printf("%.1f", preExp());
    return 0;
}

double preExp()
{
    char s[20];
    cin >> s;
    switch (s[0])
    {
    case '+':
        return preExp() + preExp();
    case '-':
        return preExp() - preExp();
    case '/':
        return preExp() / preExp();
    case '*':
        return preExp() * preExp();
    default:
        return atof(s);
        break;
    }
}