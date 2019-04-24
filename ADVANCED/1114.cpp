// author - newguo@sonaspy.cn
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
    int id = 1 << 30, size_ = 0;
    double avg_sts = 0, avg_area = 0;
    bool operator<(const family &b) const { return avg_area != b.avg_area ? avg_area > b.avg_area : id < b.id; }
};
unordered_map<int, family> mp;
set<family> v;
int my_union[10000], exist[10000] = {0};
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
    int n, id, num, i, j, tmp, father, mother, root;
    fill(my_union, my_union + 10000, -1);
    cin >> n;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &id), nodes[id].id = id, scanf("%d%d%d", &father, &mother, &num);
        exist[id] = 1;
        if (father != -1)
            exist[father] = 1;
        if (mother != -1)
            exist[mother] = 1;
        union__(id, father), union__(id, mother);
        for (j = 0; j < num; j++)
        {
            scanf("%d", &tmp);
            exist[tmp] = 1;
            union__(id, tmp);
        }
        scanf("%d%d", &nodes[id].m_es, &nodes[id].t_area);
    }
    for (i = 0; i < 10000; i++)
    {
        if (exist[i])
        {
            root = find_root(i);
            if (i < mp[root].id)
                mp[root].id = i;
            mp[root].size_++;
            mp[root].avg_area += nodes[i].t_area;
            mp[root].avg_sts += nodes[i].m_es;
        }
    }
    for (auto &k : mp)
    {
        k.second.avg_area /= k.second.size_ * 1.0;
        k.second.avg_sts /= k.second.size_ * 1.0;
        v.insert(k.second);
    }
    cout << v.size() << endl;
    for (auto k : v)
        printf("%04d %d %.3f %.3f\n", k.id, k.size_, k.avg_sts, k.avg_area);
    return 0;
}