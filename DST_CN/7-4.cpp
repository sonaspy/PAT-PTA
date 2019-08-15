// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

struct TreeNode
{
    int data = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    TreeNode(int v) : data(v) {}
};
void insert(TreeNode *&root, int v)
{
    if (!root)
    {
        root = new TreeNode(v);
        return;
    }
    root->data < v ? insert(root->right, v) : insert(root->left, v);
}
bool TreeSimilar(TreeNode *T1, TreeNode *T2)
{
    bool f1, f2;
    if (!T1 && !T2)
        return 1;
    if (!T1 || !T2 || T2->data != T1->data)
        return 0;
    f1 = TreeSimilar(T1->left, T2->left);
    f2 = TreeSimilar(T1->right, T2->right);
    return f1 && f2;
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int N, L, var;
    cin >> N;
    while (N)
    {
        TreeNode *root = nullptr;
        cin >> L;
        for (int i = 0; i < N; i++)
        {
            cin >> var;
            insert(root, var);
        }
        for (int i = 0; i < L; i++)
        {
            TreeNode *croot = nullptr;
            for (int j = 0; j < N; j++)
            {
                cin >> var;
                insert(croot, var);
            }
            if (TreeSimilar(croot, root))
                cout << "Yes\n";
            else
                cout << "No\n";
        }
        cin >> N;
    }
    return 0;
}