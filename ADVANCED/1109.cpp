// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

struct node
{
    string name;
    int height;
};
vector<node *> v, output(10000);
bool cmp(const node *a, const node *b)
{
    return a->height != b->height ? a->height > b->height : a->name < b->name;
}
int n, k, m, tmpm;
static inline int seq(int &idx)
{
    return (idx % 2 == 0) ? tmpm / 2 + idx / 2 : tmpm / 2 - (idx + 1) / 2;
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cin >> n >> k;
    m = n / k;
    for (int i = 0; i < n; i++)
    {
        v.push_back(new node);
        cin >> v[i]->name >> v[i]->height;
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0, c = 0; i < k; i++, c += tmpm)
    {
        if (i == 0)
            tmpm = m + n % k;
        else
            tmpm = m;
        int j = c, p = 0;
        output.clear();
        for (; j < (tmpm + c); j++, p++)
            output[seq(p)] = v[j];
        for (j = 0; j < tmpm; j++)
        {
            printf("%s", output[j]->name.c_str());
            cout << (j == tmpm - 1 ? "\n" : " ");
        }
    }
    return 0;
}