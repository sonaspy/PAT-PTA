// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right, *parent;
    int height = 1, depth = 1;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class solution12_13
{
public:
    void countLeavesOfLevel(TreeNode *root)
    {
        queue<TreeNode *> q, nex_q;
        q.push(root);
        TreeNode *v, *sub;
        int cntOfLeaves, level = 0;
        while (q.size())
        {
            cntOfLeaves = 0;
            while (q.size())
            {
                v = q.front(), q.pop();
                if (!v->left)
                    cntOfLeaves++;
                else
                {
                    sub = v->left;
                    while (sub)
                    {
                        nex_q.push(sub);
                        sub = sub->right;
                    }
                }
            }
            cout << level << " : " << cntOfLeaves << endl;
            level++;
            swap(q, nex_q);
        }
    }
};
class solution13_14
{
private:
    vector<int> tree;
    inline int find_root(int id)
    {
        return tree[id] == -1 ? 1 : find_root(tree[id]) + 1;
    }

public:
    int Find_height()
    {
        int maxh = 0;
        for (auto i : tree)
            maxh = max(maxh, find_root(i));
        return maxh;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    //test();

    return 0;
}