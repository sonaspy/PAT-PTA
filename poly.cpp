// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

double polynomial(int n, double val[], double x)
{
    int i;
    double p = val[n];
    for (i = n; i; --i)
        p = val[i - 1] + x * p;
    return p;
}
struct TreeNode
{
    int val;
    TreeNode *l, *r;
};
void del_x_sub(TreeNode *root, int delval)
{
    queue<TreeNode *> q;
    TreeNode *x;
    if (root->val == delval)
    {
        del(root);
        return;
    }
    q.push(root);
    while (q.size())
    {
        x = q.front(), q.pop();
        if (x->l)
        {
            if (x->l->val == delval)
            {
                del(x->l);
                x->l = nullptr;
            }
            else
                q.push(x->l);
        }
        if (x->r)
        {
            if (x->r->val == delval)
            {
                del(x->r);
                x->r = nullptr;
            }
            else
                q.push(x->r);
        }
    }
}
void del(TreeNode *root)
{
    if (!root)
        return;
    del(root->l);
    del(root->r);
    delete root;
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}