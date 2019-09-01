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
bool cmp2(const pair<int, int> &a, const pair<int, int> &b) { return a.second != b.second ? a.second > b.second : a.first < b.first; }
vector<node *> table1[30];
pair<int, int> table2[1000];
unordered_map<string, unordered_map<int, int>> type3;
unordered_map<string, vector<pair<int, int>>> table3;
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, m, sc, siten, kind;
    string ids;
    cin >> n >> m;
    char id[20];
    fill(table2, table2 + 1000, make_pair(0, 0));
    for (int i = 0; i < n; i++)
    {
        scanf("%s%d", id, &sc);
        ids = id;
        node *tmp = new node(ids, sc);
        siten = stoi(ids.substr(1, 3));
        string date_ = ids.substr(4, 6);
        table2[siten].first++, table2[siten].second += sc;
        type3[date_][siten]++;
        table1[id[0] - 'A'].push_back(tmp);
    }
    sort(table1[0].begin(), table1[0].end(), cmp), sort(table1[1].begin(), table1[1].end(), cmp), sort(table1['T' - 'A'].begin(), table1['T' - 'A'].end(), cmp);
    for (auto &i : type3)
    {
        for (auto &j : i.second)
            table3[i.first].push_back(make_pair(j.first, j.second));
    }
    for (auto &i : table3)
        sort(i.second.begin(), i.second.end(), cmp2);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &kind), printf("Case %d: %d ", i, kind);
        if (kind == 1)
        {
            getchar();
            char c = getchar();
            printf("%c\n", c);
            if (table1[c - 'A'].empty())
                printf("NA\n");
            else
            {
                for (auto it : table1[c - 'A'])
                    printf("%s %d\n", it->id.c_str(), it->sc);
            }
        }
        else if (kind == 2)
        {
            int siteid;
            scanf("%d", &siteid);
            printf("%d\n", siteid);
            if (table2[siteid].first == 0)
                printf("NA\n");
            else
                printf("%d %d\n", table2[siteid].first, table2[siteid].second);
        }
        else
        {
            scanf("%s", id), printf("%s\n", id);
            if (!table3.count(id))
                printf("NA\n");
            else
            {
                for (auto j : table3[id])
                    printf("%d %d\n", j.first, j.second);
            }
        }
    }

    return 0;
}