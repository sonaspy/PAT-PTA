// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <vector>
#include <algorithm>

#define test() freopen("in", "r", stdin)

using namespace std;
//attention
struct Node
{
    int id, data;
};
bool cmp(const Node &a,const Node &b){ return a.id < b.id; };
vector<int> post, in;
vector<Node> res;

void solve(int root, int left, int right, int id)
{
    if (left > right)
        return;
    int i = left;
    Node tmp;
    while (i < right && in[i] != post[root])
        i++;
    tmp.id = id, tmp.data = post[root];
    res.push_back(tmp);
    solve(root - 1 - right + i , left, i - 1, id * 2 + 1);
    solve(root - 1, i + 1, right, id * 2 + 2);
}

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
    sort(res.begin(),res.end(),cmp);
    cout << res.front().data;
    for(int i = 1; i < res.size();i++)
        cout << " " << res[i].data;
    return 0;
}