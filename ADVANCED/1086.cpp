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
    null
};

void post(ptrNode root)
{
    if (!root)
        return;
    if (root->left)
        post(root->left);
    if (root->right)
        post(root->right);
    if(!first) cout << " ";
    cout << root->data;
    first = 0;
}

int main(int argc, char const *argv[])
{
    /* code */
    int n, id;
    operation lastop = null;
    stack<ptrNode> sk;
    cin >> n;
    ptrNode lastpop, root, TreeNodes[n + 1];
    string s;
    for (int i = 1; i <= n; i++)
        TreeNodes[i] = new Node(i);
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> s;
        if (s[1] == 'u')
        {
            cin >> id;
            if (lastop == pop)
                lastpop->right = TreeNodes[id];
            else if (lastop == push)
                sk.top()->left = TreeNodes[id];
            else
                root = TreeNodes[id];
            sk.push(TreeNodes[id]);
            lastop = push;
        }
        else
        {
            lastpop = sk.top();
            sk.pop();
            lastop = pop;
        }
    }
    post(root);
    return 0;
}