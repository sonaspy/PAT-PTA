// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
enum COLOR{ BLK,RED};
struct TreeNode
{
    int val, belowBLKnum;
    COLOR color_;
    TreeNode *left = nullptr, *right = nullptr;
    TreeNode(int d, COLOR c) : val(d), belowBLKnum(1), color_(c) {}
};
int pre[100], in[100], k, n, isRBtree;
unordered_map<int, COLOR> colorTable;
inline int getblknums(TreeNode *node) { return node ? node->belowBLKnum : 0; }
TreeNode *__build(int root, int lo, int hi)
{
    if (hi < lo)
        return new TreeNode(INT_MIN, BLK); //dummy leaf TreeNode
    int i = lo;
    for (; i < hi && in[i] != pre[root]; i++)
        ;
    TreeNode *node = new TreeNode(pre[root], colorTable[pre[root]]);
    node->left = __build(root + 1, lo, i - 1);
    node->right = __build(root + 1 + i - lo, i + 1, hi);
    if (node->color_ == RED && (node->left->color_ == RED || node->right->color_ == RED))
        isRBtree = 0;
    if (node->left->belowBLKnum != node->right->belowBLKnum)
        isRBtree = 0;
    else
        node->belowBLKnum = node->color_ == BLK ? node->left->belowBLKnum + 1 : node->left->belowBLKnum;
    return node;
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cin >> k;
    while (k--)
    {
        cin >> n;
        isRBtree = 1;
        colorTable.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> pre[i];
            (pre[i] < 0) ? pre[i] *= -1, colorTable[pre[i]] = RED : colorTable[pre[i]] = BLK;
            in[i] = pre[i];
        }
        sort(in, in + n);
        TreeNode *root = __build(0, 0, n - 1);
        printf("%s\n", (root->color_ == BLK && isRBtree) ? "Yes" : "No");
    }
    return 0;
}