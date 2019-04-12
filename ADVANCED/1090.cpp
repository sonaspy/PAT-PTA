// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
typedef struct Node *ptrNode;
struct Node
{
    double my_p;
    vector<int> sub;
};
vector<ptrNode> container;
int n, parent, root, ans_num = 0;
double ori_p, inc_p, max_price = 0;
void BFS()
{
    int walk;
    double tmp_price;
    deque<int> dq;
    dq.push_back(root);
    while (dq.size())
    {
        walk = dq.front();
        dq.pop_front();
        tmp_price = container[walk]->my_p;
        if (tmp_price > max_price)
        {
            max_price = tmp_price;
        }
        for (auto i : container[walk]->sub)
        {
            container[i]->my_p = tmp_price * ((100 + inc_p) * 1.0 / 100);
            dq.push_back(i);
        }
    }
    for (int i = 0; i < n; i++)
        if (container[i]->my_p - max_price == 0)
            ans_num++;
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cin >> n >> ori_p >> inc_p;
    for (int i = 0; i < n; i++)
        container.push_back(new Node());
    for (int i = 0; i < n; i++)
    {
        cin >> parent;
        if (parent == -1)
        {
            root = i;
            container[root]->my_p = ori_p;
        }
        else
        {
            container[parent]->sub.push_back(i);
        }
    }
    BFS();
    printf("%.2f %d", max_price, ans_num);
    return 0;
}