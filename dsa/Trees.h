using namespace std;
vector<int> arr(1000, -1);
inline int find_root(int id)
{
    return arr[id] == -1 ? id : arr[id] = find_root(arr[id]);
}
inline void Union__(int a, int b)
{
    int ra = find_root(a), rb = find_root(b);
    if (ra != rb)
        arr[rb] = ra;
}
struct TreeNode
{
    int val;
    TreeNode *left, *right, *parent;
    int height = 1, depth = 1;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
inline int GetHeight(TreeNode *root) { return root == nullptr ? 0 : root->height; }
inline void updateHeight(TreeNode *root) { root->height = max(GetHeight(root->left), GetHeight(root->right)) + 1; }
inline int getFactor(TreeNode *root) { return GetHeight(root->left) - GetHeight(root->right); }
inline TreeNode *getMax(TreeNode *root)
{
    while (root->right)
        root = root->right;
    return root;
}
inline TreeNode *getMin(TreeNode *root)
{
    while (root->left)
        root = root->left;
    return root;
}
class Tree
{
public:
    Tree()
    {
        preorder.resize(10);
        iota(preorder.begin(), preorder.end(), 1);
        inorder.insert(inorder.begin(), preorder.begin(), preorder.end());
        int c = 450000;
        while (next_permutation(inorder.begin(), inorder.end()) && c--)
            ;

        for (auto i : preorder)
            cout << i << " ";
        cout << endl;
        for (auto i : inorder)
            cout << i << " ";
        cout << endl;
    }

    string s;
    vector<int> preorder, inorder, postorder;
    bool isunique;
    TreeNode *__build1(int root, int lo, int hi)
    {
        if (hi < lo)
            return nullptr;
        int i = lo;
        TreeNode *node = new TreeNode(preorder[root]);
        while (i < hi && inorder[i] != preorder[root])
            i++;
        node->left = __build1(root + 1, lo, i - 1);
        node->right = __build1(root + 1 + i - lo, i + 1, hi);
        return node;
    }
    TreeNode *__build2(int root, int lo, int hi)
    {
        if (hi < lo)
            return nullptr;
        int i = lo;
        TreeNode *node = new TreeNode(postorder[root]);
        while (i < hi && inorder[i] != postorder[root])
            i++;
        node->left = __build2(root - 1 + i - hi, lo, i - 1);
        node->right = __build2(root - 1, i + 1, hi);
        return node;
    }
    TreeNode *invert(TreeNode *root)
    {
        if (!root)
            return nullptr;
        TreeNode *tmp = invert(root->right);
        root->right = invert(root->left);
        root->left = tmp;
        return root;
    }
    void deleteleave(TreeNode *root, TreeNode *preorder)
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
    void del_x_sub(TreeNode *root, int target)
    {
        queue<TreeNode *> q;
        TreeNode *x;
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
    void del(TreeNode *root)
    {
        if (!root)
            return;
        del(root->left);
        del(root->right);
        delete root;
    }
    bool TreeSimilar(TreeNode *T1, TreeNode *T2)
    {
        if (!T1 && !T2)
            return 1;
        if (!T1 || !T2) // if wanna test the two trees is identical , plus "|| T1->val != T2->val"
            return 0;
        bool lf = TreeSimilar(T1->left, T2->left);
        bool rf = TreeSimilar(T1->right, T2->right);
        return lf && rf;
    }
    void Tree2Exp(TreeNode *root, int depth)
    {
        if (!root)
            return;
        if (!root->left && !root->right)
            s += root->val;
        else
        {
            if (depth)
                s.push_back('(');
            Tree2Exp(root->left, depth + 1);
            s += root->val;
            Tree2Exp(root->right, depth + 1);
            if (depth)
                s.push_back(')');
        }
    }

    bool isCMPtree(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *v;
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

    TreeNode *Construct(int leftOfpre, int rightOfpre, int leftOfpost, int rightOfpost)
    {
        if (leftOfpre > rightOfpre || leftOfpost > rightOfpost)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[leftOfpre]);
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

    vector<int> preOrderTraversal(TreeNode *root)
    {
        vector<int> resSeq;
        stack<TreeNode *> s;
        TreeNode *p = root;
        while (s.size() || p)
        {
            while (p)
            {
                resSeq.push_back(p->val);
                s.push(p);
                p = p->left;
            }
            if (s.size())
            {
                p = s.top();
                s.pop();
                p = p->right;
            }
        }
        return resSeq;
    }
    vector<int> inTrav(TreeNode *root)
    {
        vector<int> resSeq;
        stack<TreeNode *> s;
        TreeNode *p = root;
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
    vector<int> preTrav(TreeNode *root)
    {
        vector<int> resSeq;
        if (!root)
            return resSeq;
        stack<TreeNode *> s;
        s.push(root);
        while (s.size())
        {
            root = s.top();
            s.pop();
            resSeq.push_back(root->val);
            if (root->right)
                s.push(root->right);
            if (root->left)
                s.push(root->left);
        }
        return resSeq;
    }
    vector<int> postTrav(TreeNode *root)
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

    TreeNode *get_LCA(TreeNode *p, TreeNode *q)
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
    int Isomprphic(TreeNode *root1, TreeNode *root2)
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

    //BST:
    TreeNode *deleteNode(TreeNode *&root, int x)
    {
        if (!root)
            return nullptr;
        if (x < root->val)
            root->left = deleteNode(root->left, x);
        else if (root->val < x)
            root->right = deleteNode(root->right, x);
        else
        {
            TreeNode *tmp;
            if (root->left && root->right)
            {
                tmp = getMin(root->right);
                root->val = tmp->val;
                root->right = deleteNode(root->right, tmp->val);
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

// 后缀表达式 -> exp_tree
// stack : node*; 遇 oprand: create node then push, 遇operator: pop 2 item become its childs, then push.

class AVLTree
{
    inline void LL(TreeNode *&root)
    {
        TreeNode *tmp = root->left;
        root->left = tmp->right;
        tmp->right = root;
        updateHeight(root);
        updateHeight(tmp);
        root = tmp;
    }
    inline void RR(TreeNode *&root)
    {
        TreeNode *tmp = root->right;
        root->right = tmp->left;
        tmp->left = root;
        updateHeight(root);
        updateHeight(tmp);
        root = tmp;
    }
    inline void LR(TreeNode *&root)
    {
        RR(root->left);
        LL(root);
    }
    inline void RL(TreeNode *&root)
    {
        LL(root->right);
        RR(root);
    }

    void Insert(TreeNode *&root, int val)
    {
        if (!root)
        {
            root = new TreeNode(val);
            return;
        }
        else if (val < root->val)
        {
            Insert(root->left, val);
            updateHeight(root);
            if (getFactor(root) == 2)
                getFactor(root->left) == 1 ? LL(root) : LR(root);
        }
        else if (val > root->val)
        {
            Insert(root->right, val);
            updateHeight(root);
            if (getFactor(root) == -2)
                getFactor(root->right) == -1 ? RR(root) : RL(root);
        }
    }

    TreeNode *Delete(TreeNode *&root, int val)
    {
        if (!root)
            return nullptr;
        else if (root->val > val)
        {
            root->left = Delete(root->left, val);
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
            root->right = Delete(root->right, val);
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
                    TreeNode *tmp = getMax(root->left);
                    root->val = tmp->val;
                    root->left = Delete(root->left, tmp->val);
                }
                else
                {
                    TreeNode *tmp = getMin(root->right);
                    root->val = tmp->val;
                    root->right = Delete(root->right, tmp->val);
                }
            }
            else
            {
                TreeNode *tmp = root;
                root = (root->left == nullptr ? root->right : root->left);
                delete tmp;
            }
        }
        return root;
    }
};

class Heap
{
    // data[1....n] data[0] = INT_MAX
public:
    vector<int> data;
    int size;
    Heap()
    {
        data.push_back(INT_MAX);
        data.resize(101);
        generate(data.begin() + 1, data.end(), []() { return rand() % 100; });
        size = data.size() - 1;
    }
    void push(int val)
    {
        data.push_back(val);
        size = data.size() - 1;
        int i = size;
        for (; data[i / 2] < val; i /= 2)
            data[i] = data[i / 2];
        data[i] = val;
    }
    void percDown(int pos)
    {
        int val = data[pos], up = pos, down = 2 * pos;
        for (; down <= size; up = down, down *= 2)
        {
            if (down < size && data[down] < data[down + 1])
                ++down;
            if (data[down] > val)
                data[up] = data[down];
            else
                break;
        }
        data[up] = val;
    }
    void pop()
    {
        if (size == 1)
            return;
        data[1] = data.back();
        data.pop_back();
        size = data.size() - 1;
        percDown(1);
    }
    void buildHeap()
    {
        int i;
        for (i = size / 2; i; --i)
            percDown(i);
    }
};