#include <iostream>

using namespace std;
typedef struct node *ptrnode;
struct node
{
    int v, height = 1;
    ptrnode left = NULL, right = NULL;
};
ptrnode root;
int getHeight(ptrnode root)
{
    if (!root)
        return 0;
    return root->height;
}
void updateHeight(ptrnode root)
{
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
}

int getBfactor(ptrnode root)
{
    return getHeight(root->left) - getHeight(root->right);
}
void RR(ptrnode &root)
{
    ptrnode temp = root->right;
    root->right = temp->left;
    temp->left = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}
void LL(ptrnode &root)
{
    ptrnode temp = root->left;
    root->left = temp->right;
    temp->right = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}
void insert(ptrnode &root, int v)
{
    if (!root)
    {
        root = new node;
        root->v = v;
        return;
    }
    if (v < root->v)
    {
        insert(root->left, v);
        updateHeight(root);
        if (getBfactor(root) == 2)
        {
            if (getBfactor(root->left) == 1) //LL
                LL(root);
            else if (getBfactor(root->left) == -1) //LR
            {
                RR(root->left);
                LL(root);
            }
        }
    }
    else
    {
        insert(root->right, v);
        updateHeight(root);
        if (getBfactor(root) == -2)
        {
            if (getBfactor(root->right) == -1) //RR
                RR(root);
            else if (getBfactor(root->right) == 1) //RL
            {
                LL(root->right);
                RR(root);
            }
        }
    }
}
int main()
{
    int n, data;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        insert(root, data);
    }
    cout << root->v;
    return 0;
}