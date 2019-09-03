// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)
#define MAXBOUND 20
using namespace std;
struct TreeNode
{
    int val, id;
    TreeNode *left, *right;
    TreeNode(int v) : val(v), id(0), left(nullptr), right(nullptr) {}
};
vector<TreeNode *> trees;
int n, c1, c2, r = -1, last, trace = -1, iscpt = 1;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cin >> n;
    vector<int> who(n, 0);
    for (int i = 0; i < n; i++)
        trees.push_back(new TreeNode(i));
    for (int i = 0; i < n; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        if (s1 != "-")
        {
            c1 = stoi(s1);
            who[c1] = 1;
            trees[i]->left = trees[c1];
        }
        if (s2 != "-")
        {
            c2 = stoi(s2);
            who[c2] = 1;
            trees[i]->right = trees[c2];
        }
    }
    while (who[++r])
        ;
    TreeNode *v = trees[r];
    queue<TreeNode *> q;
    q.push(trees[r]);
    while (q.size())
    {
        v = q.front(), q.pop();
        last = v->val;
        if (v->id != ++trace)
            iscpt = 0;
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
    }
    if (iscpt)
        cout << "YES " << last;
    else
        cout << "NO " << r;
    return 0;
}