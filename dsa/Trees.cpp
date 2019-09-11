// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

using namespace std;
#define SIZE 10
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
public:
    TreeNode<T> *ROOT;
    string s;
    vector<int> preorder, inorder, postorder;
    bool isunique;
    inline int GetHeight(TreeNode<T> *root) { return root == nullptr ? 0 : root->height; }
    inline void updateHeight(TreeNode<T> *root) { root->height = max(GetHeight(root->left), GetHeight(root->right)) + 1; }
    inline int getFactor(TreeNode<T> *root) { return GetHeight(root->left) - GetHeight(root->right); }
    inline TreeNode<T> *getMax(TreeNode<T> *root)
    {
        while (root->right)
            root = root->right;
        return root;
    }
    inline TreeNode<T> *getROOT() { return ROOT; }
    inline TreeNode<T> *getMin(TreeNode<T> *root)
    {
        while (root->left)
            root = root->left;
        return root;
    }
    TreeNode<T> *__build1(int root, int lo, int hi)
    {
        if (hi < lo)
            return nullptr;
        int i = lo;
        TreeNode<T> *node = new TreeNode<T>(preorder[root]);
        while (i < hi && inorder[i] != preorder[root])
            i++;
        node->left = __build1(root + 1, lo, i - 1);
        node->right = __build1(root + 1 + i - lo, i + 1, hi);
        return node;
    }
    TreeNode<T> *__build2(int root, int lo, int hi)
    {
        if (hi < lo)
            return nullptr;
        int i = lo;
        TreeNode<T> *node = new TreeNode<T>(postorder[root]);
        while (i < hi && inorder[i] != postorder[root])
            i++;
        node->left = __build2(root - 1 + i - hi, lo, i - 1);
        node->right = __build2(root - 1, i + 1, hi);
        return node;
    }
    Bin_Tree()
    {
    }

    TreeNode<T> *invert(TreeNode<T> *root)
    {
        if (!root)
            return nullptr;
        TreeNode<T> *tmp = invert(root->right);
        root->right = invert(root->left);
        root->left = tmp;
        return root;
    }
    void deleteleave(TreeNode<T> *root, TreeNode<T> *preorder)
    {
        if (root)
        {
            if (!root->left && !root->right)
            {
                if (preorder)
                {
                    if (root == preorder->left)
                        preorder->left = NULL;
                    if (root == preorder->right)
                        preorder->right = NULL;
                    free(root);
                }
            }
            else
            {
                preorder = root;
                deleteleave(root->left, preorder);
                deleteleave(root->right, preorder);
            }
        }
    }
    void del_x_sub(TreeNode<T> *root, int target)
    {
        queue<TreeNode<T> *> q;
        TreeNode<T> *x;
        if (root->val == target)
        {
            del(root);
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
                    del(x->left);
                    x->left = nullptr;
                }
                else
                    q.push(x->left);
            }
            if (x->right)
            {
                if (x->right->val == target)
                {
                    del(x->right);
                    x->right = nullptr;
                }
                else
                    q.push(x->right);
            }
        }
    }
    void del(TreeNode<T> *root)
    {
        if (!root)
            return;
        del(root->left);
        del(root->right);
        delete root;
    }
    bool TreeSimilar(TreeNode<T> *T1, TreeNode<T> *T2)
    {
        if (!T1 && !T2)
            return 1;
        if (!T1 || !T2) // if wanna test the two trees is identical , plus "|| T1->val != T2->val"
            return 0;
        bool lf = TreeSimilar(T1->left, T2->left);
        bool rf = TreeSimilar(T1->right, T2->right);
        return lf && rf;
    }

    void tree2Infix(TreeNode<T> *root, int depth)
    {
        if (!root)
            return;
        if (!root->left && !root->right)
            s += root->val;
        else
        {
            if (depth)
                s.push_back('(');
            tree2Infix(root->left, depth + 1);
            s += root->val;
            tree2Infix(root->right, depth + 1);
            if (depth)
                s.push_back(')');
        }
    }
    double op(double a, double b, char oper) { return 1.0; }
    double treeExp_val(TreeNode<T> *root)
    {
        if (!root)
            return 0;
        if (root->left && root->right)
        {
            double a = treeExp_val(root->left), b = treeExp_val(root->right);
            return op(a, b, root->val);
        }
        return root->val;
    }

    bool isCMPtree(TreeNode<T> *root)
    {
        queue<TreeNode<T> *> q;
        q.push(root);
        TreeNode<T> *v;
        while (q.size())
        {
            v = q.front(), q.pop();
            if (v)
                q.push(v->left), q.push(v->right);
            else
                while (q.size())
                {
                    v = q.front(), q.pop();
                    if (v)
                        return false;
                }
        }
        return true;
    }

    TreeNode<T> *Construct(int leftOfpre, int rightOfpre, int leftOfpost, int rightOfpost)
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
            root->left = Construct(leftOfpre + 1, leftOfpre + sub_cnt + 1, leftOfpost, i);
            root->right = Construct(leftOfpre + sub_cnt + 2, rightOfpre, i + 1, rightOfpost - 1);
        }
        else
        {
            root->left = Construct(leftOfpre + 1, rightOfpre, leftOfpost, rightOfpost - 1);
            // only one child, default choose left
            isunique = 0;
        }
        return root;
    }

    vector<int> inTrav(TreeNode<T> *root)
    {
        vector<int> resSeq;
        stack<TreeNode<T> *> s;
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
        return resSeq;
    }
    vector<int> preTrav(TreeNode<T> *root)
    {
        vector<int> resSeq;
        if (!root)
            return resSeq;
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
        return resSeq;
    }
    vector<int> postTrav(TreeNode<T> *root)
    {
        vector<int> resSeq;
        if (!root)
            return resSeq;
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
        return resSeq;
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
class Huffman : Bin_Tree<T>
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
        this->ROOT = root;
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
class BST : Bin_Tree<T>
{
public:
    TreeNode<T> *delete_node(TreeNode<T> *&root, int x)
    {
        if (!root)
            return nullptr;
        if (x < root->val)
            root->left = delete_node(root->left, x);
        else if (root->val < x)
            root->right = delete_node(root->right, x);
        else
        {
            TreeNode<T> *tmp;
            if (root->left && root->right)
            {
                tmp = getMin(root->right);
                root->val = tmp->val;
                root->right = delete_node(root->right, tmp->val);
            }
            else
            {
                tmp = root;
                root = root->left ? root->left : root->right;
                free(tmp);
            }
        }
        return root;
    }
};

template <typename T>
class AVLTree : Bin_Tree<T>
{
    inline void LL(TreeNode<T> *&root)
    {
        TreeNode<T> *tmp = root->left;
        root->left = tmp->right;
        tmp->right = root;
        updateHeight(root);
        updateHeight(tmp);
        root = tmp;
    }
    inline void RR(TreeNode<T> *&root)
    {
        TreeNode<T> *tmp = root->right;
        root->right = tmp->left;
        tmp->left = root;
        updateHeight(root);
        updateHeight(tmp);
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

    void insert_node(TreeNode<T> *&root, int val)
    {
        if (!root)
        {
            root = new TreeNode<T>(val);
            return;
        }
        else if (val < root->val)
        {
            insert_node(root->left, val);
            updateHeight(root);
            if (getFactor(root) == 2)
                getFactor(root->left) == 1 ? LL(root) : LR(root);
        }
        else if (val > root->val)
        {
            insert_node(root->right, val);
            updateHeight(root);
            if (getFactor(root) == -2)
                getFactor(root->right) == -1 ? RR(root) : RL(root);
        }
    }

    TreeNode<T> *delete_node(TreeNode<T> *&root, int val)
    {
        if (!root)
            return nullptr;
        else if (root->val > val)
        {
            root->left = delete_node(root->left, val);
            updateHeight(root);
            if (getFactor(root) == -2)
            {
                if (getFactor(root->right) == -1)
                    RR(root);
                else
                {
                    LL(root->right);
                    RR(root);
                }
            }
        }
        else if (root->val < val)
        {
            root->right = delete_node(root->right, val);
            updateHeight(root);
            if (getFactor(root) == 2)
            {
                if (getFactor(root->left) == 1)
                    LL(root);
                else
                {
                    RR(root->left);
                    LL(root);
                }
            }
        }
        else // find it
        {
            if (root->right && root->left)
            {
                if (getFactor(root) > 0)
                {
                    TreeNode<T> *tmp = getMax(root->left);
                    root->val = tmp->val;
                    root->left = delete_node(root->left, tmp->val);
                }
                else
                {
                    TreeNode<T> *tmp = getMin(root->right);
                    root->val = tmp->val;
                    root->right = delete_node(root->right, tmp->val);
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

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    srand(time(NULL));
    int b[SIZE];
    generate(b, b + SIZE, [&]() { return rand() % 50; });
    vector<int> a(b, b + SIZE);
    Huffman<int> tr;
    tr.createHuffman(a);

    return 0;
}
