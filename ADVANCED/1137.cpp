// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
struct node
{
    string id;
    int gm, gf, g, gpro;
    node(string i) : id(i) { gm = -1, gf = -1, gpro = -1, g = -1; }
};
int p, m, n, tmpg;
unordered_map<string, node *> mp;
vector<node *> vec;
bool cmp(const node *a, const node *b) { return a->g != b->g ? a->g > b->g : a->id < b->id; }
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cin >> p >> m >> n;
    string id;
    for (int i = 0; i < p; i++)
    {
        cin >> id >> tmpg;
        if (tmpg < 200)
            continue;
        mp[id] = new node(id);
        mp[id]->gpro = tmpg;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> id >> tmpg;
        if (mp.count(id))
            mp[id]->gm = tmpg;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> id >> tmpg;
        if (mp.count(id))
            mp[id]->gf = tmpg;
    }
    for (auto &i : mp)
    {
        i.second->g = i.second->gm > i.second->gf ? (i.second->gm * 0.4 + i.second->gf * 0.6 + 0.5) : i.second->gf;
        if (i.second->g >= 60 && i.second->g <= 100)
            vec.push_back(i.second);
    }
    sort(vec.begin(), vec.end(), cmp);
    for (auto i : vec)
        printf("%s %d %d %d %d\n", i->id.c_str(), i->gpro, i->gm, i->gf, i->g);
    return 0;
}