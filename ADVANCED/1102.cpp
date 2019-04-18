// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
typedef struct Node *ptrn;
struct Node
{
    int flag = -1;
    int left = -1, right = -1;
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
inline void level()
{
    queue<int> q;
    int walk;
    q.push(root);
    while (q.size())
    {
        walk = q.front();
        q.pop();
        if (c)
            cout << " ";
        else
            c = 1;
        cout << walk;
        if (tree[walk]->right != -1)
            q.push(tree[walk]->right);
        if (tree[walk]->left != -1)
            q.push(tree[walk]->left);
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
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
    return 0;
}