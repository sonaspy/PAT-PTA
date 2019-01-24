#include <iostream>

using namespace std;
typedef struct node *ptrnode;
struct node
{
    int v, height = 1;
    ptrnode lchild = NULL, rchild = NULL;
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
    root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

int getBfactor(ptrnode root)
{
    return getHeight(root->lchild) - getHeight(root->rchild);
}
void RR(ptrnode &root)
{
    ptrnode temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}
void LL(ptrnode &root)
{
    ptrnode temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
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
        insert(root->lchild, v);
        updateHeight(root);
        if (getBfactor(root) == 2)
        {
            if (getBfactor(root->lchild) == 1) //LL
                LL(root);
            else if (getBfactor(root->lchild) == -1) //LR
            {
                RR(root->lchild);
                LL(root);
            }
        }
    }
    else
    {
        insert(root->rchild, v);
        updateHeight(root);
        if (getBfactor(root) == -2)
        {
            if (getBfactor(root->rchild) == -1) //RR
                RR(root);
            else if (getBfactor(root->rchild) == 1) //RL
            {
                LL(root->rchild);
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