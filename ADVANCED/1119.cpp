// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
int n, pre[35], post[35], c = 0, is_unique = 1;

struct tnode
{
    int val;
    tnode *left, *right;
    tnode(int x) : val(x), left(nullptr), right(nullptr) {}
};

tnode *Construct(int _pre, int pre_, int _post, int post_)
{
    if (_pre > pre_ || _post > post_)
        return nullptr;
    tnode *root = new tnode(pre[_pre]);
    if (_pre == pre_)
        return root;
    int l_val = pre[_pre + 1], po_i, sub_cnt;
    for (po_i = _post; po_i < post_ && post[po_i] != l_val; po_i++)
        ;
    sub_cnt = po_i - _post;
    if (po_i + 1 < post_) // 2 child
    {
        root->left = Construct(_pre + 1, _pre + sub_cnt + 1, _post, po_i);
        root->right = Construct(_pre + sub_cnt + 2, pre_, po_i + 1, post_ - 1);
    }
    else
    {
        root->left = Construct(_pre + 1, pre_, _post, post_ - 1); // only ont child, default choose left
        is_unique = 0;
    }
    return root;
}

void order(tnode *root)
{
    if (root->left) order(root->left);
    if (c) printf(" ");
    else c = 1;
    printf("%d", root->val);
    if (root->right) order(root->right);
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &pre[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &post[i]);
    tnode *ROOT = Construct(0, n - 1, 0, n - 1);
    cout << (is_unique ? "Yes" : "No") << endl;
    order(ROOT), printf("\n");
    return 0;
}//attention