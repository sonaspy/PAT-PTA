// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
int n, pre[35], post[35], c = 0, is_unique = 1;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *Construct(int leftOfpre, int rightOfpre, int leftOfpost, int rightOfpost)
{
    if (leftOfpre > rightOfpre || leftOfpost > rightOfpost)
        return nullptr;
    TreeNode *root = new TreeNode(pre[leftOfpre]);
    if (leftOfpre == rightOfpre)
        return root;
    int leftSubVal = pre[leftOfpre + 1], i, sub_cnt;
    for (i = leftOfpost; i < rightOfpost && post[i] != leftSubVal; i++)
        ;
    sub_cnt = i - leftOfpost;
    if (i + 1 < rightOfpost) // 2 child
    {
        root->left = Construct(leftOfpre + 1, leftOfpre + sub_cnt + 1, leftOfpost, i);
        root->right = Construct(leftOfpre + sub_cnt + 2, rightOfpre, i + 1, rightOfpost - 1);
    }
    else
    {
        root->left = Construct(leftOfpre + 1, rightOfpre, leftOfpost, rightOfpost - 1); // only one child, default choose left
        is_unique = 0;
    }
    return root;
}

void order(TreeNode *root)
{
    if (root->left)
        order(root->left);
    if (c)
        printf(" ");
    else
        c = 1;
    printf("%d", root->val);
    if (root->right)
        order(root->right);
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &pre[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &post[i]);
    TreeNode *ROOT = Construct(0, n - 1, 0, n - 1);
    cout << (is_unique ? "Yes" : "No") << endl;
    order(ROOT), printf("\n");
    return 0;
}