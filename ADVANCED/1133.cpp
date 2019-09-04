// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
struct node
{
    int id, data, next;
} mp[100000];
int n, walk, k, id;
inline bool cmp(const node *a, const node *b)
{
    return (a->data < 0 && b->data >= 0) || (a->data <= k && b->data > k);
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cin >> walk >> n >> k;
    vector<node *> v;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &id), mp[id].id = id;
        scanf("%d%d", &mp[id].data, &mp[id].next);
    }
    for (; walk != -1; walk = mp[walk].next)
        v.push_back(mp + walk);
    stable_sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size() - 1; i++)
        printf("%05d %d %05d\n", v[i]->id, v[i]->data, v[i + 1]->id);
    printf("%05d %d -1", v.back()->id, v.back()->data);
    return 0;
}