// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int num;
inline void func()
{
    int cnt = 0;
    while (num != 1)
    {
        cnt++;
        if (num % 2 == 0)
            num /= 2;
        else
            num = (3 * num + 1) / 2;
    }
    printf("%d\n", cnt);
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    while (cin >> num && num != 0)
    {
        func();
    }
    return 0;
}