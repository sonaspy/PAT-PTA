// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int k, n, m, a, b, c;
struct node
{
    int sum, suscall;
    node() : sum(0), suscall(0) {}
};
vector<set<int>> gangs(1000);
vector<vector<node>> mp(1111, vector<node>(1111, node()));
vector<int> theUnion(1111, -1);
bool cmp(set<int> &a, set<int> &b) { return a.size() > b.size(); }
int find_root(int a)
{
    return theUnion[a] == 0 ? a : theUnion[a] = find_root(theUnion[a]);
}
void Unite(int a, int b)
{
    int ra = find_root(a), rb = find_root(b);
    theUnion[rb] = ra;
}

int main(int argc, char const *argv[])
{
    /* code */
    test();
    cin >> k >> n >> m;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &a, &b);
        scanf("%d", &c);
        mp[a][b].sum++;
        if (c <= 5)
            mp[a][b].suscall++;
    }
    for (int i = 1; i <= n; i++)
    {
        int callt = 0, rece = 0, calp = 0;
        double perc = 0;
        for (int j = 1; j <= n; j++)
        {
            if (mp[i][j].suscall)
            {
                calp++;
                callt += mp[i][j].suscall;
                if (mp[j][i].sum)
                    rece += min(mp[i][j].suscall, mp[j][i].sum);
            }
        }
        perc = rece * 1.0 / callt;
        if (perc <= 0.2 && calp > k)
            theUnion[i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!theUnion[i])
        {
            for (int j = 1; j <= n; j++)
                if (!theUnion[j] && mp[i][j].sum && mp[j][i].sum)
                    Unite(i, j);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (theUnion[i] != -1)
        {
            int root = find_root(i);
            gangs[root].insert(i);
        }
    }
    sort(gangs.begin(), gangs.end(), cmp);
    for (auto &i : gangs)
    {
        if (i.size())
        {
            auto j = i.begin();
            cout << *j;
            j++;
            for (; j != i.end(); j++)
                cout << " " << *j;
            cout << endl;
        }
    }
    return 0;
}