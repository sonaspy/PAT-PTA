// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
vector<int> a(100), b(10);
bool cmp(int &it1, int &it2) { return a[it1] < a[it2]; }
int main(int argc, char const *argv[])
{
    /* code */
    //test();

    iota(a.begin(), a.end(), 0);
    iota(b.begin(), b.end(), 0);
    auto i = max_element(b.begin(), b.begin() + 12, cmp);
    cout << *i;
    return 0;
}