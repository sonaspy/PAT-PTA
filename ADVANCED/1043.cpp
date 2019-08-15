// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>
//attention
#define test() freopen("in", "r", stdin)
using namespace std;
int input[2222], n, f = 0, c = 0;
vector<int> post_output;
struct TreeNode
{
    int val;
    TreeNode *left = nullptr, *right = nullptr;
    TreeNode(int d) : val(d) {}
};
void insert(TreeNode *&root, int val)
{
    if (!root)
    {
        root = new TreeNode(val);
        return;
    }
    insert(val < root->val ? (root->left) : (root->right), val);
}
bool preorder(TreeNode *root)
{
    if (!root)
        return true;
    bool f1 = root->val == input[c++];
    bool f2 = preorder(root->left);
    bool f3 = preorder(root->right);
    return f1 && f2 && f3;
}
void postorder(TreeNode *root)
{
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    post_output.push_back(root->val);
}
TreeNode *invert(TreeNode *root)
{
    if (!root)
        return nullptr;
    TreeNode *tmp = invert(root->right);
    root->right = invert(root->left);
    root->left = tmp;
    return root;
}

int main()
{
    //test();
    TreeNode *root = nullptr;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", input + i);
    for (int i = 0; i < n; i++)
        insert(root, input[i]);
    if (preorder(root))
    {
        postorder(root);
        f = 1;
    }
    else
    {
        c = 0;
        invert(root);
        if (preorder(root))
        {
            f = 1;
            postorder(root);
        }
    }
    if (!f) printf("NO");
    else
    {
        cout << "YES\n" << post_output[0];
        for (int i = 1; i < post_output.size(); i++)
            printf(" %d", post_output[i]);
    }
    return 0;
}