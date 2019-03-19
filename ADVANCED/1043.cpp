// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <vector>
//attention
#define test() freopen("in", "r", stdin)

using namespace std;
int num[1111], n;
vector<int> pre, mirror_pre, post;
typedef struct Node *pNode;
struct Node
{
    int data;
    pNode lchild = NULL, rchild = NULL;
    Node(int d) { data = d; }
};
void insert(pNode &root, int x)
{
    if (!root)
    {
        root = new Node(x);
        return;
    }
    if (x >= root->data) insert(root->rchild, x);
    else insert(root->lchild, x);
}
void preorder(pNode root)
{
    if (!root) return;
    pre.push_back(root->data);
    preorder(root->lchild);
    preorder(root->rchild);
}
void mirrororder(pNode root)
{
    if (!root) return;
    mirror_pre.push_back(root->data);
    mirrororder(root->rchild);
    mirrororder(root->lchild);
}
inline bool issame(const vector<int> &pre)
{
    for (int i = 0; i < n; i++)
        if (pre[i] != num[i])
            return false;
    return true;
}
void postorder(pNode root)
{
    if (!root) return;
    postorder(root->lchild);
    postorder(root->rchild);
    post.push_back(root->data);
}
void postorder_mirror(pNode root)
{
    if (!root) return;
    postorder_mirror(root->rchild);
    postorder_mirror(root->lchild);
    post.push_back(root->data);
}
int main()
{
    test();
    pNode root = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &num[i]);
    for (int i = 0; i < n; i++) insert(root, num[i]);
    preorder(root);
    mirrororder(root);
    bool f = false;
    if (issame(pre)) {postorder(root); f = true;}
    else if (issame(mirror_pre)) {postorder_mirror(root); f = true;}
    if(!f){printf("NO");return 0;}
    cout << "YES\n" <<post[0];
    for (int i = 1; i < post.size(); i++) printf(" %d", post[i]);
    return 0;
}