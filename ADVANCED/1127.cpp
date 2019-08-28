// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left = nullptr, *right = nullptr;
    TreeNode(int d) : val(d) {}
} * ROOT, *v;
vector<TreeNode *> result;
int n, post[100], in[100];
TreeNode *__build(int root, int lo, int hi)
{
    if (hi < lo)
        return nullptr;
    int i = lo;
    for (; i < hi && in[i] != post[root]; i++)
        ;
    TreeNode *node = new TreeNode(post[root]);
    node->left = __build(root - 1 + i - hi, lo, i - 1);
    node->right = __build(root - 1, i + 1, hi);
    return node;
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cin >> n;
    int zig = 1;
    for (int i = 0; i < n; i++)
        scanf("%d", in + i);
    for (int i = 0; i < n; i++)
        scanf("%d", post + i);
    ROOT = __build(n - 1, 0, n - 1);
    deque<TreeNode *> q, nex_q;
    q.push_back(ROOT);
    while (q.size())
    {
        (zig == -1) ? result.insert(result.end(), q.begin(), q.end()) : result.insert(result.end(), q.rbegin(), q.rend());
        while (q.size())
        {
            v = q.front(), q.pop_front();
            if (v->left)
                nex_q.push_back(v->left);
            if (v->right)
                nex_q.push_back(v->right);
        }
        swap(q, nex_q);
        zig *= -1;
    }
    for (int i = 0; i < result.size(); i++)
        printf("%d%c", result[i]->val, i == result.size() - 1 ? '\n' : ' ');
    return 0;
}