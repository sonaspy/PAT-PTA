// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
struct TreeNode
{
    int val;
    TreeNode *l = nullptr, *r = nullptr;
    TreeNode(int d) : val(d) {}
};

void insert_node(int val, TreeNode *&root)
{
    if (!root)
    {
        root = new TreeNode(val);
        return;
    }
    (val <= root->val) ? insert_node(val, root->l) : insert_node(val, root->r);
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, tmp, n1 = 0, n2 = 0;
    vector<int> level_size;
    cin >> n;
    TreeNode *ROOT, *v;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        insert_node(tmp, ROOT);
    }
    queue<TreeNode *> q, next_q;
    q.push(ROOT);
    while (q.size())
    {
        level_size.push_back(0);
        while (q.size())
        {
            v = q.front(), q.pop();
            level_size.back()++;
            if (v->l)
                next_q.push(v->l);
            if (v->r)
                next_q.push(v->r);
        }
        swap(q, next_q);
    }
    n1 = level_size.back(), n2 = *(level_size.rbegin() + 1);
    printf("%d + %d = %d", n1, n2, n1 + n2);
    return 0;
}