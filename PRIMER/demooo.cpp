// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
typedef struct Node *ptrn;
struct Node
{
    int flag = -1, data;
    int left = -1, right = -1;
    ptrn l, r;
};
vector<ptrn> tree(20);

int n, root, c = 0;
inline void inOrder(int r)
{
    if (tree[r]->right != -1)
        inOrder(tree[r]->right);
    if (c)
        cout << " ";
    cout << r;
    c = 1;
    if (tree[r]->left != -1)
        inOrder(tree[r]->left);
}
ptrn ROOT = new Node;
inline void level()
{
    queue<pair<int, ptrn>> q;
    ROOT->data = root;
    int walk;
    ptrn v;
    q.push(make_pair(root, ROOT));
    while (q.size())
    {
        walk = q.front().first;
        v = q.front().second;
        q.pop();
        if (c)
            cout << " ";
        else
            c = 1;
        cout << walk;
        if (tree[walk]->right != -1)
        {
            v->l = new Node;
            v->l->data = tree[walk]->right;
            q.push(make_pair(tree[walk]->right, v->l));
        }
        if (tree[walk]->left != -1)
        {
            v->r = new Node;
            v->r->data = tree[walk]->left;
            q.push(make_pair(tree[walk]->left, v->r));
        }
    }
}

void order(ptrn r)
{
    if (r->l)
        order(r->l);
    cout << r->data << " ";
    if (r->r)
        order(r->r);
}

int main(int argc, char const *argv[])
{
    /* code */
    test();
    cin >> n;
    char c1, c2;
    for (int i = 0; i < 20; i++)
        tree[i] = new Node();
    for (int i = 0; i < n; i++)
    {
        getchar();
        scanf("%c %c", &c1, &c2);
        if (c1 != '-')
        {
            tree[i]->left = c1 - '0';
            tree[c1 - '0']->flag = 1;
        }
        if (c2 != '-')
        {
            tree[i]->right = c2 - '0';
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
    level();
    cout << endl;
    c = 0;
    inOrder(root);
    cout << endl;
    return 0;
}