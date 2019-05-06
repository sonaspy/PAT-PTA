// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
struct node
{
    int id, data, next;
} mp[100000];

int n, src, k, id;
bool cmp(const node *a, const node *b)
{
    if ((a->data < 0 && b->data >= 0) || (a->data <= k && b->data > k))
        return true;
    else
        return false;
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cin >> src >> n >> k;
    vector<node *> v;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &id), mp[id].id = id;
        scanf("%d%d", &mp[id].data, &mp[id].next);
    }
    for (; src != -1; src = mp[src].next)
        v.push_back(mp + src);
    stable_sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size() - 1; i++)
        printf("%05d %d %05d\n", v[i]->id, v[i]->data, v[i + 1]->id);
    printf("%05d %d -1", v.back()->id, v.back()->data);
    return 0;
}