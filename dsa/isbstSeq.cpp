// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>
#include "Trees.h"
#define test() freopen("in", "r", stdin)

using namespace std;
bool flag = 1;
void insert(TreeNode *&root, int v)
{
    if (!flag) return;
    if (!root){ root = new TreeNode(v); return; }
    if (root->left && root->right){flag = 0;return;}
    root->val <= v ? insert(root->right, v) : insert(root->left, v);
}
bool isBSTSeq(vector<int> &s)
{
    TreeNode *root = nullptr;
    for (auto i : s)
    {
        insert(root, i);
        if (!flag)
            break;
    }
    return flag;
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int a[] = {3, 2, 4, 1};
    vector<int> seq(a, a + 4);

    cout << isBSTSeq(seq);

    return 0;
}