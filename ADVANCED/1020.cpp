// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <string>
#define test() freopen("in", "r", stdin)

using namespace std;
//attention
struct Node
{
    int id, data;
    bool operator<(const Node &b)const
    {
        return id < b.id;
    }
};
vector<int> post, in;
set<Node> res;

void solve(int root, int left, int right, int id)
{
    if (left > right) return;
    int i = left;
    Node tmp;
    while (i < right && in[i] != post[root]) i++;
    tmp.id = id, tmp.data = post[root];
    res.insert(tmp);
    solve(root - 1 - right + i, left, i - 1, id * 2 + 1);
    solve(root - 1, i + 1, right, id * 2 + 2);
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n;
    string s;
    cin >> n;
    in.resize(n), post.resize(n);
    for (int i = 0; i < n; i++) cin >> post[i];
    for (int i = 0; i < n; i++) cin >> in[i];
    solve(n - 1, 0, n - 1, 0);
    for(auto i : res) s += to_string(i.data) + " ";
    s.pop_back();
    cout << s;
    return 0;
}
