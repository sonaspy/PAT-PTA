// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#define test() freopen("in", "r", stdin)

using namespace std;
//attention

vector<int> pre, in;
map<int, int> res;

void solve(int root, int left, int right, int id)
{
    if (left > right) return;
    int index = left;
    while (index < right && in[index] != pre[root]) index++;
    res[id] = pre[root];
    solve(root + 1, left, index - 1, id*2 +1 );
    solve(root + index + 1 - left , index + 1, right, id*2+2);
}

int main(int argc, char const *argv[])
{
    /* code */
    test();
    int n;
    string s;
    cin >> n;
    in.resize(n), pre.resize(n);
    for (int index = 0; index < n; index++)
        cin >> pre[index];
    for (int index = 0; index < n; index++)
        cin >> in[index];
    solve(0, 0, n - 1, 0);
    for (auto index : res)
        s += to_string(index.second) + " ";
    s.pop_back(), cout << s;
    return 0;
}