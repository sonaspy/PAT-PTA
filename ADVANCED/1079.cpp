// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
struct Node
{
    int amount = 0;
    vector<int> sub;
    double price;
} nodes[100001];
int n, tmp, t_amount, _sub;
double uniprice, p_incr, sum_price = 0;
inline void bfs()
{
    queue<int> deq;
    deq.push(0);
    while (deq.size())
    {
        int tf = deq.front();
        deq.pop();
        //cout << tf  << "(" <<  nodes[tf].price << ")" << ": ";
        for (auto i : nodes[tf].sub)
        {
            //cout << i << " ";
            nodes[i].price = nodes[tf].price * (1 + p_incr / 100);
            deq.push(i);
        }
        if (nodes[tf].sub.empty())
            sum_price += nodes[tf].amount * nodes[tf].price;
        //cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cin >> n >> uniprice >> p_incr;
    nodes[0].price = uniprice;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        if (!tmp)
        {
            scanf("%d", &t_amount);
            nodes[i].amount = t_amount;
        }
        else
            for (int j = 0; j < tmp; j++)
            {
                scanf("%d", &_sub);
                nodes[i].sub.push_back(_sub);
            }
    }
    bfs();
    cout.setf(ios::fixed);
    cout << setprecision(1) << sum_price;

    return 0;
}