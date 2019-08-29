// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
typedef struct TreeNode *PtrNode;
struct TreeNode
{
    int val, height, id;
    PtrNode left, right;
    TreeNode(int d) : val(d), height(1), id(0), left(nullptr), right(nullptr) {}
};
inline int getHeight(PtrNode root) { return root == nullptr ? 0 : root->height; }
inline int getFactor(PtrNode root) { return getHeight(root->left) - getHeight(root->right); }
inline void updateHeight(PtrNode &root) { root->height = max(getHeight(root->left), getHeight(root->right)) + 1; }
inline void LL(PtrNode &root)
{
    PtrNode tmp = root->left;
    root->left = tmp->right;
    tmp->right = root;
    updateHeight(root);
    updateHeight(tmp);
    root = tmp;
}
inline void RR(PtrNode &root)
{
    PtrNode tmp = root->right;
    root->right = tmp->left;
    tmp->left = root;
    updateHeight(root);
    updateHeight(tmp);
    root = tmp;
}

void Insert(PtrNode &root, int val)
{
    if (!root)
    {
        root = new TreeNode(val);
        return;
    }
    if (val < root->val)
    {
        Insert(root->left, val);
        updateHeight(root);
        if (getFactor(root) == 2)
        {
            if (getFactor(root->left) == 1)
                LL(root);
            else
            {
                RR(root->left);
                LL(root);
            }
        }
    }
    else
    {
        Insert(root->right, val);
        updateHeight(root);
        if (getFactor(root) == -2)
        {
            if (getFactor(root->right) == -1)
                RR(root);
            else
            {
                LL(root->right);
                RR(root);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, t, iscpt = 1, last = -1;
    PtrNode ROOT = nullptr, v = nullptr;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        Insert(ROOT, t);
    }
    queue<PtrNode> q;
    q.push(ROOT);
    while (q.size())
    {
        v = q.front(), q.pop();
        if(v->id != ++last)iscpt = 0;
        cout << v->val;
        if (v->left)
        {
            v->left->id = v->id * 2 + 1;
            q.push(v->left);
        }
        if (v->right)
        {
            v->right->id = v->id * 2 + 2;
            q.push(v->right);
        }
        cout << (q.empty() ? "\n" : " ");
    }
    cout << (iscpt ? "YES" : "NO");
    return 0;
}