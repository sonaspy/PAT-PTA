#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define N 1005
#define inf 0x3f3f3f
vector<int> q[N];
map<string, int> rt;
set<string> rq;
int res[N][N];
vector<string> rs;
int n;
int dist[N];
bool bfs(int s, int e)
{
    memset(dist, 0, sizeof(dist));
    queue<int> Q;
    Q.push(s);
    dist[s] = 1;
    while (!Q.empty())
        {
            int cmt = Q.front();
            //	cout << cmt << endl;
            Q.pop();
            for (int i = 0; i < q[cmt].size(); i++)
                {
                    if (!dist[q[cmt][i]] && res[cmt][q[cmt][i]])
                        {
                            dist[q[cmt][i]] = dist[cmt] + 1;
                            Q.push(q[cmt][i]);
                        }
                }
        }
    return dist[e];
}
int dini(int s, int e, int sum)
{
    if (s == e)
        return sum;
    for (int i = 0; i < q[s].size(); i++)
        {
            if (dist[q[s][i]] == dist[s] + 1 && res[s][q[s][i]])
                {
                    int fd = dini(q[s][i], e, min(sum, res[s][q[s][i]]));
                    if (fd)
                        {
                            res[s][q[s][i]] -= fd;
                            res[q[s][i]][s] += fd;
                            return fd;
                        }
                }
        }
    return 0;
}
int main()
{
    int sum = 0;
    memset(res, 0, sizeof(res));
    int cnt = 0, wt;
    string str1, str2, s1, s2;
    cin >> s1 >> s2 >> n;
    for (int i = 0; i < n; i++)
        {
            cin >> str1 >> str2 >> wt;
            if (!rq.count(str1))
                {
                    rs.push_back(str1);
                    rt[str1] = rs.size() - 1;
                    rq.insert(str1);
                }
            if (!rq.count(str2))
                {
                    rs.push_back(str2);
                    rt[str2] = rs.size() - 1;
                    rq.insert(str2);
                }
            if (!res[rt[str1]][rt[str2]] && !res[rt[str2]][rt[str1]])
                {
                    q[rt[str1]].push_back(rt[str2]);
                    q[rt[str2]].push_back(rt[str1]);
                }
            res[rt[str1]][rt[str2]] = wt;
        }
    while (bfs(rt[s1], rt[s2]))
        sum += dini(rt[s1], rt[s2], inf);
    cout << sum << endl;
    return 0;
}
