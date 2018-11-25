// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<iostream>

using namespace std;
int in[31], post[31];
typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
} BiTNode, *BiTree;
BiTree Build(int *in, int *post, int n)
{               
    if (n <= 0) 
        return NULL;
    int *p = in; 
    while (p)
    { 
        if (*p == *(post + n - 1))
            break;
        p++;
    }
    BiTree T = new BiTNode;
    T->data = *p;
    int len = p - in;
    T->lchild = Build(in, post, len);
    T->rchild = Build(p + 1, post + len, n - 1 - len);
    return T;
}
void PreOrder(BiTree T)
{
    if (T)
    {
        printf(" %d", T->data);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
    return;
}
int main(int argc, char const *argv[])
{
    /* code */
    //freopen("input.a" , "r", stdin);
    int n;
    BiTree T; 
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> post[i];
    for (int i = 0; i < n; i++)
        cin >> in[i];
    T = Build(in, post, n);
        cout << "Preorder:";
    PreOrder(T);

    return 0;
}