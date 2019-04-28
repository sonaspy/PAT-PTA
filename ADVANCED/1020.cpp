// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<bits/stdc++.h>

#define test() freopen("in","r",stdin)

using namespace std;
//attention
vector<int> post, in;
map<int, int> res;

void solve(int root, int lo, int hi, int id)
{
    if (hi < lo) return;
    int i = lo;
    res[id] = post[root];
    while (i < hi && in[i] != post[root]) i++;
    solve(root - 1 + i - hi, lo, i - 1, id * 2 + 1);
    solve(root - 1, i + 1, hi, id * 2 + 2);
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
    for(auto i : res) s += to_string(i.second) + " ";
    s.pop_back(), cout << s;
    return 0;
}