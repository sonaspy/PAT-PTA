// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

using namespace std;
namespace newtree
{
template <typename T>
struct TreeNode
{
    T val;
    TreeNode *left, *right, *parent;
    int height, depth, ltag, rtag;
    TreeNode(T x) : val(x), left(nullptr), right(nullptr), parent(nullptr), height(1), depth(1), ltag(0), rtag(0) {}
};
template <typename T>
class Bin_Tree
{
protected:
    TreeNode<T> *_ROOT, *tp1;
    bool isunique; // pre post build
    inline int __height(TreeNode<T> *root) { return root == nullptr ? 0 : root->height; }
    inline int __depth(TreeNode<T> *root) { return root == nullptr ? 0 : root->depth; }
    inline void __updateD(TreeNode<T> *root) { root->depth = __depth(root->parent) + 1; }
    inline void __updateH(TreeNode<T> *root) { root->height = max(__height(root->left), __height(root->right)) + 1; }
    inline int __factor(TreeNode<T> *root) { return __height(root->left) - __height(root->right); }
    inline TreeNode<T> *__getMaxOfL(TreeNode<T> *root)
    {
        while (root->right)
            root = root->right;
        return root;
    }
    inline TreeNode<T> *__getMinOfR(TreeNode<T> *root)
    {
        while (root->left)
            root = root->left;
        return root;
    }
    inline void __updateROOT(TreeNode<T> *root)
    {
        this->_ROOT = root;
    }
    TreeNode<T> *__build_pi(int root, int lo, int hi, TreeNode<T> *p)
    {
        if (hi < lo)
            return nullptr;
        int i = lo;
        TreeNode<T> *node = new TreeNode<T>(preorder[root]);
        table[preorder[root]] = node;
        node->parent = p;
        __updateD(node);
        while (i < hi && inorder[i] != preorder[root])
            i++;
        node->left = __build_pi(root + 1, lo, i - 1, node);
        node->right = __build_pi(root + 1 + i - lo, i + 1, hi, node);
        __updateH(node);
        return node;
    }
    TreeNode<T> *__build_ip(int root, int lo, int hi, TreeNode<T> *p)
    {
        if (hi < lo)
            return nullptr;
        int i = lo;
        TreeNode<T> *node = new TreeNode<T>(postorder[root]);
        table[postorder[root]] = node;
        node->parent = p;
        __updateD(node);
        while (i < hi && inorder[i] != postorder[root])
            i++;
        node->left = __build_ip(root - 1 + i - hi, lo, i - 1, node);
        node->right = __build_ip(root - 1, i + 1, hi, node);
        __updateH(node);
        return node;
    }
    TreeNode<T> *__build_pp(int leftOfpre, int rightOfpre, int leftOfpost, int rightOfpost)
    {
        if (leftOfpre > rightOfpre || leftOfpost > rightOfpost)
            return nullptr;
        TreeNode<T> *root = new TreeNode<T>(preorder[leftOfpre]);
        if (leftOfpre == rightOfpre)
            return root;
        int leftSubVal = preorder[leftOfpre + 1], i, sub_cnt;
        for (i = leftOfpost; i < rightOfpost && postorder[i] != leftSubVal; i++)
            ;
        sub_cnt = i - leftOfpost;
        if (i + 1 < rightOfpost) // 2 child
        {
            root->left = __build_pp(leftOfpre + 1, leftOfpre + sub_cnt + 1, leftOfpost, i);
            root->right = __build_pp(leftOfpre + sub_cnt + 2, rightOfpre, i + 1, rightOfpost - 1);
        }
        else
        {
            root->left = __build_pp(leftOfpre + 1, rightOfpre, leftOfpost, rightOfpost - 1);
            // only one child, default choose left
            isunique = 0;
        }
        return root;
    }
    TreeNode<T> *__invert(TreeNode<T> *root)
    {
        if (!root)
            return nullptr;
        TreeNode<T> *tmp = invert(root->right);
        root->right = invert(root->left);
        root->left = tmp;
        return root;
    }
    void __del_leaf(TreeNode<T> *&root, TreeNode<T> *p)
    {
        if (!root)
            return;
        if (!root->left && !root->right)
        {
            if (p)
            {
                if (root == p->left)
                    p->left = nullptr;
                if (root == p->right)
                    p->right = nullptr;
                delete root;
            }
            return;
        }
        __del_leaf(root->left, root);
        __del_leaf(root->right, root);
    }
    int __leafcount()
    {
        if (!this->_ROOT)
            return -1;
        int cnt = 0;
        queue<TreeNode<T> *> q;
        q.push(this->_ROOT);
        while (q.size())
        {
            tp1 = q.front(), q.pop();
            if (!tp1->left && !tp1->right)
                cnt++;
            if (tp1->left)
                q.push(tp1->left);
            if (tp1->right)
                q.push(tp1->right);
        }
        return cnt;
    }
    int __nodecount()
    {
        if (!this->_ROOT)
            return 0;
        int cnt = 0;
        queue<TreeNode<T> *> q;
        q.push(this->_ROOT);
        while (q.size())
        {
            tp1 = q.front(), q.pop();
            cnt++;
            if (tp1->left)
                q.push(tp1->left);
            if (tp1->right)
                q.push(tp1->right);
        }
        return cnt;
    }
    void __del_targetSub(TreeNode<T> *root, int target)
    {
        queue<TreeNode<T> *> q;
        TreeNode<T> *x;
        if (root->val == target)
        {
            __del_allSub(root);
            return;
        }
        q.push(root);
        while (q.size())
        {
            x = q.front(), q.pop();
            if (x->left)
            {
                if (x->left->val == target)
                {
                    __del_allSub(x->left);
                    x->left = nullptr;
                }
                else
                    q.push(x->left);
            }
            if (x->right)
            {
                if (x->right->val == target)
                {
                    __del_allSub(x->right);
                    x->right = nullptr;
                }
                else
                    q.push(x->right);
            }
        }
    }
    void __del_allSub(TreeNode<T> *root)
    {
        if (!root)
            return;
        __del_allSub(root->left);
        __del_allSub(root->right);
        delete root;
    }
    bool __TreeIdentical(TreeNode<T> *T1, TreeNode<T> *T2)
    {
        if (!T1 && !T2)
            return 1;
        if (!T1 || !T2 || T1->val != T2->val)
            return 0;
        bool lf = __TreeIdentical(T1->left, T2->left);
        bool rf = __TreeIdentical(T1->right, T2->right);
        return lf && rf;
    }
    bool __TreeSimilar(TreeNode<T> *T1, TreeNode<T> *T2)
    {
        if (!T1 && !T2)
            return 1;
        if (!T1 || !T2) // if wanna test the two trees is identical , plus "|| T1->val != T2->val"
            return 0;
        bool lf = __TreeSimilar(T1->left, T2->left);
        bool rf = __TreeSimilar(T1->right, T2->right);
        return lf && rf;
    }
    void __tree2Infix(TreeNode<string> *root, int depth, string &s)
    {
        if (!root)
            return;
        if (!root->left && !root->right)
            s += root->val;
        else
        {
            if (depth)
                s.push_back('(');
            __tree2Infix(root->left, depth + 1, s);
            s += root->val;
            __tree2Infix(root->right, depth + 1, s);
            if (depth)
                s.push_back(')');
        }
    }
    template <class _Function>
    void __recur_pre(TreeNode<T> *root, _Function f)
    {
        if (!root)
            return;
        f(root);
        __recur_pre(root->left, f);
        __recur_pre(root->right, f);
    }
    template <class _Function>
    void __recur_in(TreeNode<T> *root, _Function f)
    {
        if (!root)
            return;
        __recur_in(root->left, f);
        f(root);
        __recur_in(root->right, f);
    }
    template <class _Function>
    void __recur_post(TreeNode<T> *root, _Function f)
    {
        if (!root)
            return;
        __recur_post(root->left, f);
        __recur_post(root->right, f);
        f(root);
    }

    double __op(double a, double b, char oper)
    {
        double res;
        switch (oper)
        {
        case '+':
            res = a + b;
            break;
        case '-':
            res = a - b;
            break;
        case '*':
            res = a * b;
            break;
        case '/':
            res = a / b;
            break;
        }
        return res;
    }
    double __infix_val(TreeNode<string> *root)
    {
        if (!root)
            return 0;
        if (root->left && root->right)
        {
            double a = stof(__infix_val(root->left)), b = stof(__infix_val(root->right));
            return __op(a, b, root->val[0]);
        }
        return stof(root->val);
    }

public:
    unordered_map<T, TreeNode<T> *> table;
    vector<T> preorder, inorder, postorder;
    Bin_Tree()
    {
        this->_ROOT = nullptr;
    }
    inline TreeNode<T> *ROOT()
    {
        return this->_ROOT;
    }
    void build_pi(vector<int> &pr, vector<int> &in)
    {
        this->preorder = pr, this->inorder = in;
        __updateROOT(__build_pi(0, 0, pr.size() - 1, nullptr));
    }
    void build_ip(vector<int> &in, vector<int> &po)
    {
        this->postorder = po, this->inorder = in;
        __updateROOT(__build_ip(in.size() - 1, 0, in.size() - 1, nullptr));
    }
    void invert()
    {
        __updateROOT(__invert(this->_ROOT));
    }
    void delLeaf()
    {
        __del_leaf(this->_ROOT, nullptr);
    }
    int countleaf()
    {
        return __leafcount();
    }
    int countnode()
    {
        return __nodecount();
    }
    bool similar(Bin_Tree<T> T2)
    {
        return __TreeSimilar(this->_ROOT, T2.ROOT());
    }
    bool identical(Bin_Tree<T> T2)
    {
        return __TreeIdentical(this->_ROOT, T2.ROOT());
    }
    string tree2infix()
    {
        string s;
        __tree2Infix(this->_ROOT, 0, s);
        return s;
    }
    double infixval()
    {
        return __infix_val(this->_ROOT);
    }
    bool iscmp()
    {
        queue<TreeNode<T> *> q;
        TreeNode<T> *root = this->_ROOT;
        q.push(root);
        while (q.size())
        {
            tp1 = q.front(), q.pop();
            if (tp1)
                q.push(tp1->left), q.push(tp1->right);
            else
                while (q.size())
                {
                    tp1 = q.front(), q.pop();
                    if (tp1)
                        return false;
                }
        }
        return true;
    }

    template <class _Function>
    void intrav(_Function f)
    {
        __recur_in(this->_ROOT, f);
    }
    void inTrav()
    {
        vector<int> resSeq;
        stack<TreeNode<T> *> s;
        TreeNode<T> *root = this->_ROOT;
        if (!root)
            return;
        TreeNode<T> *p = root;
        while (s.size() || p)
        {
            while (p)
            {
                s.push(p);
                p = p->left;
            }
            if (s.size())
            {
                p = s.top();
                s.pop();
                resSeq.push_back(p->val);
                p = p->right;
            }
        }
        this->inorder = resSeq;
    }
    void preTrav()
    {
        vector<int> resSeq;
        TreeNode<T> *root = this->_ROOT;
        if (!root)
            return;
        stack<TreeNode<T> *> s;
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
        this->preorder = resSeq;
    }
    void postTrav()
    {
        vector<int> resSeq;
        TreeNode<T> *root = this->_ROOT;
        if (!root)
            return;
        stack<pair<TreeNode<T> *, bool>> s;
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
        this->postorder = resSeq;
    }
    TreeNode<T> *get_LCA(TreeNode<T> *p, TreeNode<T> *q)
    {
        while (p->depth > q->depth)
            p = p->parent;
        while (q->depth > p->depth)
            q = q->parent;
        while (p != q)
            p = p->parent, q = q->parent;
        return p;
    }

    // T1 <-> T2  convertable, left <-> right;
    int Isomprphic(TreeNode<T> *root1, TreeNode<T> *root2)
    {
        if (!root1 && !root2)
            return 1;
        if ((!root1 && root2) || (!root2 && root1))
            return 0;
        if (root1->val != root2->val)
            return 0;
        if (!root1->left && !root2->left)
            return Isomprphic(root1->right, root2->right);
        if (root1->left && root2->left && root1->left->val == root2->left->val)
            return Isomprphic(root1->left, root2->left) && Isomprphic(root1->right, root2->right);
        else
            return Isomprphic(root1->left, root2->right) && Isomprphic(root1->right, root2->left);
    }

    void InThread(TreeNode<T> *root, TreeNode<T> *pre)
    {
        if (root)
        {
            InThread(root->left, pre);
            if (!root->left)
            {
                root->ltag = 1;
                root->left = pre;
            }
            if (pre && !pre->right)
            {
                pre->rtag = 1;
                pre->right = root;
            }
            InThread(root->right, root);
        }
    }
};

// 后缀表达式 -> exp_tree
// stack : node*; 遇 oprand: create node then push, 遇operator: pop 2 item become its childs, then push, 2nd_pop item is left.
template <typename T>
class Huffman : public Bin_Tree<T>
{
public:
    struct cmp
    {
        bool operator()(const TreeNode<T> *a, const TreeNode<T> *b) const { return a->val > b->val; }
    };
    void createHuffman(vector<int> &data)
    {
        priority_queue<TreeNode<T> *, vector<TreeNode<T> *>, cmp> pq;
        TreeNode<T> *v, *w, *root;
        for (auto i : data)
            pq.push(new TreeNode<T>(i));
        while (pq.size() > 1)
        {
            v = pq.top(), pq.pop();
            w = pq.top(), pq.pop();
            root = new TreeNode<T>(v->val + w->val);
            root->left = v, root->right = w;
            pq.push(root);
        }
        this->_ROOT = root;
    }
    void WPl_sum(TreeNode<T> *root, int &wpl)
    {
        if (!root)
            return;
        if (root->left)
            wpl += root->val;
        WPl_sum(root->left, wpl);
        WPl_sum(root->right, wpl);
    };
    void wpl_sum(TreeNode<T> *root, int &wpl)
    {
        queue<TreeNode<T> *> q, nexq;
        q.push(root);
        TreeNode<T> *v;
        int le = 0;
        while (q.size())
        {
            while (q.size())
            {
                v = q.front(), q.pop();
                if (!v->left && !v->right)
                    wpl += le * v->val;
                if (v->left)
                    nexq.push(v->left);
                if (v->right)
                    nexq.push(v->right);
            }
            swap(q, nexq);
            le++;
        }
    };
};
template <typename T>
class BST : public Bin_Tree<T>
{
protected:
    void __insert(TreeNode<T> *&root, int v)
    {
        if (!root)
        {
            root = new TreeNode<T>(v);
            return;
        }
        root->val <= v ? __insert(root->right, v) : __insert(root->left, v);
    }
    bool __judge_avl(TreeNode<T> *root)
    {
        if (!root)
            return true;
        bool f1 = __judge_avl(root->left);
        bool f2 = __judge_avl(root->right);
        this->__updateH(root);
        return f1 && f2 && abs(this->__factor(root)) < 2;
    }
    TreeNode<T> *__delete(TreeNode<T> *&root, int x)
    {
        if (!root)
            return nullptr;
        if (x < root->val)
            root->left = __delete(root->left, x);
        else if (root->val < x)
            root->right = __delete(root->right, x);
        else
        {
            TreeNode<T> *tmp;
            if (root->left && root->right)
            {
                tmp = this->__getMinOfR(root->right);
                root->val = tmp->val;
                root->right = __delete(root->right, tmp->val);
            }
            else
            {
                tmp = root;
                root = root->left ? root->left : root->right;
                delete tmp;
            }
        }
        return root;
    }

public:
    void create_BST(vector<int> &a)
    {
        for (auto i : a)
            __insert(this->_ROOT, i);
    }
    bool is_balanced()
    {
        return __judge_avl(this->_ROOT);
    }
    void del_one(T val)
    {
        __delete(this->_ROOT, val);
    }
};

template <typename T>
class AVLTree : public BST<T>
{
public:
    void create_BST(vector<int> &a)
    {
        for (auto i : a)
            __insert(this->_ROOT, i);
    }
    void del_one(T val)
    {
        __delete(this->_ROOT, val);
    }

protected:
    inline void LL(TreeNode<T> *&root)
    {
        TreeNode<T> *tmp = root->left;
        root->left = tmp->right;
        tmp->right = root;
        this->__updateH(root);
        this->__updateH(tmp);
        root = tmp;
    }
    inline void RR(TreeNode<T> *&root)
    {
        TreeNode<T> *tmp = root->right;
        root->right = tmp->left;
        tmp->left = root;
        this->__updateH(root);
        this->__updateH(tmp);
        root = tmp;
    }
    inline void LR(TreeNode<T> *&root)
    {
        RR(root->left);
        LL(root);
    }
    inline void RL(TreeNode<T> *&root)
    {
        LL(root->right);
        RR(root);
    }
    void __insert(TreeNode<T> *&root, int val)
    {
        if (!root)
        {
            root = new TreeNode<T>(val);
            return;
        }
        else if (val < root->val)
        {
            __insert(root->left, val);
            this->__updateH(root);
            if (this->__factor(root) == 2)
                this->__factor(root->left) == 1 ? LL(root) : LR(root);
        }
        else if (val > root->val)
        {
            __insert(root->right, val);
            this->__updateH(root);
            if (this->__factor(root) == -2)
                this->__factor(root->right) == -1 ? RR(root) : RL(root);
        }
    }

    TreeNode<T> *__delete(TreeNode<T> *&root, int val)
    {
        if (!root)
            return nullptr;
        else if (root->val > val)
        {
            root->left = __delete(root->left, val);
            this->__updateH(root);
            if (this->__factor(root) == -2)
                this->__factor(root->right) == -1 ? RR(root) : RL(root);
        }
        else if (root->val < val)
        {
            root->right = __delete(root->right, val);
            this->__updateH(root);
            if (this->__factor(root) == 2)
            {
                (this->__factor(root->left) == 1) ? LL(root) : LR(root);
            }
        }
        else // find it
        {
            if (root->right && root->left)
            {
                if (this->__factor(root) > 0)
                {
                    TreeNode<T> *tmp = this->__getMaxOfL(root->left);
                    root->val = tmp->val;
                    root->left = __delete(root->left, tmp->val);
                }
                else
                {
                    TreeNode<T> *tmp = this->__getMinOfR(root->right);
                    root->val = tmp->val;
                    root->right = __delete(root->right, tmp->val);
                }
            }
            else
            {
                TreeNode<T> *tmp = root;
                root = (root->left == nullptr ? root->right : root->left);
                delete tmp;
            }
        }
        return root;
    }
};
}; // namespace newtree