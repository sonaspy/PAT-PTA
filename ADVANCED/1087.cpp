// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)
#define NON_EXIST (1 << 30)
using namespace std;

int n, k, src = 0, dst, happy[201] = {0}, MAP[201][201], dist[201] = {0}, vis[201] = {0}, r_cnt = 0, f_hap = 0;
string start, s, d, res;
double f_ave = 0.0;
unordered_map<string, int> mp;
unordered_map<int, string> mp1;
vector<int> paths[201];
deque<int> tmpPath, ansPath;

inline void findPath(int walk)
{
    static int hap_val = 0;
    hap_val += happy[walk];
    tmpPath.push_front(walk);
    if (walk == src)
    {
        r_cnt++;
        if (hap_val > f_hap)
        {
            f_hap = hap_val;
            f_ave = hap_val * 1.0 / (tmpPath.size() - 1);
            ansPath = tmpPath;
        }
        return;
    }
    for (auto i : paths[walk])
    {
        findPath(i);
        tmpPath.pop_front();
        hap_val -= happy[i];
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cin >> n >> k >> start;
    mp[start] = 0;
    fill(*MAP, *MAP + 201 * 201, NON_EXIST);
    fill(dist, dist + 201, NON_EXIST);
    for (int i = 1; i < n; i++)
    {
        cin >> s >> happy[i];
        mp[s] = i;
        mp1[i] = s;
    }
    for (int i = 0; i < k; i++)
    {
        int tmp;
        cin >> s >> d >> tmp;
        MAP[mp[s]][mp[d]] = tmp;
        MAP[mp[d]][mp[s]] = tmp;
    }
    dst = mp["ROM"];
    dist[0] = 0;
    for (int i = 0; i < n; i++)
    {
        int k = -1, min_ = NON_EXIST;
        for (int j = 0; j < n; j++)
        {
            if (!vis[j] && dist[j] < min_)
            {
                k = j;
                min_ = dist[j];
            }
        }
        if (k == -1)
            break;
        vis[k] = 1;
        for (int j = 0; j < n; j++)
        {
            if (!vis[j] && MAP[k][j] != NON_EXIST)
            {
                if (dist[k] + MAP[k][j] < dist[j])
                {
                    dist[j] = dist[k] + MAP[k][j];
                    paths[j].clear();
                    paths[j].push_back(k);
                }
                else if (dist[k] + MAP[k][j] == dist[j])
                    paths[j].push_back(k);
            }
        }
    }
    findPath(dst);
    printf("%d %d %d %d\n", r_cnt, dist[dst], f_hap, int(f_ave));
    cout << start;
    ansPath.pop_front();
    for (auto i : ansPath)
        cout << "->" << mp1[i];
    return 0;
}