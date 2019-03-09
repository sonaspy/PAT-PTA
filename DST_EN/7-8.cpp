// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;
const int maxn = 10001;
vector<int> Root(maxn, -1);
int getRoot(int n)
{
    if (Root[n] == -1)
        return n;
    return (Root[n] = getRoot(Root[n]));
}
void uni(int a, int b)
{
    int fa = getRoot(a);
    int fb = getRoot(b);
    if (fa != fb)
        Root[fa] = fb;
}
void check(int a, int b)
{
    if (getRoot(a) == getRoot(b))
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}
int main()
{
    int n, cnt = 0;
    cin >> n;
    char s;
    cin >> s;
    while (s != 'S')
    {
        int a, b;
        cin >> a >> b;
        if (s == 'C')
            check(a, b);
        else if (s == 'I')
            uni(a, b);
        cin >> s;
    }
    for (int i = 1; i <= n; i++)
        if (Root[i] == -1)
            cnt++;
    (cnt == 1) ? cout << "The network is connected." << endl : cout << "There are " << cnt << " components." << endl;
    return 0;
}