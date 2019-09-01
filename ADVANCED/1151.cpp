// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)
#define MSIZE 10001
using namespace std;
struct TreeNode
{
    int val, depth;
    TreeNode *left, *right, *parent;
    TreeNode(int v = 0) : val(v), depth(1), left(nullptr), right(nullptr), parent(nullptr) {}
};
int in[MSIZE], pre[MSIZE];
unordered_map<int, TreeNode *> table;
inline int getDepth(TreeNode *root) { return root == nullptr ? 0 : root->depth; }
TreeNode *__build(int root, int lo, int hi, TreeNode *thisParent)
{
    if (hi < lo)
        return nullptr;
    int i;
    for (i = lo; i < hi && in[i] != pre[root]; ++i)
        ;
    TreeNode *thisNode = new TreeNode(pre[root]);
    thisNode->parent = thisParent;
    thisNode->depth = getDepth(thisNode->parent) + 1;
    thisNode->left = __build(root + 1, lo, i - 1, thisNode);
    thisNode->right = __build(root + 1 + i - lo, i + 1, hi, thisNode);
    table[thisNode->val] = thisNode;
    return thisNode;
}
TreeNode *root;
TreeNode *getLCA(TreeNode *p, TreeNode *q)
{
    while (p->depth > q->depth)
        p = p->parent;
    while (q->depth > p->depth)
        q = q->parent;
    while (p != q)
        p = p->parent, q = q->parent;
    return p;
}
int main(int argc, char const *argv[])
{
    //test();
    int m, n;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", in + i);
    for (int i = 0; i < n; ++i)
        scanf("%d", pre + i);
    root = __build(0, 0, n - 1, nullptr);
    while (m--)
    {
        int x1, x2;
        scanf("%d %d", &x1, &x2);
        TreeNode *p = table.count(x1) ? table[x1] : nullptr, *q = table.count(x2) ? table[x2] : nullptr;
        if (!p && !q)
            printf("ERROR: %d and %d are not found.\n", x1, x2);
        else if (!p || !q)
            printf("ERROR: %d is not found.\n", !p ? x1 : x2);
        else
        {
            TreeNode *thisLCA = getLCA(p, q);
            if (thisLCA != p && thisLCA != q)
                printf("LCA of %d and %d is %d.\n", x1, x2, thisLCA->val);
            else
                printf("%d is an ancestor of %d.\n", thisLCA == p ? x1 : x2, thisLCA == p ? x2 : x1);
        }
    }
    return 0;
}