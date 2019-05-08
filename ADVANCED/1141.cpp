// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
struct node
{
    string id;
    int cnt = 0, sa = 0, st = 0, sb = 0, sc = 0;
    node(string s) : id(s) {}
};
unordered_map<string, node *> mp;
vector<node *> v;
inline bool cmp(const node *a, const node *b) { return a->sc != b->sc ? a->sc > b->sc : a->cnt != b->cnt ? a->cnt < b->cnt : a->id < b->id; }
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, tmp, rank = 1;
    char name[20], id[20];
    string scid;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%s%d%s", name, &tmp, id);
        scid = id;
        transform(scid.begin(), scid.end(), scid.begin(), ::tolower);
        if (!mp.count(scid))
            mp[scid] = new node(scid);
        mp[scid]->cnt++;
        if (name[0] == 'A')
            mp[scid]->sa += tmp;
        else if (name[0] == 'B')
            mp[scid]->sb += tmp;
        else if (name[0] == 'T')
            mp[scid]->st += tmp;
    }
    for (auto &i : mp)
    {
        i.second->sc = i.second->st * 1.5 + i.second->sa + i.second->sb / 1.5;
        v.push_back(i.second);
    }
    sort(v.begin(), v.end(), cmp);
    cout << v.size() << endl;
    printf("%d %s %d %d\n", rank, v[0]->id.c_str(), v[0]->sc, v[0]->cnt);
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i - 1]->sc != v[i]->sc)
            rank = i + 1;
        printf("%d %s %d %d\n", rank, v[i]->id.c_str(), v[i]->sc, v[i]->cnt);
    }

    return 0;
}