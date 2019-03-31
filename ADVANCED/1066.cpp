// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
typedef struct AVLNode *avlptr;
struct AVLNode
{
    int data, height;
    avlptr left = nullptr, right = nullptr;
    AVLNode(int d, int h) : data(d), height(h) {}
};

int GetHeight(avlptr root) { return root == nullptr ? 0 : root->height; }
void updateHeight(avlptr root) { root->height = max(GetHeight(root->left), GetHeight(root->right)) + 1; }
int getFactor(avlptr root) { return GetHeight(root->left) - GetHeight(root->right); }

void LL(avlptr &root)
{
    avlptr tmp = root->left;
    root->left = tmp->right;
    tmp->right = root;
    updateHeight(root);
    updateHeight(tmp);
    root = tmp;
}

void RR(avlptr &root)
{
    avlptr tmp = root->right;
    root->right = tmp->left;
    tmp->left = root;
    updateHeight(root);
    updateHeight(tmp);
    root = tmp;
}

void Insert(avlptr &root, int data)
{
    if (!root)
    {
        root = new AVLNode(data, 1);
        return;
    }
    else if (data < root->data)
    {
        Insert(root->left, data);
        updateHeight(root);
        if (getFactor(root) == 2)
        {
            if (getFactor(root->left) == 1)
                LL(root);
            else
            {
                RR(root->left);
                LL(root);
            }
        }
    }
    else if (data > root->data)
    {
        Insert(root->right, data);
        updateHeight(root);
        if (getFactor(root) == -2)
        {
            if (getFactor(root->right) == -1)
                RR(root);
            else
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
    //test();
    int n, tmp;
    cin >> n;
    avlptr root = nullptr;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        Insert(root, tmp);
    }
    cout << root->data;
    return 0;
}