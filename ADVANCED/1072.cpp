// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int n, m, k, ds, d, a1, a2, mp[1025][1025], vis[1025];
string s1, s2;
struct Node
{
    int id;
    double av_s = 0.0, sum_s = 0.0, min_ = 99999999999.9;
    bool operator<(const Node &b) const { return min_ != b.min_ ? min_ > b.min_ : av_s != b.av_s ? av_s < b.av_s : id < b.id; }
};
inline int convert(string &s) { return s[0] != 'G' ? stoi(s) : stoi(s.substr(1, s.size() - 1)) + n; }
vector<Node> v;
inline void Dij(int id)
{
    fill(vis, vis + 1025, 0);
    vector<int> dis(mp[id], mp[id] + n + m + 1);
    dis[id] = 0;
    for (int i = 1; i <= n + m; i++)
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
    bool valid = true;
    Node tmp;
    tmp.id = id - n;
    for (int j = 1; j <= n; j++)
    {
        tmp.sum_s += dis[j];
        if (dis[j] > ds)
        {
            valid = false;
            break;
        }
        tmp.min_ = dis[j] < tmp.min_ ? dis[j] : tmp.min_;
    }
    if (!valid)
        return;
    tmp.av_s = tmp.sum_s * 1.0 / n;
    v.push_back(tmp);
}
void output()
{
    if (v.empty())
        printf("No Solution\n");
    else
    {
        sort(v.begin(), v.end());
        printf("G%d\n", v.front().id);
        cout << setiosflags(ios::fixed) << setprecision(1)<<  v.front().min_ << " " << v.front().av_s;
    }
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
    output();
    return 0;
} //attention