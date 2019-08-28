// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
struct node
{
    string data;
    node *l, *r;
    node() : data("@"), l(nullptr), r(nullptr) {}
};
string s;
vector<node *> a(1000);
void inorder(node *root, int depth)
{
    if (!root)
        return;
    if (!root->l && !root->r)
        s += root->data;
    else
    {
        if (depth) s.push_back('(');
        inorder(root->l, depth + 1);
        s += root->data;
        inorder(root->r, depth + 1);
        if (depth) s.push_back(')');
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int f[1000] = {0}, n, root = 1, l, r;
    cin >> n;
    generate(a.begin(), a.end(), []() { return new node(); });
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i]->data >> l >> r;
        if (l != -1)
        {
            a[i]->l = a[l];
            f[l] = 1;
        }
        if (r != -1)
        {
            a[i]->r = a[r];
            f[r] = 1;
        }
    }
    while (f[root]) root++;
    inorder(a[root], 0);
    cout << s;
    return 0;
}