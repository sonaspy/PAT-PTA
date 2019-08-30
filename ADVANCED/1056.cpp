// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
vector<int> playorder, therank, weight(11111, 0), nex_p;
unordered_map<int, vector<int>> out;
int n, m, group_n, c = 0, cnt = 0;
inline int getGroup_n(int size) { return size % m == 0 ? size / m : size / m + 1; }
bool cmp(int &it1, int &it2) { return weight[it1] < weight[it2]; }
int main(int argc, char const *argv[])
{
    /* code */
    test();
    cin >> n >> m;
    playorder.resize(n), therank.resize(n);
    for (int i = 0; i < n; i++)
        cin >> weight[i];
    for (int i = 0; i < n; i++)
        cin >> playorder[i];
    while (playorder.size() > 1)
    {
        group_n = getGroup_n(playorder.size());
        for (int i = 0, s = 0; s < group_n; i += m, s++)
        {
            vector<int>::iterator it = playorder.begin() + i, iend = i + m <= playorder.size() ? it + m : playorder.end();
            auto winner = max_element(it, iend, cmp);
            for (; it != iend; it++)
            {
                if (*it != *winner)
                    out[c].push_back(*it);
            }
            nex_p.push_back(*winner);
        }
        c++;
        swap(nex_p, playorder);
        nex_p.clear();
    }
    out[c].push_back(playorder.front());
    for (; c > -1; c--)
    {
        for (auto i : out[c])
            therank[i] = cnt + 1;
        cnt += out[c].size();
    }
    for (auto i : therank)
        cout << i << " ";
    return 0;
}