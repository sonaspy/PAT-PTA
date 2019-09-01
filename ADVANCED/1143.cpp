// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
struct TreeNode
{
    int val, depth;
    TreeNode *left, *right, *parent;
    TreeNode(int v, TreeNode *thisParent) : val(v), depth(1), left(nullptr), right(nullptr), parent(thisParent) {}
};
int in[10000], pre[10000];
unordered_map<int, TreeNode *> table;
inline int getDepth(TreeNode *root) { return root == nullptr ? 0 : root->depth; }
TreeNode *__build(int root, int lo, int hi, TreeNode *thisParent)
{
    if (hi < lo)
        return nullptr;
    int i;
    for (i = lo; i < hi && in[i] != pre[root]; ++i)
        ;
    TreeNode *thisnode = new TreeNode(pre[root], thisParent);
    thisnode->depth = getDepth(thisnode->parent) + 1;
    thisnode->left = __build(root + 1, lo, i - 1, thisnode);
    thisnode->right = __build(root + 1 + i - lo, i + 1, hi, thisnode);
    table[pre[root]] = thisnode;
    return thisnode;
}

TreeNode *get_LCA(TreeNode *p, TreeNode *q)
{
    while (p->depth > q->depth)
        p = p->parent;
    while (q->depth > p->depth)
        q = q->parent;
    while (p != q)
        p = p->parent, q = q->parent;
    return p;
}
int main()
{
    //test();
    int m, n, x1, x2;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", in + i);
        pre[i] = in[i];
    }
    sort(in, in + n);
    TreeNode *root = __build(0, 0, n - 1, nullptr);
    while (m--)
    {
        scanf("%d %d", &x1, &x2);
        TreeNode *p = table.count(x1) ? table[x1] : nullptr, *q = table.count(x2) ? table[x2] : nullptr;
        if (!p && !q)
            printf("ERROR: %d and %d are not found.\n", x1, x2);
        else if (!p || !q)
            printf("ERROR: %d is not found.\n", p == nullptr ? x1 : x2);
        else
        {
            TreeNode *ans = get_LCA(p, q);
            (ans != p && ans != q) ? printf("LCA of %d and %d is %d.\n", x1, x2, ans->val) : printf("%d is an ancestor of %d.\n", ans == p ? x1 : x2, ans == p ? x2 : x1);
        }
    }
    return 0;
}