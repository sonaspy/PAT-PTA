// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    list<int> l1(10);
    iota(l1.begin(), l1.end(), 0);
    for (auto i : l1)
        cout << i << ' ';
    l1.splice(l1.begin(), l1, --------l1.end());
    cout << endl;
    for (auto i : l1)
        cout << i << ' ';
    return 0;
}