// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
int first = 1;
typedef struct Node *ptrNode;
struct Node
{
    int data;
    ptrNode left = nullptr, right = nullptr;
    Node(int d) : data(d) {}
};

enum operation
{
    push,
    pop,
    firstop
};
void post(ptrNode root)
{
    if (!root) return;
    post(root->left);
    post(root->right);
    if (!first) cout << " ";
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
    ptrNode lastPOP, root, TreeNodes[n + 1];
    string s;
    for (int i = 1; i <= n; i++)
        TreeNodes[i] = new Node(i);
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> s;
        if (s[1] == 'u')
        {
            cin >> id;
            if (_op == pop)
                lastPOP->right = TreeNodes[id];
            else if (_op == push)
                S.top()->left = TreeNodes[id];
            else
                root = TreeNodes[id];
            S.push(TreeNodes[id]);
            _op = push;
        }
        else
        {
            lastPOP = S.top();
            S.pop();
            _op = pop;
        }
    }
    post(root);
    return 0;
}