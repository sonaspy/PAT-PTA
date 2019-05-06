// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
enum COLOR
{
    BLK,
    RED
};
struct node
{
    int data;
    COLOR color_;
    node *left = nullptr, *right = nullptr;
    node(int d, COLOR c) : data(d), color_(c) {}
};
int pre[100], in[100], k, n, flag;
unordered_map<int, COLOR> mp;
node *construct(int root, int lo, int hi)
{
    if (hi < lo)
        return new node(-1, BLK); //dummy leaf node
    int i = lo;
    for (; i < hi && in[i] != pre[root]; i++)
        ;
    node *tmp = new node(pre[root], mp[pre[root]]);
    tmp->left = construct(root + 1, lo, i - 1);
    tmp->right = construct(root + 1 + i - lo, i + 1, hi);
    if (tmp->color_ == RED && !(tmp->left->color_ == BLK && tmp->right->color_ == BLK))
        flag = 0;
    return tmp;
}

int postorder(node *root)
{
    int n1 = 0, n2 = 0;
    if (root->left)
        n1 = postorder(root->left);
    if (root->right)
        n2 = postorder(root->right);
    if (n1 != n2)
    {
        flag = 0;
        return max(n1, n2);
    }
    else
        return root->color_ == BLK ? n1 + 1 : n1;
}

bool judge(node *root)
{
    postorder(root);
    if (root->color_ == RED || !flag)
        return false;
    return true;
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cin >> k;
    while (k--)
    {
        cin >> n;
        flag = 1;
        mp.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> pre[i];
            if (pre[i] < 0)
            {
                pre[i] = -pre[i];
                mp[pre[i]] = RED;
            }
            else
                mp[pre[i]] = BLK;
            in[i] = pre[i];
        }
        sort(in, in + n);
        node *root = construct(0, 0, n - 1);
        printf("%s\n", judge(root) ? "Yes" : "No");
    }
    return 0;
}