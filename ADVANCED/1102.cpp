// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
typedef struct Node *ptrn;
struct Node
{
    int val, flag;
    ptrn left, right;
    Node(int x) : val(x), flag(-1), left(nullptr), right(nullptr) {}
};
vector<ptrn> tree(20);
vector<int> res;
int n, root;
void inOrder(ptrn root)
{
    if (!root)
        return;
    inOrder(root->left);
    res.push_back(root->val);
    inOrder(root->right);
}
void level(ptrn root)
{
    queue<ptrn> q;
    q.push(root);
    ptrn v;
    while (q.size())
    {
        v = q.front(), q.pop();
        res.push_back(v->val);
        if (v->left)
            q.push(v->left);
        if (v->right)
            q.push(v->right);
    }
}
ptrn invert(ptrn root)
{
    if (!root)
        return nullptr;
    ptrn tmp = invert(root->right);
    root->right = invert(root->left);
    root->left = tmp;
    return root;
}
void output()
{
    cout << res.front();
    for (int i = 1; i < res.size(); i++)
        cout << " " << res[i];
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cin >> n;
    char c1, c2;
    for (int i = 0; i < 20; i++)
        tree[i] = new Node(i);
    for (int i = 0; i < n; i++)
    {
        getchar();
        scanf("%c %c", &c1, &c2);
        if (c1 != '-')
        {
            tree[i]->left = tree[c1 - '0'];
            tree[c1 - '0']->flag = 1;
        }
        if (c2 != '-')
        {
            tree[i]->right = tree[c2 - '0'];
            tree[c2 - '0']->flag = 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (tree[i]->flag == -1)
        {
            root = i;
            break;
        }
    }
    invert(tree[root]);
    level(tree[root]);
    output();
    cout << endl;
    res.clear();
    inOrder(tree[root]);
    output();
    return 0;
}