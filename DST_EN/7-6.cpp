// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
using namespace std;
typedef struct node *avlNode;
struct node
{
    avlNode left = NULL, right = NULL;
    int data, height = 1;
};
avlNode Root;

int getHeight(avlNode root)
{
    if (!root)
        return 0;
    return root->height;
}
void updateHeight(avlNode root)
{
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
}
int getAVLfactor(avlNode root)
{
    return getHeight(root->left) - getHeight(root->right);
}
void LL(avlNode &root)
{
    avlNode tmp = root->left;
    root->left = tmp->right;
    tmp->right = root;
    updateHeight(root);
    updateHeight(tmp);
    root= tmp;
}
void RR(avlNode &root)
{
    avlNode tmp = root->right;
    root->right = tmp->left;
    tmp->left = root;
    updateHeight(root);
    updateHeight(tmp);
    root = tmp;
}
void insert_2_avlTree(avlNode &root, int data)
{
    if (!root)
    {
        root = new node;
        root->data = data;
        return;
    }
    if (data < root->data)
    {
        insert_2_avlTree(root->left, data);
        updateHeight(root);
        if (getAVLfactor(root) == 2)
        {
            if (getAVLfactor(root->left) == 1)
                LL(root);
            else if (getAVLfactor(root->left) == -1)
            {
                RR(root->left);
                LL(root);
            }
        }
    }
    else
    {
        insert_2_avlTree(root->right, data);
        updateHeight(root);
        if (getAVLfactor(root) == -2)
        {
            if (getAVLfactor(root->right) == -1)
                RR(root);
            else if (getAVLfactor(root->right) == 1)
            {
                LL(root->right);
                RR(root);
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    /* code */
    int data, n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        insert_2_avlTree(Root, data);
    }
    cout << Root->data;
    return 0;
}