// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <queue>
#include <numeric>

#define test() freopen("in", "r", stdin)

using namespace std;

int n, m, tmp;
int remain = n;
struct Mouse
{
    int w, id, out_o, rank;
    Mouse(int w, int i) : w(w), id(i) {}
};
bool cmp1(const Mouse *a, const Mouse *b) { return a->out_o > b->out_o; }
bool cmp(const Mouse *a, const Mouse *b) { return a->w < b->w; }
vector<Mouse *> mice, group, tmpwin;
queue<Mouse *> Q;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cin >> n >> m;
    int in[n], w[n], outOrder = 0;
    for (int i = 0; i < n; i++)
        scanf("%d", w + i);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", in + i);
        Mouse *tmp = new Mouse(w[in[i]], in[i]);
        mice.push_back(tmp);
        Q.push(mice[i]);
    }
    while (Q.size() > 1)
    {
        ++outOrder;
        tmpwin.clear();
        int s = Q.size();
        for (int j = 0; j < s / m; j++)
        {
            group.clear();
            for (int i = 0; i < m; i++)
            {
                group.push_back(Q.front());
                Q.pop();
            }
            vector<Mouse *>::iterator it = max_element(group.begin(), group.end(), cmp);
            tmpwin.push_back(*it);
            group.erase(it);
            for (auto k : group)
                k->out_o = outOrder;
        }
        if (Q.size())
        {
            group.clear();
            while (Q.size())
            {
                group.push_back(Q.front());
                Q.pop();
            }
            vector<Mouse *>::iterator it = max_element(group.begin(), group.end(), cmp);
            tmpwin.push_back(*it);
            group.erase(it);
            for (auto k : group)
                k->out_o = outOrder;
        }
        for (auto i : tmpwin)
            Q.push(i);
    }
    Q.front()->out_o = ++outOrder;
    sort(mice.begin(), mice.end(), cmp1);
    int c = 1;
    unordered_map<int, int> mp;
    mp[mice[0]->w] = 1;
    for (int i = 1; i < n; i++)
    {
        if (mice[i]->out_o != mice[i - 1]->out_o)
            c = i + 1;
        mp[mice[i]->w] = c;
    }
    printf("%d", mp[w[0]]);
    for (int i = 1; i < n; i++)
        printf(" %d", mp[w[i]]);
    return 0;
}//attention