// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
typedef struct node *ptrn;
struct node
{
    int data, height, id;
    ptrn left, right;
    node(int d) : data(d), height(1), id(0), left(nullptr), right(nullptr) {}
};
inline int getHeight(ptrn root) { return root == nullptr ? 0 : root->height; }
inline int getFactor(ptrn root) { return getHeight(root->left) - getHeight(root->right); }
inline void updateHeight(ptrn &root) { root->height = max(getHeight(root->left), getHeight(root->right)) + 1; }
inline void LL(ptrn &root)
{
    ptrn tmp = root->left;
    root->left = tmp->right;
    tmp->right = root;
    updateHeight(root);
    updateHeight(tmp);
    root = tmp;
}
inline void RR(ptrn &root)
{
    ptrn tmp = root->right;
    root->right = tmp->left;
    tmp->left = root;
    updateHeight(root);
    updateHeight(tmp);
    root = tmp;
}

void Insert(ptrn &root, int data)
{
    if (!root)
    {
        root = new node(data);
        return;
    }
    if (data < root->data)
    {
        Insert(root->left, data);
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
    else
    {
        Insert(root->right, data);
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
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, t, iscpt = 1;
    vector<int> st, check;
    ptrn ROOT = nullptr, v = nullptr;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        Insert(ROOT, t);
    }
    queue<ptrn> q;
    q.push(ROOT);
    while (q.size())
    {
        v = q.front(), q.pop();
        st.push_back(v->id);
        cout << v->data;
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
        cout << (q.empty() ? "\n" : " ");
    }
    check.resize(st.size()), iota(check.begin(), check.end(), 0);
    iscpt = equal(check.begin(), check.end(), st.begin());
    cout << (iscpt ? "YES" : "NO");
    return 0;
}