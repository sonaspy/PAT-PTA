// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
struct country
{
    double gold, medal, g_p, m_p;
    int rank[5];
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    country cons[10];
    int id = 1;
    int i = 10;
    cons[1].medal = 10;
    cons[1].gold = 1;
    int  offset = offsetof(country, medal);
    cout << (*((double *)&cons[1] + id - 1) == *((double *)&cons[2] + id - 1));
    return 0;
}