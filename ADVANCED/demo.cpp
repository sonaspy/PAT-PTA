// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    vector<int> a(10, 2);
    a.erase(a.begin() + a.size(), a.end());
    cout << a.size();
    return 0;
}