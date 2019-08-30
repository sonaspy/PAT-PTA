// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)
#define ROOT 1
using namespace std;
vector<int> Tree[101];
int n, m, num, a, b, max_num = 0, level = 0, ans_l;

inline void BFS()
{
    queue<int> Q, next_Q;
    Q.push(ROOT);
    while (Q.size())
    {
        level++;
        while (Q.size())
        {
            int node = Q.front();
            Q.pop();
            for (auto sub : Tree[node])
                next_Q.push(sub);
        }
        if (next_Q.size() > max_num)
        {
            max_num = next_Q.size();
            ans_l = level + 1;
        }
        swap(Q, next_Q);
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cin >> n >> m;
    if (n == 1)
        cout << 1 << " " << 1;
    else
    {

        for (int i = 0; i < m; i++)
        {
            scanf("%d%d", &a, &num);
            for (int j = 0; j < num; j++)
            {
                scanf("%d", &b);
                Tree[a].push_back(b);
            }
        }
        BFS();
        cout << max_num << " " << ans_l;
    }
    return 0;
}