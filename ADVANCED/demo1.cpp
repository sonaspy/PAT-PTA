// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
int pre[1001], in[1001];

typedef struct Node *ptrn;
struct Node
{
    int data;
    ptrn parent, left, right;
    Node(int d) : data(d) {}
};
unordered_map<int, ptrn> mp;

ptrn solve(int root, int left, int right, ptrn p)
{
    if (left > right)
        return nullptr;
    int i = left;
    mp[pre[root]] = new Node(pre[root]);
    mp[pre[root]]->parent = p;
    while (i < right && in[i] != pre[root])
        i++;
    mp[pre[root]]->left = solve(root + 1, left, i - 1, mp[pre[root]]);
    mp[pre[root]]->right = solve(root + 1 + i - left, i + 1, right, mp[pre[root]]);
    return mp[pre[root]];
}
void func(vector<int> &vec, ptrn node)
{
    while (node != nullptr)
    {
        vec.push_back(node->data);
        node = node->parent;
    }
}

int main(int argc, char const *argv[])
{
    /* code */

    int l, i, j, a1 = 3,a2 = 6, a []={2,3,4,5}, b[] = {1,7,3,5};
    vector<int> v1(a,a+4), v2(b,b+4);
    
    for (i = v1.size() - 1, j = v2.size() - 1; i > -1 && j > -1 && v1[i] == v2[j]; i--, j--)
        ;
    cout << i << endl;
    //l = v1[i + 1];
    if (l != a1 && l != a2)
        printf("LCA of %d and %d is %d.\n", a1, a2, l);
    else if (l == a1)
        printf("%d is an ancestor of %d.\n", a1, a2);
    else
        printf("%d is an ancestor of %d.\n", a2, a1);
}