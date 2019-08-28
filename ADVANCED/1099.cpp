// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
typedef struct TreeNode *ptrn;
struct TreeNode
{
    int id, left, right, data;
    TreeNode(int id, int l, int r) : id(id), left(l), right(r) {}
};
vector<ptrn> trees(111);
int c = 0, arr[111];
inline void inorder(int root)
{
    if (root == -1)
        return;
    inorder(trees[root]->left);
    trees[root]->data = arr[c++];
    inorder(trees[root]->right);
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, l, r;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &l, &r);
        trees[i] = new TreeNode(i, l, r);
    }
    for (int i = 0; i < n; i++)
        scanf("%d", arr + i);
    sort(arr, arr + n);
    inorder(0);
    c = 0;
    queue<int> q;
    int v;
    q.push(0);
    while (q.size())
    {
        v = q.front();
        q.pop();
        arr[c++] = trees[v]->data;
        if (trees[v]->left != -1)
            q.push(trees[v]->left);
        if (trees[v]->right != -1)
            q.push(trees[v]->right);
    }
    printf("%d", arr[0]);
    for (int i = 1; i < n; i++)
        printf(" %d", arr[i]);
    return 0;
}