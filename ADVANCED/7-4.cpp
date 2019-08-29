// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
struct treenode
{
    int val, depth;
    treenode *l, *r, *p;
    treenode(int x, treenode *pre) : val(x), depth(0), l(nullptr), r(nullptr), p(pre) {}
};
inline int getdepth(treenode *root) { return root == nullptr ? 0 : root->depth; }
vector<int> post(100), in(100);
unordered_map<int, treenode *> mp;
treenode *root;
bool isfull = true;
treenode *build(int root, int lo, int hi, treenode *pre)
{
    if (hi < lo)
        return nullptr;
    int i = lo;
    treenode *node = new treenode(post[root], pre);
    mp[node->val] = node;
    node->depth = getdepth(pre) + 1;
    while (i < hi && in[i] != post[root])
        i++;
    node->l = build(root - 1 + i - hi, lo, i - 1, node);
    node->r = build(root - 1, i + 1, hi, node);
    return node;
}
void isFull(treenode *root)
{
    queue<treenode *> q;
    treenode *v;
    q.push(root);
    while (q.size())
    {
        v = q.front(), q.pop();
        if ((!v->l && v->r) || (!v->r && v->l))
            isfull = 0;
        if (v->l)
            q.push(v->l);
        if (v->r)
            q.push(v->r);
    }
}

bool judge(string &s)
{
    stringstream ss(s);
    string tmp;
    int a1, a2, a3;
    if (s.back() == 't')
    {
        ss >> a1;
        return root->val == a1;
    }
    else if (s.back() == 'l')
    {
        ss >> a1 >> tmp >> a2;
        return mp[a1]->depth == mp[a2]->depth;
    }
    else if (s.back() == 's')
    {
        ss >> a1 >> tmp >> a2;
        return mp[a1]->p == mp[a2]->p;
    }
    else if (s.back() == 'e')
        return isfull;
    else
    {
        ss >> a1 >> tmp >> tmp >> tmp;
        if (tmp[0] == 'p')
        {
            ss >> tmp >> a2;
            if (!mp[a2]->p) return false;
            return mp[a2]->p->val == a1;
        }
        if (tmp[0] == 'l')
        {
            ss >> tmp >> tmp >> a2;
            return mp[a2]->l == nullptr ? false : mp[a2]->l->val == a1;
        }
        else
        {
            ss >> tmp >> tmp >> a2;
            return mp[a2]->r == nullptr ? false : mp[a2]->r->val == a1;
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, m;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++)
        cin >> post[i];
    for (int i = 0; i < n; i++)
        cin >> in[i];
    root = build(n - 1, 0, n - 1, nullptr);
    cin >> m, getchar();
    isFull(root);
    for (int i = 0; i < m; i++)
    {
        getline(cin, s);
        cout << (judge(s) ? "Yes\n" : "No\n");
    }
    return 0;
}