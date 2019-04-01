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

inline int GetHeight(avlptr root) { return root == nullptr ? 0 : root->height; }
inline void updateHeight(avlptr root) { root->height = max(GetHeight(root->left), GetHeight(root->right)) + 1; }
inline int getFactor(avlptr root) { return GetHeight(root->left) - GetHeight(root->right); }
// inline avlptr getMax(avlptr root)
// {
//     while (root->right)
//         root = root->right;
//     return root;
// }
// inline avlptr getMin(avlptr root)
// {
//     while (root->left)
//         root = root->left;
//     return root;
// }

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

// avlptr Delete(avlptr &root, int data)
// {
//     if (!root)
//         return nullptr;
//     else if (root->data > data)
//     {
//         root->left = Delete(root->left, data);
//         updateHeight(root);
//         if (getFactor(root) == -2)
//         {
//             if (getFactor(root->right) == -1)
//                 RR(root);
//             else
//             {
//                 LL(root->right);
//                 RR(root);
//             }
//         }
//     }
//     else if (root->data < data)
//     {
//         root->right = Delete(root->right, data);
//         updateHeight(root);
//		   if (getFactor(root) == 2)
//         {
//             if (getFactor(root->left) == 1)
//                 LL(root);
//             else
//             {
//                 RR(root->left);
//                 LL(root);
//             }
//         }
//     }
//     else // find it
//     {
//         if (root->right && root->left)
//         {
//             if (getFactor(root) > 0)
//             {
//                 avlptr tmp = getMax(root->left);
//                 root->data = tmp->data;
//                 root->left = Delete(root->left, tmp->data);
//             }
//             else
//             {
//                 avlptr tmp = getMin(root->right);
//                 root->data = tmp->data;
//                 root->right = Delete(root->right, tmp->data);
//             }
//         }
//         else
//         {
//             avlptr tmp = root;
//             root = (root->left == nullptr ? root->right : root->left);
//             delete tmp;
//         }
//     }
//     return root;
// }

int main(int argc, char const *argv[])
{
    /* code */
    test();
    int n, tmp;
    cin >> n;
    avlptr root = nullptr;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        Insert(root, tmp);
    }
    return 0;
}