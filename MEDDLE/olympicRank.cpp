// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
struct Country
{
    double gold, medal, g_p, m_p;
    int rank[5];
};
inline bool cmp0(const Country &a, const Country &b)
{
    return a.rank[0] < b.rank[0];
}
inline bool cmp1(const Country &a, const Country &b)
{
    return a.gold > b.gold;
}
inline bool cmp2(const Country &a, const Country &b)
{
    return a.medal > b.medal;
}
inline bool cmp3(const Country &a, const Country &b)
{
    return a.g_p > b.g_p;
}
inline bool cmp4(const Country &a, const Country &b)
{
    return a.m_p > b.m_p;
}

typedef bool (*PF)(const Country &, const Country &);
PF cmps[5] = {cmp0, cmp1, cmp2, cmp3, cmp4};

inline void solve(Country *countries, int m, int id)
{
    sort(countries, countries + m, cmps[id]);
    int rank = 1, i;
    countries[0].rank[id] = 1;
    for (i = 1; i < m; i++)
    {
        if (*((double *)&countries[i] + id - 1) != *((double *)&countries[i - 1] + id - 1))
            rank = i + 1;
        countries[i].rank[id] = rank;
    }
}
int main()
{
    //test();
    int n, m;
    while (cin >> n >> m)
    {
        Country countries[1000];
        int i, population, num;
        for (i = 0; i < n; i++)
        {
            cin >> countries[i].gold >> countries[i].medal >> population;
            countries[i].g_p = 1.0 * countries[i].gold / population;
            countries[i].m_p = 1.0 * countries[i].medal / population;
        }
        for (i = 0; i < m; i++)
        {
            cin >> num;
            countries[i] = countries[num];
            countries[i].rank[0] = i;
        }
        for (int id = 1; id <= 4; id++)
            solve(countries, m, id);
        sort(countries, countries + m, cmps[0]);
        int j;
        for (j = 0; j < m; j++)
        {
            int r = countries[j].rank[1], method = 1;
            for (i = 2; i <= 4; i++)
            {
                if (countries[j].rank[i] < r)
                {
                    r = countries[j].rank[i];
                    method = i;
                }
            }
            cout << r << ":" << method << endl;
        }
        cout << endl;
    }
    return 0;
}