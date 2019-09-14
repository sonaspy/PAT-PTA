// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

using namespace std;

#ifndef __NEW_TREE__
#define __NEW_TREE__
namespace newtree
{
#define MAXCOL 1000
#define MAXROW 20

template <typename T>
struct BinNode
{
    T val;
    BinNode *left, *right, *parent;
    int height, depth, ltag, rtag;
    BinNode(T x) : val(x), left(nullptr), right(nullptr), parent(nullptr), height(1), depth(1), ltag(0), rtag(0) {}
    bool inline is_l()
    {
        return parent && parent->left == this;
    }
    bool inline is_r()
    {
        return parent && parent->right == this;
    }
    bool inline isroot()
    {
        return parent == nullptr;
    }
};

template <typename T>
class BinTree
{
protected:
    BinNode<T> *_ROOT, *tp1;
    unordered_set<BinNode<T> *> __MEM_OF_NODE;
    deque<BinNode<T> *> q, nexq;
    int _cnt;
    bool isunique; // pre post build
    vector<vector<string>> disp_buf;
    inline int __height(BinNode<T> *root) { return root == nullptr ? 0 : root->height; }
    inline int __depth(BinNode<T> *root) { return root == nullptr ? 0 : root->depth; }
    inline void __updatedepth(BinNode<T> *root) { root->depth = __depth(root->parent) + 1; }
    inline void __updateheight(BinNode<T> *root) { root->height = max(__height(root->left), __height(root->right)) + 1; }
    inline int __factor(BinNode<T> *root) { return __height(root->left) - __height(root->right); }
    inline BinNode<T> *__getmax(BinNode<T> *root)
    {
        while (root->right)
            root = root->right;
        return root;
    }
    inline BinNode<T> *__getmin(BinNode<T> *root)
    {
        while (root->left)
            root = root->left;
        return root;
    }
    inline void __updateROOT(BinNode<T> *root)
    {
        this->_ROOT = root;
    }
    BinNode<T> *__build_pi(int root, int lo, int hi, BinNode<T> *p)
    {
        if (hi < lo)
            return nullptr;
        int i = lo;
        BinNode<T> *node = new BinNode<T>(preorder[root]);
        __MEM_OF_NODE.insert(node);
        table[preorder[root]] = node;
        node->parent = p;
        __updatedepth(node);
        while (i < hi && inorder[i] != preorder[root])
            i++;
        node->left = __build_pi(root + 1, lo, i - 1, node);
        node->right = __build_pi(root + 1 + i - lo, i + 1, hi, node);
        __updateheight(node);
        return node;
    }
    void __print(BinNode<T> *root, int root_x, int root_y, int interval)
    {
        if (!root)
            return;
        int left_child = root_y - interval, right_child = root_y + interval;
        string tp = to_string(root->val);
        if (tp.size() == 1)
            tp.push_back(' ');
        disp_buf[root_x][root_y] = tp;
        if (root->left)
            disp_buf[root_x + 1][root_y - (interval + 1) / 2] = "/ ";
        if (root->right)
            disp_buf[root_x + 1][root_y + (interval + 1) / 2] = " \\";
        __print(root->left, root_x + 2, left_child, (interval >> 1));
        __print(root->right, root_x + 2, right_child, (interval >> 1));
    }
    BinNode<T> *__build_ip(int root, int lo, int hi, BinNode<T> *p)
    {
        if (hi < lo)
            return nullptr;
        int i = lo;
        BinNode<T> *node = new BinNode<T>(postorder[root]);
        __MEM_OF_NODE.insert(node);
        table[postorder[root]] = node;
        node->parent = p;
        __updatedepth(node);
        while (i < hi && inorder[i] != postorder[root])
            i++;
        node->left = __build_ip(root - 1 + i - hi, lo, i - 1, node);
        node->right = __build_ip(root - 1, i + 1, hi, node);
        __updateheight(node);
        return node;
    }
    BinNode<T> *__build_pp(int leftOfpre, int rightOfpre, int leftOfpost, int rightOfpost)
    {
        if (leftOfpre > rightOfpre || leftOfpost > rightOfpost)
            return nullptr;
        BinNode<T> *root = new BinNode<T>(preorder[leftOfpre]);
        __MEM_OF_NODE.insert(root);
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
    BinNode<T> *__invert(BinNode<T> *root)
    {
        if (!root)
            return nullptr;
        BinNode<T> *tmp = __invert(root->right);
        root->right = __invert(root->left);
        root->left = tmp;
        return root;
    }
    void __del_leaf(BinNode<T> *&root, BinNode<T> *p)
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
                this->__MEM_OF_NODE.erase(root);
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
        this->q.push_back(this->_ROOT);
        while (this->q.size())
        {
            tp1 = this->q.front(), this->q.pop_front();
            if (!tp1->left && !tp1->right)
                cnt++;
            if (tp1->left)
                this->q.push_back(tp1->left);
            if (tp1->right)
                this->q.push_back(tp1->right);
        }
        this->q.clear();
        return cnt;
    }
    int __nodecount()
    {
        if (!this->_ROOT)
            return 0;
        int cnt = 0;
        this->q.push_back(this->_ROOT);
        while (this->q.size())
        {
            tp1 = this->q.front(), this->q.pop_front();
            cnt++;
            if (tp1->left)
                this->q.push_back(tp1->left);
            if (tp1->right)
                this->q.push_back(tp1->right);
        }
        this->q.clear();
        return cnt;
    }
    void __del_targetSub(BinNode<T> *root, int target)
    {
        BinNode<T> *x;
        if (root->val == target)
        {
            __del_allSub(root);
            return;
        }
        this->q.push_back(root);
        while (this->q.size())
        {
            x = this->q.front(), this->q.pop_front();
            if (x->val == target)
            {
                __del_allSub(x->left);
                __del_allSub(x->right);
                x->left = x->right = nullptr;
                continue;
            }
            if (x->left)
                this->q.push_back(x->left);
            if (x->right)
                this->q.push_back(x->right);
        }
        this->q.clear();
    }
    void __del_allSub(BinNode<T> *root)
    {
        if (!root)
            return;
        __del_allSub(root->left);
        __del_allSub(root->right);
        this->__MEM_OF_NODE.erase(root);
        delete root;
    }
    bool __TreeIdentical(BinNode<T> *T1, BinNode<T> *T2)
    {
        if (!T1 && !T2)
            return 1;
        if (!T1 || !T2 || T1->val != T2->val)
            return 0;
        bool lf = __TreeIdentical(T1->left, T2->left);
        bool rf = __TreeIdentical(T1->right, T2->right);
        return lf && rf;
    }
    bool __TreeSimilar(BinNode<T> *T1, BinNode<T> *T2)
    {
        if (!T1 && !T2)
            return 1;
        if (!T1 || !T2) // if wanna test the two trees is identical , plus "|| T1->val != T2->val"
            return 0;
        return __TreeSimilar(T1->left, T2->left) && __TreeSimilar(T1->right, T2->right);
    }
    void __tree2Infix(BinNode<string> *root, int depth, string &s)
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
    void __recur_pre(BinNode<T> *root, _Function f)
    {
        if (!root)
            return;
        f(root);
        __recur_pre(root->left, f);
        __recur_pre(root->right, f);
    }
    template <class _Function>
    void __recur_in(BinNode<T> *root, _Function f)
    {
        if (!root)
            return;
        __recur_in(root->left, f);
        f(root);
        __recur_in(root->right, f);
    }
    template <class _Function>
    void __recur_post(BinNode<T> *root, _Function f)
    {
        if (!root)
            return;
        __recur_post(root->left, f);
        __recur_post(root->right, f);
        f(root);
    }

    void __InThread(BinNode<T> *root, BinNode<T> *pre)
    {
        if (root)
        {
            __InThread(root->left, pre);
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
            __InThread(root->right, root);
        }
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
    double __infix_val(BinNode<string> *root)
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
    int __diameter()
    {
        q.push_back(this->_ROOT);
        int level = 0, last = 0;
        while (q.size())
        {
            if (q.size() > 1)
                last = level;
            while (q.size())
            {
                tp1 = q.front(), q.pop_front();
                if (tp1->left)
                    nexq.push_back(tp1->left);
                if (tp1->right)
                    nexq.push_back(tp1->right);
            }
            level++;
            swap(q, nexq);
        }
        this->q.clear(), this->nexq.clear();
        return last + level - 1;
    }

    void __update_member(BinNode<T> *root, BinNode<T> *p)
    {
        if (!root)
            return;
        root->parent = p;
        __updatedepth(root);
        __update_member(root->left, root);
        __update_member(root->right, root);
        __updateheight(root);
    }

public:
    unordered_map<T, BinNode<T> *> table;
    vector<T> preorder, inorder, postorder;
    BinTree()
    {
        this->_ROOT = nullptr;
        this->isunique = true;
        this->q.clear(), this->nexq.clear();
        this->_cnt = 0;
    }
    void printTree()
    {
        if (!this->_ROOT)
            return;
        printf("🌲\n");
        this->disp_buf = vector<vector<string>>(MAXROW, vector<string>(MAXCOL, string(2, ' ')));
        __print(this->_ROOT, 0, pow(2, this->_ROOT->height - 1) - 1, pow(2, this->_ROOT->height - 2));
        int n = this->_ROOT->height * 2 - 1, i, j;
        for (i = 0; i < n; ++i)
        {
            j = MAXCOL;
            while (j > 0 && disp_buf[i][--j] == "  ")
                ;
            disp_buf[i][j + 1] = "!";
        }
        for (i = 0; i < n; ++i)
        {
            for (j = 0; j < MAXCOL; ++j)
            {
                if (disp_buf[i][j] == "!")
                    break;
                cout << disp_buf[i][j];
            }
            cout << endl;
        }
        printf("🌲\n");
    }

    inline BinNode<T> *root()
    {
        return this->_ROOT;
    }
    BinNode<T> *__buildcmp(int id, vector<int> &a)
    {
        if (a.size() - 1 < id)
            return nullptr;
        BinNode<T> *v = new BinNode<T>(a[id]);
        __MEM_OF_NODE.insert(v);
        v->left = __buildcmp(id * 2 + 1, a);
        v->right = __buildcmp(id * 2 + 2, a);
        return v;
    }
    inline void build_cmp(vector<int> &a)
    {
        __updateROOT(__buildcmp(0, a));
        __update_status();
    }
    inline void build_pi(vector<int> &pr, vector<int> &in)
    {
        this->preorder = pr, this->inorder = in;
        __updateROOT(__build_pi(0, 0, pr.size() - 1, nullptr));
        this->_cnt = in.size();
    }
    inline void build_ip(vector<int> &in, vector<int> &po)
    {
        this->postorder = po, this->inorder = in;
        __updateROOT(__build_ip(in.size() - 1, 0, in.size() - 1, nullptr));
        this->_cnt = in.size();
    }
    inline void invert()
    {
        if (!this->_ROOT)
            return;
        __invert(this->_ROOT);
        __update_status();
    }
    inline void eraseLeaf()
    {
        if (!this->_ROOT)
            return;
        __del_leaf(this->_ROOT, nullptr);
        this->_cnt = __nodecount();
        __update_status();
    }
    inline int countleaf()
    {
        if (!this->_ROOT)
            return 0;
        return __leafcount();
    }
    inline int size()
    {
        return _cnt;
    }
    inline int height()
    {
        if (!this->_ROOT)
            return 0;
        return this->_ROOT->height;
    }
    inline void __update_status()
    {
        this->__update_member(_ROOT, nullptr);
    }
    inline int diam() { return __diameter(); }
    inline bool similar(BinTree<T> T2)
    {
        return __TreeSimilar(this->_ROOT, T2.root());
    }
    inline bool identical(BinTree<T> T2)
    {
        return __TreeIdentical(this->_ROOT, T2.root());
    }
    inline bool symmetric()
    {
        if (!this->_ROOT)
            return true;
        return __TreeSimilar(this->_ROOT->left, this->_ROOT->right);
    }
    BinNode<T> *convert2list()
    {
        if (!this->_ROOT)
            return;
        vector<BinNode<T> *> ls;
        intrav([&](BinNode<T> *v) { ls.push_back(v); });
        auto p1 = ls.begin(), p2 = ls.begin() + 1;
        BinNode<T> *head = *p1;
        for (; p2 != ls.end(); p1++, p2++)
        {
            (*p1)->left = nullptr;
            (*p1)->right = (*p2);
        }
        (*p1)->right = (*p1)->left = nullptr;
        return head;
    }
    string tree2infix()
    {
        string s;
        __tree2Infix(this->_ROOT, 0, s);
        return s;
    }
    void eraseSubOf(T v)
    {
        if (!this->_ROOT)
            return;
        __del_targetSub(this->_ROOT, v);
    }
    double infixval()
    {
        return __infix_val(this->_ROOT);
    }
    bool iscmp()
    {
        if (!this->_ROOT)
            return true;
        BinNode<T> *root = this->_ROOT;
        this->q.push_back(root);
        while (this->q.size())
        {
            tp1 = this->q.front(), this->q.pop_front();
            if (tp1)
                this->q.push_back(tp1->left), this->q.push_back(tp1->right);
            else
                while (this->q.size())
                {
                    tp1 = this->q.front(), this->q.pop_front();
                    if (tp1)
                        return false;
                }
        }
        this->q.clear();
        return true;
    }
    inline void clear()
    {
        _ROOT = tp1 = nullptr;
        q.clear(), nexq.clear();
        _cnt = 0;
        isunique = 1;
        disp_buf.clear();
        for (auto &p : __MEM_OF_NODE)
            delete p;
        __MEM_OF_NODE.clear();
    }

    template <class _Function>
    void intrav(_Function f)
    {
        __recur_in(this->_ROOT, f);
    }
    template <class _Function>
    void pretrav(_Function f)
    {
        __recur_pre(this->_ROOT, f);
    }
    template <class _Function>
    void posttrav(_Function f)
    {
        __recur_post(this->_ROOT, f);
    }
    void inTrav()
    {
        vector<T> resSeq;
        stack<BinNode<T> *> s;
        BinNode<T> *root = this->_ROOT;
        if (!root)
            return;
        BinNode<T> *p = root;
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
        vector<T> resSeq;
        BinNode<T> *root = this->_ROOT;
        if (!root)
            return;
        stack<BinNode<T> *> s;
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
        vector<T> resSeq;
        BinNode<T> *root = this->_ROOT;
        if (!root)
            return;
        stack<pair<BinNode<T> *, bool>> s;
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
    BinNode<T> *get_LCA(BinNode<T> *p, BinNode<T> *q)
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
    int Isomprphic(BinNode<T> *root1, BinNode<T> *root2)
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
    ~BinTree()
    {
        this->clear();
    }
};

// 后缀表达式 -> exp_tree
// stack : node*; 遇 oprand: build node then push, 遇operator: pop 2 item become its childs, then push, 2nd_pop item is left.
template <typename T>
class Huffman : public BinTree<T>
{
protected:
    int _wpl;
    struct __cmp
    {
        bool operator()(const BinNode<T> *a, const BinNode<T> *b) const { return a->val > b->val; }
    };
    void __build_hfm(vector<int> &data)
    {
        priority_queue<BinNode<T> *, vector<BinNode<T> *>, __cmp> pq;
        BinNode<T> *v, *w, *root;
        for (auto i : data)
        {
            BinNode<T> *v = new BinNode<T>(i);
            pq.push_back(v);
            this->__MEM_OF_NODE.insert(v);
        }
        while (pq.size() > 1)
        {
            v = pq.top(), pq.pop_front();
            w = pq.top(), pq.pop_front();
            root = new BinNode<T>(v->val + w->val);
            this->__MEM_OF_NODE.insert(root);
            root->left = v, root->right = w;
            pq.push_back(root);
        }
        this->__updateROOT(root);
    }
    void __wpl(BinNode<T> *root)
    {
        if (!root)
            return;
        if (root->left)
            _wpl += root->val;
        __wpl(root->left);
        __wpl(root->right);
    };

public:
    Huffman()
    {
        _wpl = -1;
    }
    void build(vector<int> &a)
    {
        if (a.empty())
            return;
        __build_hfm(a);
    }
    inline void clear()
    {
        BinTree<T>::clear();
        _wpl = 0;
    }
    int wpl()
    {
        if (_wpl == -1)
            __wpl(this->_ROOT);
        return _wpl;
    }
    ~Huffman() { this->clear(); }
};
template <typename T>
class BST : public BinTree<T>
{
protected:
    BinNode<T> *_last;
    inline void __attAsL(BinNode<T> *&p, BinNode<T> *&lc)
    {
        p->left = lc;
        if (lc)
            lc->parent = p;
    }
    inline void __attAsR(BinNode<T> *&p, BinNode<T> *&rc)
    {
        p->right = rc;
        if (rc)
            rc->parent = p;
    }
    BinNode<T> *__search(BinNode<T> *&root, const T &v)
    {
        BinNode<T> *x = root;
        while (x)
        {
            if (x->val == v)
                break;
            this->_last = x;
            x = x->val < v ? x->right : x->left;
        }
        return x;
    }
    void __insert(BinNode<T> *&root, const T &v)
    {
        if (!root)
        {
            root = new BinNode<T>(v);
            this->__MEM_OF_NODE.insert(root);
            this->_cnt++;
            return;
        }
        this->_last = nullptr;
        BinNode<T> *x = __search(root, v);
        if (x)
            return;
        x = new BinNode<T>(v);
        this->__MEM_OF_NODE.insert(x);
        v < this->_last->val ? this->_last->left = x : this->_last->right = x;
        this->_cnt++;
    }
    bool __judge_avl(BinNode<T> *root)
    {
        if (!root)
            return true;
        bool f1 = __judge_avl(root->left);
        bool f2 = __judge_avl(root->right);
        this->__updateheight(root);
        return f1 && f2 && abs(this->__factor(root)) < 2;
    }

    BinNode<T> *__delete(BinNode<T> *&root, T x)
    {
        if (!root)
            return nullptr;
        if (x < root->val)
            root->left = __delete(root->left, x);
        else if (root->val < x)
            root->right = __delete(root->right, x);
        else
        {
            BinNode<T> *tmp;
            if (root->left && root->right)
            {
                tmp = this->__getmin(root->right);
                root->val = tmp->val;
                root->right = __delete(root->right, tmp->val);
            }
            else
            {
                tmp = root;
                root = root->left ? root->left : root->right;
                BinTree<T>::__MEM_OF_NODE.erase(tmp);
                delete tmp;
            }
        }
        return root;
    }

public:
    void build(vector<T> &a)
    {
        for (auto i : a)
            __insert(this->_ROOT, i);
        this->__update_status();
    }
    bool balanced()
    {
        return __judge_avl(this->_ROOT);
    }
    void erase(const T &val)
    {
        __delete(this->_ROOT, val);
        this->_cnt--;
    }
    void insert(const T &val)
    {
        __insert(this->_ROOT, val);
    }
    BinNode<T> *locate(const T &e)
    {
        this->_last = nullptr;
        return __search(this->_ROOT, e);
    }
    inline void clear()
    {
        BinTree<T>::clear();
        this->_last = nullptr;
    }
    BinNode<T> *findLCA(T v1, T v2)
    {
        BinNode<T> *walk = this->_ROOT;
        while (walk)
        {
            if (v1 < walk->val && v2 < walk->val)
                walk = walk->left;
            else if (walk->val < v1 && walk->val < v2)
                walk = walk->right;
            else
                break;
        }
        return walk;
    }
    inline bool exist(const T &e)
    {
        return locate(e);
    }
    ~BST() { this->clear(); }
};

template <typename T>
class AVLTree : public BST<T>
{
public:
    void build(vector<T> &a)
    {
        for (auto i : a)
            __insert(this->_ROOT, i, nullptr);
        this->__update_status();
    }
    void erase(const T &val)
    {
        __delete(this->_ROOT, val);
        this->__update_status();
        this->_cnt--;
    }
    void insert(const T &val)
    {
        __insert(this->_ROOT, val, nullptr);
        this->__update_status();
    }
    inline void clear() { BST<T>::clear(); }
    ~AVLTree()
    {
        this->clear();
    }

protected:
    inline void _zig(BinNode<T> *&root)
    {
        BinNode<T> *tmp = root->left;
        root->left = tmp->right;
        if (tmp->right)
            tmp->right->parent = root;
        tmp->right = root;
        tmp->parent = root->parent;
        root->parent = tmp;
        this->__updateheight(root);
        this->__updateheight(tmp);
        root = tmp;
    }
    inline void _zag(BinNode<T> *&root)
    {
        BinNode<T> *tmp = root->right;
        root->right = tmp->left;
        if (tmp->left)
            tmp->left->parent = root;
        tmp->left = root;
        tmp->parent = root->parent;
        root->parent = tmp;
        this->__updateheight(root);
        this->__updateheight(tmp);
        root = tmp;
    }
    inline void _zigzag(BinNode<T> *&root)
    {
        _zag(root->left);
        _zig(root);
    }
    inline void _zagzig(BinNode<T> *&root)
    {
        _zig(root->right);
        _zag(root);
    }
    void __insert(BinNode<T> *&root, const T &val, BinNode<T> *p)
    {
        if (!root)
        {
            root = new BinNode<T>(val);
            this->__MEM_OF_NODE.insert(root);
            root->parent = p;
            this->_cnt++;
            return;
        }
        else if (val < root->val)
        {
            __insert(root->left, val, root);
            this->__updateheight(root);
            if (this->__factor(root) == 2)
                this->__factor(root->left) == 1 ? _zig(root) : _zigzag(root);
        }
        else if (val > root->val)
        {
            __insert(root->right, val, root);
            this->__updateheight(root);
            if (this->__factor(root) == -2)
                this->__factor(root->right) == -1 ? _zag(root) : _zagzig(root);
        }
    }

    BinNode<T> *__delete(BinNode<T> *&root, const T &val)
    {
        if (!root)
            return nullptr;
        if (val < root->val)
        {
            root->left = __delete(root->left, val);
            this->__updateheight(root);
            if (this->__factor(root) == -2)
                this->__factor(root->right) == -1 ? _zag(root) : _zagzig(root);
        }
        else if (root->val < val)
        {
            root->right = __delete(root->right, val);
            this->__updateheight(root);
            if (this->__factor(root) == 2)
                (this->__factor(root->left) == 1) ? _zig(root) : _zigzag(root);
        }
        else // find it
        {
            BinNode<T> *tmp;
            if (root->right && root->left)
            {
                if (this->__factor(root) > 0)
                {
                    tmp = this->__getmax(root->left);
                    root->val = tmp->val;
                    root->left = __delete(root->left, tmp->val);
                }
                else
                {
                    tmp = this->__getmin(root->right);
                    root->val = tmp->val;
                    root->right = __delete(root->right, tmp->val);
                }
            }
            else
            {
                tmp = root;
                root = root->left ? root->left : root->right;
                BinTree<T>::__MEM_OF_NODE.erase(tmp);
                delete tmp;
            }
        }
        return root;
    }
};

template <class T>
class splayTree : public BST<T>
{ // still bug there
protected:
    BinNode<T> *__splay(BinNode<T> *&v)
    {
        if (!v)
            return nullptr;
        BinNode<T> *p, *g, *gg;
        while (1)
        {
            p = v->parent;
            if (!p)
                break;
            g = p->parent;
            if (!g)
                break;
            if (v->is_l())
                if (p->is_l())
                    this->__attAsL(g, p->right), this->__attAsL(p, v->right), this->__attAsR(p, g), this->__attAsR(v, p);
                else
                    this->__attAsL(p, v->right), this->__attAsR(g, v->left), this->__attAsL(v, g), this->__attAsR(v, p);
            else if (p->is_r())
                this->__attAsR(g, p->left), this->__attAsR(p, v->left), this->__attAsL(p, g), this->__attAsL(v, p);
            else
                this->__attAsR(p, v->left), this->__attAsL(g, v->right), this->__attAsR(v, g), this->__attAsL(v, p);
            if (!gg)
                v->parent = nullptr;
            else
                g == gg->left ? this->__attAsL(gg, v) : this->__attAsR(gg, v);
            this->__updateheight(g), this->__updateheight(p), this->__updateheight(v);
        }
        p = v->parent;
        if (p)
        {
            if (v->is_l())
                this->__attAsL(p, v->right), this->__attAsR(v, p);
            else
                this->__attAsR(p, v->left), this->__attAsL(v, p);
            this->__updateheight(p), this->__updateheight(v);
        }
        v->parent = nullptr;
        return v;
    }

public:
    BinNode<T> *locate(const T &e)
    {
        this->_last = nullptr;
        BinNode<T> *p = this->__search(this->_ROOT, e);
        this->_ROOT = __splay(p ? p : this->_last);
        return this->_ROOT;
    }
};

template <typename T>
struct BNode
{
    T val;
    BNode *left, *right, *parent;
    int height, depth, ltag, rtag;
    BNode(T x) : val(x), left(nullptr), right(nullptr), parent(nullptr), height(1), depth(1), ltag(0), rtag(0) {}
    bool inline is_l()
    {
        return parent && parent->left == this;
    }
    bool inline is_r()
    {
        return parent && parent->right == this;
    }
    bool inline isroot()
    {
        return parent == nullptr;
    }
};

template <typename T>
class Heap
{
    // data[1....n] data[0] = INT_MAX
protected:
    vector<T> data;
    int _size;

    void __percDown(int pos)
    {
        T val = data[pos];
        int up = pos, down = 2 * pos;
        for (; down <= _size; up = down, down *= 2)
        {
            if (down < _size && data[down] < data[down + 1])
                ++down;
            if (data[down] > val)
                data[up] = data[down];
            else
                break;
        }
        data[up] = val;
    }

    void __buildHeap()
    {
        int i;
        for (i = _size / 2; i; --i)
            __percDown(i);
    }

public:
    Heap()
    {
        _size = 0;
    }
    void push(const T &val)
    {
        data.push_back(val);
        _size++;
        int i = _size;
        for (; data[i / 2] < val; i /= 2)
            data[i] = data[i / 2];
        data[i] = val;
    }
    void pop()
    {
        if (_size == 1)
            return;
        iter_swap(data.begin() + 1, data.end() - 1);
        data.pop_back();
        _size--;
        __percDown(1);
    }
    T top()
    {
        return data[1];
    }
    int size()
    {
        return _size;
    }
    void build(vector<T> &a)
    {
        data.push_back(INT_MAX);
        data.insert(data.end(), a.begin(), a.end());
        _size = a.size();
        __buildHeap();
    }
};

}; // namespace newtree
#endif