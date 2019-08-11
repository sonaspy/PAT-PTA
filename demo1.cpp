// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
};
vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> resSeq;
    if (!root)
        return resSeq;
    stack<pair<TreeNode *, bool>> s;
    s.push(make_pair(root, false));
    bool isMyTurn;
    while (s.size())
    {
        root = s.top().first, isMyTurn = s.top().second, s.pop();
        if (isMyTurn)
            resSeq.push_back(root->val);
        else
        {
            if (root->right)
                s.push(make_pair(root->right, false));
            if (root->left)
                s.push(make_pair(root->left, false));
            s.push(make_pair(root, true));
        }
    }
    return resSeq;
}
vector<int> preorder(TreeNode *root)
{
    vector<int> resSeq;
    if (!root)
        return resSeq;
    stack<TreeNode *> s;
    s.push(root);
    while (s.size())
    {
        root = s.top(), s.pop();
        resSeq.push_back(root->val);
        if (root->right)
            s.push(root->right);
        if (root->left)
            s.push(root->left);
    }
    return resSeq;
}
vector<int> inorder(TreeNode *root)
{
    vector<int> resSeq;
    if (!root)
        return resSeq;
    stack<pair<TreeNode *, bool>> s;
    s.push(make_pair(root, false));
    bool isMyTurn;
    while (s.size())
    {
        root = s.top().first, isMyTurn = s.top().second, s.pop();
        if (isMyTurn)
            resSeq.push_back(root->val);
        else
        {
            if (root->right)
                s.push(make_pair(root->right, false));
            s.push(make_pair(root, true));
            if (root->left)
                s.push(make_pair(root->left, false));
        }
    }
    return resSeq;
}
vector<int> postorder(TreeNode *root)
{
    vector<int> resSeq;
    if (!root)
        return resSeq;
    stack<pair<TreeNode *, bool>> s;
    s.push(make_pair(root, false));
    bool isMyTurn;
    while (s.size())
    {
        root = s.top().first, isMyTurn = s.top().second, s.pop();
        if (isMyTurn)
            resSeq.push_back(root->val);
        else
        {
            s.push(make_pair(root, true));
            if (root->right)
                s.push(make_pair(root->right, false));
            if (root->left)
                s.push(make_pair(root->left, false));
        }
    }
    return resSeq;
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    queue<int> q;
    q.push(100), q.push(1), q.push(1), q.push(1), q.push(1), q.push(10);
    cout << q.front();
    return 0;
}