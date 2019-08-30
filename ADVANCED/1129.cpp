// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
int n, k, tmp;
struct node
{
    int val, freq = 0;
    node() {}
    node(int v) : val(v) {}
} keys[50001];
struct cmp
{
    bool operator()(const node *a, const node *b) const
    {
        return a->freq != b->freq ? a->freq > b->freq : a->val < b->val;
    }
};
set<node *, cmp> pq;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cin >> n >> k >> tmp;
    keys[tmp].val = tmp;
    keys[tmp].freq++;
    pq.insert(keys + tmp);
    for (int i = 1; i < n; i++)
    {
        scanf("%d", &tmp);
        printf("%d:", tmp);
        int c = 0;
        for (auto j : pq)
        {
            if (c == k)
                break;
            printf(" %d", j->val);
            c++;
        }
        if (!pq.count(keys + tmp))
        {
            keys[tmp].val = tmp;
            keys[tmp].freq++;
            pq.insert(keys + tmp);
        }
        else
        {
            pq.erase(pq.find(keys + tmp));
            keys[tmp].freq++;
            pq.insert(keys + tmp);
        }
        printf("\n");
    }
    return 0;
}