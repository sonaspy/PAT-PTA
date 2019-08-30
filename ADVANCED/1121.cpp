// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
int mp[100000], n, cnt = 0, a1, a2;
unordered_set<int> party;
set<int> sig;
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    fill(mp, mp + 100000, -1);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &a1, &a2);
        mp[a1] = a2;
        mp[a2] = a1;
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a1);
        party.insert(a1);
    }
    for (auto j : party)
    {
        if (!party.count(mp[j]))
            sig.insert(j);
    }
    cout << sig.size() << endl;
    n = 0;
    for (auto i : sig)
    {
        if (n != 0)
            printf(" ");
        else
            n = 1;
        printf("%05d", i);
    }
    return 0;
}