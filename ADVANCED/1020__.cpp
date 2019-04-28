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

vector<int> post, in;
map<int, int> res;

void solve(int root, int lo, int hi, int id)
{
    if (hi < lo)
        return;
    int i = lo;
    res[id] = post[root];
    while (i < hi && in[i] != post[root])
        i++;
    solve(root - 1 + i - hi, lo, i - 1, id * 2 + 1);
    solve(root - 1, i + 1, hi, id * 2 + 2);
}

// pre , in -> level
// void solve(int root, int lo, int hi, int id)
// {
//     if (hi < lo)
//         return;
//     int i = lo;
//     while (i < hi && in[i] != pre[root])
//         i++;
//     res[id] = pre[root];
//     solve(root + 1, lo, i - 1, id * 2 + 1);
//     solve(root + 1 + i - lo, i + 1, hi, id * 2 + 2);
// }

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n;
    cin >> n;
    in.resize(n), post.resize(n);
    for (int i = 0; i < n; i++)
        cin >> post[i];
    for (int i = 0; i < n; i++)
        cin >> in[i];
    solve(n - 1, 0, n - 1, 0);
    return 0;
}