// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
typedef struct Node *ptrn;
struct Node
{
    int id, left, right, data;
    Node(int id, int l, int r) : id(id), left(l), right(r) {}
};
vector<ptrn> container(111);
int c = 0, arr[111];
inline void Inorder(int root)
{
    if (container[root]->left != -1)
        Inorder(container[root]->left);
    container[root]->data = arr[c++];
    if (container[root]->right != -1)
        Inorder(container[root]->right);
}

inline void levelorder()
{
    c = 0;
    queue<int> q, next_q;
    int no;
    q.push(0);
    while (q.size())
    {
        while (q.size())
        {
            no = q.front();
            q.pop();
            arr[c++] = container[no]->data;
            if (container[no]->left != -1)
                next_q.push(container[no]->left);
            if (container[no]->right != -1)
                next_q.push(container[no]->right);
        }
        swap(q, next_q);
    }
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
        container[i] = new Node(i, l, r);
    }
    for (int i = 0; i < n; i++)
        scanf("%d", arr + i);
    sort(arr, arr + n);
    Inorder(0);
    levelorder();
    printf("%d", arr[0]);
    for (int i = 1; i < n; i++)
        printf(" %d", arr[i]);
    return 0;
}