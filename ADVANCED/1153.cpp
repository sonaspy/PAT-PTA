// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
struct node
{
    int sc;
    string id;
    node(string id, int sc) : id(id), sc(sc) {}
};
bool cmp(const node *a, const node *b) { return a->sc != b->sc ? a->sc > b->sc : a->id < b->id; }
bool cmp2(const pair<int, int> a, const pair<int, int> b) { return a.second != b.second ? a.second > b.second : a.first < b.first; }
vector<node *> type1[30];
pair<int, int> type2[1000];
unordered_map<string, unordered_map<int, int>> type3;
unordered_map<string, vector<pair<int, int>>> type3__;
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, m, sc, siten, type__;
    string ids;
    cin >> n >> m;
    char id[20];
    fill(type2, type2 + 1000, make_pair(0, 0));
    for (int i = 0; i < n; i++)
    {
        scanf("%s%d", id, &sc);
        ids = id;
        node *tmp = new node(ids, sc);
        siten = stoi(ids.substr(1, 3));
        string date_ = ids.substr(4, 6);
        type2[siten].first++, type2[siten].second += sc;
        type3[date_][siten]++;
        type1[id[0] - 'A'].push_back(tmp);
    }
    sort(type1[0].begin(), type1[0].end(), cmp), sort(type1[1].begin(), type1[1].end(), cmp), sort(type1['T' - 'A'].begin(), type1['T' - 'A'].end(), cmp);
    for (auto i : type3)
    {
        for (auto j : i.second)
            type3__[i.first].push_back(make_pair(j.first, j.second));
    }
    for (auto &i : type3__)
        sort(i.second.begin(), i.second.end(), cmp2);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &type__);
        printf("Case %d: %d ", i, type__);
        if (type__ == 1)
        {
            getchar();
            char c = getchar();
            printf("%c\n", c);
            if (type1[c - 'A'].empty())
                printf("NA\n");
            else
            {
                for (auto it : type1[c - 'A'])
                    printf("%s %d\n", it->id.c_str(), it->sc);
            }
        }
        else if (type__ == 2)
        {
            int siteid;
            scanf("%d", &siteid);
            printf("%d\n", siteid);
            if (type2[siteid].first == 0)
                printf("NA\n");
            else
                printf("%d %d\n", type2[siteid].first, type2[siteid].second);
        }
        else
        {
            scanf("%s", id);
            printf("%s\n", id);
            if (!type3__.count(id))
                printf("NA\n");
            else
            {
                for (auto j : type3__[id])
                    printf("%d %d\n", j.first, j.second);
            }
        }
    }

    return 0;
}