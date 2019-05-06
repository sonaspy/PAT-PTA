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
unordered_map<int, COLOR> itsColor;
node *construct(int root, int lo, int hi)
{
    if (hi < lo)
        return new node(-1, BLK); //dummy leaf node
    int i = lo;
    for (; i < hi && in[i] != pre[root]; i++)
        ;
    node *titsColor = new node(pre[root], itsColor[pre[root]]);
    titsColor->left = construct(root + 1, lo, i - 1);
    titsColor->right = construct(root + 1 + i - lo, i + 1, hi);
    if (titsColor->color_ == RED && !(titsColor->left->color_ == BLK && titsColor->right->color_ == BLK))
        flag = 0;
    return titsColor;
}

int postorder(node *root)
{
    if(!root || !flag)return 0;
    int n1 = postorder(root->left);
    int n2 = postorder(root->right);
    if (n1 != n2)
    {
        flag = 0;
        return 0;
    }
    return root->color_ == BLK ? n1 + 1 : n1;
}
inline bool judge(node *root)
{
    postorder(root);
    return (root->color_ == RED || !flag) ? false: true;
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
        itsColor.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> pre[i];
            if (pre[i] < 0)
            {
                pre[i] = -pre[i];
                itsColor[pre[i]] = RED;
            }
            else itsColor[pre[i]] = BLK;
            in[i] = pre[i];
        }
        sort(in, in + n);
        node *root = construct(0, 0, n - 1);
        printf("%s\n", judge(root) ? "Yes" : "No");
    }
    return 0;
}