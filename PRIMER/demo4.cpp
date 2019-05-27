// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
int f(int x)
{
    return (x > 0) ? x * f(x - 1) : 2;
}
int i;
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    i = f();
    cout << i;
    return 0;
}