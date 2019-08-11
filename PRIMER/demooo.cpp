// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

struct stu
{
    char *ss;
    int i;
};

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    stu a, *p = &a;
    cout << p->ss++;
    return 0;
}