#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    //对新节点进行初始化 ，采用的方法是一边输入，一边建树
    Node(int data1 = -1)
    { //没有输入数据则默认为-1
        data = data1;
        left = NULL;
        right = NULL;
    }
} BNode;
int n, m;
//判断两棵树是否相同
BNode *build(BNode *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data); //根节点为空则新建一个根节点
    }
    else
    {
        if (data < root->data)
        { //比根节点数值小则为左子树
            root->left = build(root->left, data);
        }
        if (data > root->data)
        { //比根节点数值大则为右子树
            root->right = build(root->right, data);
        }
    }
    return root;
}
bool judge(BNode *root1, BNode *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true; //根节点为空则相同
    }
    if (root1 == NULL && root2 != NULL || root2 == NULL && root1 != NULL)
    {
        return false; //两个根节点一个为空一个不为空肯定是不相同的
    }
    if (root1 != NULL && root2 != NULL && root1->data != root2->data)
    {
        return false;
    }
    //判断完根节点之后判断左右子树是否相同
    return judge(root1->left, root2->left) && judge(root1->right, root2->right);
}
int main()
{
    int data;
    //	freopen("input.txt","r",stdin);
    
    while (scanf("%d", &n) != EOF && n != 0)
    {
        scanf("%d", &m);
        BNode *root = NULL; //注意：这里一定要赋值为NULL

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &data);
            root = build(root, data);
        }
        while (m--)
        {
            BNode *root1 = NULL; //注意：这里一定要赋值为NULL

            for (int i = 0; i < n; i++)
            {
                scanf("%d", &data);
                root1 = build(root1, data);
            }
            if (judge(root, root1))
                printf("Yes\n");
            else
                printf("No\n");
            
        }
    }
    return 0;
}