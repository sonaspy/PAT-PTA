// author - sonaspy@outlook.com
// coding - utf_8

#include <iostream>

#define test() freopen("in", "r", stdin)
using namespace std;
int h[30], z[30];
struct Tree
{
    Tree *left = NULL, *right = NULL;
    int data;
};
Tree *RestoreTree(int h1, int h2, int z1, int z2)
{
    Tree *root = new Tree();
    root->data = h[h2];
    for (int i = z1; i <= z2; i++)
        {
            if (z[i] == h[h2])
                {
                    if (i != z1)
                        root->left = RestoreTree(h1, h1 - 1 + i - z1, z1, i - 1);
                    if (i != z2)
                        root->right = RestoreTree(h2 + i - z2, h2 - 1, i + 1, z2);
                    break;
                }
        }
    return root;
}
void preOrder(Tree *tree)
{
    cout << ' ' << tree->data;
    if (tree->left)
        preOrder(tree->left);
    if (tree->right)
        preOrder(tree->right);
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> h[i];
    for (int i = 0; i < n; i++)
        cin >> z[i];
    Tree *root = RestoreTree(0, n - 1, 0, n - 1);
    cout << "Preorder:";
    preOrder(root);
}