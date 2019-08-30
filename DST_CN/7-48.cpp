// author - sonaspy@outlook.com
// coding - utf_8

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <unordered_map>

#define test() freopen("in", "r", stdin)
#define MAXN 10001
using namespace std;

int N, M, c_m_num, timeline = 0, sum;
struct Node
{
    char name[5];
    int start, cost, wait_time;
} a[MAXN];

bool finished[MAXN] = {false};
vector<string> vec;
unordered_map<string, int> mp;

void solve(int index, int circle_id)
{
    for (int i = index + 1; i < N; i++)
        {
            if (!finished[i] && mp[a[i].name] == circle_id && a[i].start <= timeline)
                {
                    finished[i] = true;
                    a[i].wait_time = timeline - a[i].start;
                    timeline += a[i].cost;
                    vec.push_back(a[i].name);
                }
        }
}

int main(int argc, char const *argv[])
{
    /* code */
    // test();
    char name[4];
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= M; i++)
        {
            scanf("%d", &c_m_num);
            for (int j = 0; j < c_m_num; j++)
                {
                    scanf("%s", name);
                    mp[name] = i;
                }
        }
    int cnt = M + 1;
    for (int i = 0; i < N; i++)
        {
            scanf("%s", a[i].name);
            if (!mp[a[i].name])
                mp[a[i].name] = cnt++;
            scanf("%d%d", &a[i].start, &a[i].cost);
            a[i].cost = a[i].cost > 60 ? 60 : a[i].cost;
        }
    for (int i = 0; i < N; i++)
        {
            if (!finished[i])
                {
                    finished[i] = true;
                    if (a[i].start > timeline)
                        timeline = a[i].start;
                    a[i].wait_time = timeline - a[i].start;
                    timeline += a[i].cost;
                    vec.push_back(a[i].name);
                    solve(i, mp[a[i].name]);
                }
        }
    for (auto iter : vec)
        cout << iter << endl;
    for (int i = 0; i < N; i++)
        sum += a[i].wait_time;
    printf("%.1f\n", 1.0 * sum / N);
    return 0;
}