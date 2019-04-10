// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
vector<int> res;
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
    res.push_back(root->data);
}

int main(int argc, char const *argv[])
{
    /* code */
    test();
    int n, id;
    operation lastop = null;
    stack<ptrNode> sk;
    cin >> n;
    ptrNode lastpop, root, container[n + 1];
    string s;
    for (int i = 1; i <= n; i++)
        container[i] = new Node(i);
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> s;
        if (s[1] == 'u')
        {
            cin >> id;
            if (lastop == pop)
                lastpop->right = container[id];
            else if (lastop == push)
                sk.top()->left = container[id];
            else
                root = container[id];
            sk.push(container[id]);
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
    for (int i = 0; i < res.size(); i++)
    {
        if (i != 0) cout << " ";
        cout << res[i];
    }
    return 0;
}