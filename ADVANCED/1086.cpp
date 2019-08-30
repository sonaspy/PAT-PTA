// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
int first = 1;
typedef struct TreeNode *ptrNode;
struct TreeNode
{
    int data;
    ptrNode left = nullptr, right = nullptr;
    TreeNode(int d) : data(d) {}
};
enum operation
{
    push,
    pop,
    firstop
};
void post(ptrNode root)
{
    if (!root)
        return;
    post(root->left);
    post(root->right);
    if (!first)
        cout << " ";
    cout << root->data;
    first = 0;
}
int main(int argc, char const *argv[])
{
    /* code */
    int n, id;
    operation _op = firstop;
    stack<ptrNode> S;
    cin >> n;
    ptrNode root, TreeNodes[n + 1], lastnode;
    string s;
    for (int i = 1; i <= n; i++)
        TreeNodes[i] = new TreeNode(i);
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> s;
        if (s[1] == 'u')
        {
            cin >> id;
            if (_op == pop)
                lastnode->right = TreeNodes[id];
            else if (_op == push)
                lastnode->left = TreeNodes[id];
            else
                root = TreeNodes[id];
            S.push(TreeNodes[id]);
            lastnode = S.top();
            _op = push;
        }
        else
        {
            lastnode = S.top();
            S.pop();
            _op = pop;
        }
    }
    post(root);
    return 0;
}