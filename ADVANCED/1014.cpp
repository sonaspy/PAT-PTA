// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>
#define test() freopen("in", "r", stdin)
using namespace std;
#define INF 1 << 30
int n, m, k, q, serveT[1001], finish[1001], cur_time = 8 * 60, id;
queue<pair<int, int>> Q[20];
queue<int> beyondLine;
void Enline(int t)
{
    while (beyondLine.size())
    {
        int k = -1, min_size = m, tmp;
        for (int i = 0; i < n; i++)
        {
            if (Q[i].size() < min_size)
            {
                min_size = Q[i].size();
                k = i;
            }
        }
        if (k == -1)
            return;
        Q[k].push(make_pair(beyondLine.front(), serveT[beyondLine.front()])), beyondLine.pop();
    }
    if (beyondLine.empty())
        for (int i = 0; i < n; i++)
        {
            cur_time = t;
            while (Q[i].size())
            {
                cur_time += Q[i].front().second;
                finish[Q[i].front().first] = cur_time;
                Q[i].pop();
            }
        }
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cin >> n >> m >> k >> q;
    for (int i = 1; i <= k; i++)
    {
        scanf("%d", &serveT[i]);
        beyondLine.push(i);
    }
    while (beyondLine.size())
    {
        int first_dq = INF, k = -1;
        for (int i = 0; i < n; i++)
        {
            if (Q[i].size() && Q[i].front().second < first_dq)
            {
                first_dq = Q[i].front().second;
                k = Q[i].front().first;
            }
        }
        if (k != -1)
        {
            cur_time += first_dq;
            for (int i = 0; i < n; i++)
            {
                if (Q[i].size())
                {
                    Q[i].front().second -= first_dq;
                    if (Q[i].front().second == 0)
                    {
                        finish[Q[i].front().first] = cur_time;
                        Q[i].pop();
                    }
                }
            }
        }
        Enline(cur_time);
    }
    for (int i = 0; i < q; i++)
    {
        cin >> id;
        finish[id] - serveT[id] >= 17 * 60 ? printf("Sorry\n") : printf("%02d:%02d\n", finish[id] / 60, finish[id] % 60);
    }
    return 0;
}