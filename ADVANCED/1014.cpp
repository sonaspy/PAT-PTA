// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <algorithm>
#include <queue>
#define test() freopen("in", "r", stdin)

using namespace std;
#define INF 99999999
int n, m, k, q, T[1001], finish[1001], nowTime = 8 * 60;
queue<pair<int, int>> Q[20];
queue<int> waiting;

void solve(int value)
{
    while (waiting.size())
        {
            int k = -1, min = m, tmp;
            for (int i = 0; i < n; i++)
                {
                    if (Q[i].size() < min)
                        {
                            min = Q[i].size();
                            k = i;
                        }
                }
            if (k == -1)
                return;
            Q[k].push(make_pair(waiting.front(), T[waiting.front()])), waiting.pop();
        }
    if (waiting.empty())
        {
            for (int i = 0; i < n; i++)
                {
                    nowTime = value;
                    while (Q[i].size())
                        {
                            nowTime += Q[i].front().second;
                            finish[Q[i].front().first] = nowTime;
                            Q[i].pop();
                        }
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
            scanf("%d", &T[i]);
            waiting.push(i);
        }
    while (waiting.size())
        {
            int mint = INF, k = -1;
            for (int i = 0; i < n; i++)
                {
                    if (Q[i].size() && Q[i].front().second < mint)
                        {
                            mint = Q[i].front().second;
                            k = Q[i].front().first;
                        }
                }
            if (k > -1)
                {
                    nowTime += mint;
                    for (int i = 0; i < n; i++)
                        {
                            if (Q[i].size())
                                {
                                    Q[i].front().second -= mint;
                                    if (Q[i].front().second == 0)
                                        {
                                            finish[Q[i].front().first] = nowTime;
                                            Q[i].pop();
                                        }
                                }
                        }
                }
            solve(nowTime);
        }
    for (int i = 0; i < q; i++)
        {
            int id;
            cin >> id;
            if (finish[id] - T[id] >= 17 * 60)
                printf("Sorry\n");
            else
                printf("%02d:%02d\n", finish[id] / 60, finish[id] % 60);
        }
    return 0;
}