// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)
#define SIZE 100
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

class Solution1_1
{
    vector<TreeNode *> path;
    TreeNode *deepest;
    void find_deepest(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *v;
        while (q.size())
        {
            v = q.front(), q.pop();
            deepest = v;
            if (v->left)
                q.push(v->left);
            if (v->right)
                q.push(v->right);
        }
    }
    void output()
    {
        for (auto i : path)
            cout << i << " ";
    }
    void pre(TreeNode *root)
    {
        if (!root)
            return;
        path.push_back(root);
        if (root == deepest)
        {
            output();
            exit(0);
        }
        pre(root->left);
        pre(root->right);
        path.pop_back();
    }
};

class Solution1_2
{
public:
    vector<int> l;
    void output()
    {
        for (auto i : l)
            cout << i << " ";
        cout << endl;
    }
    Solution1_2()
    {
        l.resize(10000);
        generate(l.begin(), l.end(), [&]() { return rand() % 100; });
        sort(l.begin(), l.end());
        swap(l[2], l[4]);
    }
    inline void rearrange_one_pos()
    {
        int i = 0, n = l.size();
        for (; i + 1 < n && l[i] <= l[i + 1]; i++)
            ;
        for (; i + 1 < n && l[i] > l[i + 1]; i++)
            swap(l[i], l[i + 1]);
    }
    void solve(int k)
    {
        while (k--)
            rearrange_one_pos();
    }
};

class Solution2_1
{
private:
    struct edge
    {
        int v1, v2, cost;
    };
    struct cmp
    {
        bool operator()(const edge &e1, const edge &e2) const { return e1.cost < e2.cost; }
    };
    vector<int> st;
    vector<edge> res;
    int cnt, vc, sum;
    priority_queue<edge, vector<edge>, cmp> pq;
    int find_root(int id) { return st[id] == -1 ? id : st[id] = find_root(id); }
    void Unite(int a, int b)
    {
        int ra = find_root(a), rb = find_root(b);
        if (ra != rb)
            st[rb] = ra;
    }

public:
    Solution2_1()
    {
        st = vector<int>(100, -1);
        cnt = 0;
        vc = 100;
        sum = 0;
    }
    bool kruskal()
    {
        while (cnt < vc - 1 && pq.size())
        {
            edge e = pq.top();
            pq.pop();
            int a1 = find_root(e.v1), a2 = find_root(e.v2);
            if (a1 != a2)
            {
                Unite(a1, a2);
                res.push_back(e);
                sum += e.cost;
            }
        }
        return cnt == vc - 1;
    }
};

class Solution2_2
{
private:
    stack<int> s1, s2; // s1 - input . s2 - output
    int maxsize;

public:
    inline bool enQueue(int x)
    {
        if (s1.size() == maxsize)
        {
            if (s2.size())
                return 0;
            while (s1.size())
                s2.push(s1.top()), s1.pop();
        }
        s1.push(x);
        return 1;
    }
    inline bool deQueue(int &x)
    {
        if (s1.empty() && s2.empty())
            return 0;
        if (s2.empty())
            while (s1.size())
                s2.push(s1.top()), s1.pop();
        x = s2.top();
        s2.pop();
        return 1;
    }
};

class Solution3_2
{
private:
    bool flag;
    vector<TreeNode *> ls;
    void insert_node(TreeNode *&root, int v)
    {
        if (!root)
        {
            root = new TreeNode(v);
            ls.push_back(root);
            return;
        }
        root->val <= v ? insert_node(root->right, v) : insert_node(root->left, v);
    }
    void pre(TreeNode *root)
    {
        if (!root || !flag)
            return;
        if (root->left && root->right)
            flag = 0;
        pre(root->left);
        pre(root->right);
    }

public:
    Solution3_2()
    {
        flag = 1;
    }
    bool isBSTSeq(vector<int> &s)
    {
        TreeNode *root = nullptr;
        for (auto i : s)
            insert_node(root, i);
        pre(root);
        for_each(ls.begin(), ls.end(), [](TreeNode *&p) { delete p; });
        return flag;
    }
    ~Solution3_2()
    {
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    srand(time(NULL));
    int b[SIZE] = {2, 4, 1};
    generate(b, b + SIZE, [&]() { return rand() % 100; });
    vector<int> a(b, b + SIZE);
    Solution3_2 s;
    cout << s.isBSTSeq(a);
    return 0;
}