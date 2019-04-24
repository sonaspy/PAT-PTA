// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
typedef struct node *ptrn;
struct node
{
    int data;
    ptrn l = nullptr, r = nullptr;
    node(int d) : data(d) {}
};

void insert_node(int data, ptrn &root)
{
    if (!root)
    {
        root = new node(data);
        return;
    }
    else if (data <= root->data)
        insert_node(data, root->l);
    else if (data > root->data)
        insert_node(data, root->r);
    return;
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, tmp, n1 = 0, n2 = 0;
    vector<int> level_size(1, 0);
    cin >> n;
    ptrn ROOT, v;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        insert_node(tmp, ROOT);
    }
    queue<ptrn> q, next_q;
    q.push(ROOT);
    while (q.size())
    {
        while (q.size())
        {
            v = q.front(), q.pop();
            level_size.back()++;
            if (v->l)
                next_q.push(v->l);
            if (v->r)
                next_q.push(v->r);
        }
        level_size.push_back(0);
        swap(q, next_q);
    }
    level_size.pop_back();
    n1 = level_size[level_size.size() - 1], n2 = level_size[level_size.size() - 2];
    printf("%d + %d = %d", n1, n2, n1 + n2);
    return 0;
}