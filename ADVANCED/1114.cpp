// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
struct node
{
    int id, m_es = 0, t_area = 0;
} nodes[10000];

struct family
{
    int id = INT_MAX, sIze = 0;
    double avg_sts = 0, avg_area = 0;
    bool operator<(const family &b) const { return avg_area != b.avg_area ? avg_area > b.avg_area : id < b.id; }
};
unordered_map<int, family> mp;
set<family> fams;
vector<int> my_union(10000, -1);
unordered_map<int, int> exist;
inline int find_root(int id)
{
    return (my_union[id] == -1) ? id : my_union[id] = find_root(my_union[id]);
}
inline void union__(int a, int b)
{
    if (a == -1 || b == -1)
        return;
    int r_a = find_root(a), r_b = find_root(b);
    if (r_a != r_b)
        my_union[r_b] = r_a;
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, id, num, i, j, child, father, mother, root;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &id), nodes[id].id = id, scanf("%d%d%d", &father, &mother, &num);
        exist[id] = exist[father] = exist[mother] = 1;
        union__(id, father), union__(id, mother);
        for (j = 0; j < num; j++)
        {
            scanf("%d", &child);
            exist[child] = 1;
            union__(id, child);
        }
        scanf("%d%d", &nodes[id].m_es, &nodes[id].t_area);
    }
    exist.erase(-1);
    for (auto i : exist)
    {
        if (i.second)
        {
            root = find_root(i.first);
            mp[root].id = min(i.first, mp[root].id), mp[root].sIze++, mp[root].avg_area += nodes[i.first].t_area, mp[root].avg_sts += nodes[i.first].m_es;
        }
    }
    for (auto &k : mp)
    {
        k.second.avg_area /= k.second.sIze * 1.0;
        k.second.avg_sts /= k.second.sIze * 1.0;
        fams.insert(k.second);
    }
    cout << fams.size() << endl;
    for (auto k : fams)
        printf("%04d %d %.3f %.3f\n", k.id, k.sIze, k.avg_sts, k.avg_area);
    return 0;
}