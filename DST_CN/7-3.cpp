// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

struct TreeNode
{
    char data;
    TreeNode *left = nullptr, *right = nullptr;
    TreeNode(char x) : data(x) {}
};
typedef vector<TreeNode *> Tree;
TreeNode *BulidTree(Tree &T)
{
    int N, check[20] = {0};
    char cl, cr;
    cin >> N;
    for (int i = 0; i < N; i++)
        T[i] = new TreeNode('-');
    for (int i = 0; i < N; i++)
    {
        cin >> T[i]->data >> cl >> cr;
        if (cl != '-')
        {
            T[i]->left = T[cl - '0'];
            check[cl - '0'] = 1;
        }
        if (cr != '-')
        {
            T[i]->right = T[cr - '0'];
            check[cr - '0'] = 1;
        }
    }
    for (int i = 0; i < N; i++)
        if (!check[i])
            return T[i];
    return nullptr;
}

int Isomprphic(TreeNode *root1, TreeNode *root2)
{
    if (!root1 && !root2)
        return 1;
    if (!root1 || !root2)
        return 0;
    if (root1->data != root2->data)
        return 0;
    if (!root1->left && !root2->left)
        return Isomprphic(root1->right, root2->right);
    if (root1->left && root2->left && root1->left->data == root2->left->data)
        return (Isomprphic(root1->left, root2->left) && Isomprphic(root1->right, root2->right));
    else
        return (Isomprphic(root1->left, root2->right) && Isomprphic(root1->right, root2->left));
}
int main()
{
    //test();
    TreeNode *root1, *root2;
    Tree T1(20), T2(20);
    root1 = BulidTree(T1);
    root2 = BulidTree(T2);
    if (Isomprphic(root1, root2))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}