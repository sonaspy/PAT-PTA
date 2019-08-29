// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
struct treenode
{
    int val, depth;
    treenode *l, *r, *p;
    treenode(int x, treenode *p) : val(x), depth(0), l(nullptr), r(nullptr), p(p) {}
};
inline int getdepth(treenode *root) { return root == nullptr ? 0 : root->depth; }
vector<int> post(100), in(100);
unordered_map<int, treenode *> table;
treenode *root, *v;
bool isfull = true;
treenode *build(int root, int lo, int hi, treenode *p)
{
    if (hi < lo)
        return nullptr;
    int i = lo;
    treenode *node = new treenode(post[root], p);
    table[node->val] = node;
    node->depth = getdepth(p) + 1;
    while (i < hi && in[i] != post[root])
        i++;
    node->l = build(root - 1 + i - hi, lo, i - 1, node);
    node->r = build(root - 1, i + 1, hi, node);
    return node;
}
inline bool judge(string &s)
{
    stringstream bfstream(s);
    string buffer;
    int obj1, obj2;
    if (s.back() == 't')
    {
        bfstream >> obj1;
        return root->val == obj1;
    }
    else if (s.back() == 'l')
    {
        bfstream >> obj1 >> buffer >> obj2;
        return table[obj1]->depth == table[obj2]->depth;
    }
    else if (s.back() == 's')
    {
        bfstream >> obj1 >> buffer >> obj2;
        return table[obj1]->p == table[obj2]->p;
    }
    else if (s.back() == 'e')
        return isfull;
    else
    {
        bfstream >> obj1 >> buffer >> buffer >> buffer;
        if (buffer[0] == 'p')
        {
            bfstream >> buffer >> obj2;
            if (!table[obj2]->p)
                return false;
            return table[obj2]->p->val == obj1;
        }
        if (buffer[0] == 'l')
        {
            bfstream >> buffer >> buffer >> obj2;
            return table[obj2]->l == nullptr ? false : table[obj2]->l->val == obj1;
        }
        bfstream >> buffer >> buffer >> obj2;
        return table[obj2]->r == nullptr ? false : table[obj2]->r->val == obj1;
    }
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
    queue<treenode *> q;
    q.push(root);
    while (q.size())
    {
        v = q.front(), q.pop();
        if ((!v->l && v->r) || (!v->r && v->l))
        {
            isfull = 0;
            break;
        }
        if (v->l)
            q.push(v->l);
        if (v->r)
            q.push(v->r);
    }
    for (int i = 0; i < m; i++)
    {
        getline(cin, s);
        cout << (judge(s) ? "Yes\n" : "No\n");
    }
    return 0;
}