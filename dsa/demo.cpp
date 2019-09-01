// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int vis[10] = {1, 1, 1, 1, 1, 1, 0};
    int i = count_if(vis, vis + 5, [](int &c) { return c != 1; });
    cout << i;
    return 0;
}