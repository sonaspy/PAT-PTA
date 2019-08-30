// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int n, m, k, ds, d, a1, a2, mp[1025][1025], vis[1025];
string s1, s2;
struct theNode
{
    int id;
    double average = 0.0, sum_s = 0.0, themin = 99999999999.9;
    bool operator<(const theNode &b) const { return themin != b.themin ? themin > b.themin : average != b.average ? average < b.average : id < b.id; }
};
inline int convert(string &s) { return s[0] != 'G' ? stoi(s) : stoi(s.substr(1, s.size() - 1)) + n; }
vector<theNode> res;
inline void Dij(int id)
{
    fill(vis, vis + 1025, 0);
    vector<int> dis(mp[id], mp[id] + n + m + 1);
    dis[id] = 0;
    while (true)
    {
        int min = 1 << 30, k = -1;
        for (int j = 1; j <= n + m; j++)
        {
            if (!vis[j] && dis[j] < min)
            {
                min = dis[j];
                k = j;
            }
        }
        if (k == -1)
            break;
        vis[k] = 1;
        for (int j = 1; j <= n + m; j++)
            if (!vis[j] && dis[j] > dis[k] + mp[k][j])
                dis[j] = dis[k] + mp[k][j];
    }
    theNode canidate;
    canidate.id = id - n;
    for (int j = 1; j <= n; j++)
    {
        canidate.sum_s += dis[j];
        if (dis[j] > ds)
            return;
        canidate.themin = min(double(dis[j]), canidate.themin);
    }
    canidate.average = canidate.sum_s * 1.0 / n;
    if (res.empty())
        res.push_back(canidate);
    else if (canidate < res[0])
        res[0] = canidate;
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    fill(*mp, *mp + 1025 * 1025, 1 << 30);
    cin >> n >> m >> k >> ds;
    for (int i = 0; i < k; i++)
    {
        cin >> s1 >> s2 >> d;
        a1 = convert(s1), a2 = convert(s2);
        mp[a1][a2] = mp[a2][a1] = d;
    }
    for (int i = n + 1; i <= n + m; i++)
        Dij(i);
    if (res.empty())
        printf("No Solution\n");
    else
    {
        printf("G%d\n", res.front().id);
        cout << setiosflags(ios::fixed) << setprecision(1) << res.front().themin << " " << res.front().average;
    }
    return 0;
}