// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
typedef struct Node *ptrn;
struct Node
{
    int id, left = -1, right = -1, data;
    Node(int id) : id(id) {}
};
vector<ptrn> container(1111);
int c = 0, arr[1111];
inline void Inorder(int root)
{
    if (root == -1)
        return;
    Inorder(container[root]->left);
    container[root]->data = arr[c++];
    Inorder(container[root]->right);
}
inline void levelorder()
{
    c = 0;
    queue<int> q, next_q;
    int v;
    q.push(0);
    while (q.size())
    {
        v = q.front();
        q.pop();
        arr[c++] = container[v]->data;
        if (container[v]->left != -1)
            q.push(container[v]->left);
        if (container[v]->right != -1)
            q.push(container[v]->right);
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        container[i] = new Node(i);
        if (2 * i + 1 < n)
            container[i]->left = 2 * i + 1;
        if (2 * i + 2 < n)
            container[i]->right = 2 * i + 2;
        scanf("%d", arr + i);
    }
    sort(arr, arr + n);
    Inorder(0);
    levelorder();
    printf("%d", arr[0]);
    for (int i = 1; i < n; i++)
        printf(" %d", arr[i]);
    return 0;
}