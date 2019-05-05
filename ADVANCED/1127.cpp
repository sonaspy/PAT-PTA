// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
struct node
{
    int val;
    node *left = nullptr, *right = nullptr;
    node(int d) : val(d) {}
} * ROOT, *v;
vector<node *> res;
int n, post[100], in[100];
node *Construct(int root, int lo, int hi)
{
    if (hi < lo)
        return nullptr;
    int i = lo;
    for (; i < hi && in[i] != post[root]; i++)
        ;
    node *tmp = new node(post[root]);
    tmp->left = Construct(root - 1 + i - hi, lo, i - 1);
    tmp->right = Construct(root - 1, i + 1, hi);
    return tmp;
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cin >> n;
    bool zig = false;
    for (int i = 0; i < n; i++)
        scanf("%d", in + i);
    for (int i = 0; i < n; i++)
        scanf("%d", post + i);
    ROOT = Construct(n - 1, 0, n - 1);
    deque<node *> q, nex_q;
    q.push_back(ROOT);
    while (q.size())
    {
        if (zig)
            res.insert(res.end(), q.begin(), q.end());
        else
            res.insert(res.end(), q.rbegin(), q.rend());
        while (q.size())
        {
            v = q.front(), q.pop_front();
            if (v->left)
                nex_q.push_back(v->left);
            if (v->right)
                nex_q.push_back(v->right);
        }
        swap(q, nex_q);
        zig = zig ? 0 : 1;
    }
    for (int i = 0; i < res.size(); i++)
        printf("%d%c", res[i]->val, i == res.size() - 1 ? '\n' : ' ');
    return 0;
}