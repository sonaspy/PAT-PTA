// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int pre[50001], in[50001], n;
struct node
{
    int data;
    node *l = nullptr, *r = nullptr;
    node(int d) : data(d) {}
};
node *Construct(int root, int lo, int hi)
{
    if (hi < lo) return nullptr;
    int i = lo;
    while (i < hi && in[i] != pre[root]) i++;
    node *tmp = new node(pre[root]);
    tmp->l = Construct(root + 1, lo, i - 1);
    tmp->r = Construct(root + 1 + i - lo, i + 1, hi);
    return tmp;
}
void post(node *root)
{
    if (!root) return;
    post(root->l);
    post(root->r);
    cout << root->data;
    exit(0);
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cin >> n;
    for (int i = 0; i < n; i++)
        scanf("%d", pre + i);
    for (int i = 0; i < n; i++)
        scanf("%d", in + i);
    node *root = Construct(0, 0, n - 1), *res;
    post(root);
    return 0;
}