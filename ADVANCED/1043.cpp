// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <vector>
//attention
#define test() freopen("in", "r", stdin)
const int DATASIZE = 1 << 16;
using namespace std;
int input[DATASIZE], n, f = 0;
vector<int> pre, pre_m, post_output;
typedef struct Node* pNode;
struct Node
{
    int __data;
    pNode left = nullptr, right = nullptr;
    Node(int d) { __data = d; }
};
void insert(pNode &root, int data)
{
    if (!root){ root = new Node(data); return;}
    insert((data < root->__data) ? (root->left) : (root->right) , data);
}
void preorder(pNode root)
{
    if (!root) return;
    pre.push_back(root->__data);
    preorder(root->left);
    preorder(root->right);
}
void preorder_m(pNode root)
{
    if (!root) return;
    pre_m.push_back(root->__data);
    preorder_m(root->right);
    preorder_m(root->left);
}
void postorder(pNode root)
{
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    post_output.push_back(root->__data);
}
void postorder_m(pNode root)
{
    if (!root) return;
    postorder_m(root->right);
    postorder_m(root->left);
    post_output.push_back(root->__data);
}
inline bool isMatched(const vector<int> &pre)
{
    for (int i = 0; i < n; i++)
        if (pre[i] != input[i])
            return false;
    return true;
}
int main()
{
    //test();
    pNode root = nullptr;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", input+i);
    for (int i = 0; i < n; i++) insert(root, input[i]);
    preorder(root), preorder_m(root);
    if (isMatched(pre)) { postorder(root); f = 1;}
    else if (isMatched(pre_m)) { postorder_m(root); f = 1;}
    if(!f){ printf("NO"); return 0;}
    cout << "YES\n" << post_output[0];
    for (int i = 1; i < post_output.size(); i++) printf(" %d", post_output[i]);
    return 0;
}