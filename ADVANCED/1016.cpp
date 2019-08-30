// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int u_price[25], n, hour = 60, day = hour * 24;
struct Record
{
    int minute, dhm[4];
    string T;
    bool online;
    bool operator<(const Record &b) const { return minute < b.minute; }
};
struct Person
{
    vector<Record> records;
    int mon;
};
inline int solveprice(Record &n)
{
    int sum = 0;
    sum += n.dhm[2] * u_price[n.dhm[1]] + u_price[24] * 60 * n.dhm[0];
    for (int i = 0; i < n.dhm[1]; i++)
        sum += u_price[i] * 60;
    return sum;
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    map<string, Person> mp;
    for (int i = 0; i < 24; i++)
    {
        cin >> u_price[i];
        u_price[24] += u_price[i];
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char str[9], s[22], s1[10];
        int M, D, h, m;
        scanf("%s", s), getchar();
        scanf("%d:%d:%d:%d", &M, &D, &h, &m), getchar();
        scanf("%s", s1), getchar();
        sprintf(str, "%02d:%02d:%02d", D, h, m);
        Record tmp;
        mp[s].mon = M;
        tmp.minute = m + h * hour + day * D, tmp.T = str, tmp.online = (s1[1] == 'n') ? true : false, tmp.dhm[0] = D, tmp.dhm[1] = h, tmp.dhm[2] = m;
        mp[s].records.push_back(tmp);
    }
    for (auto &i : mp)
        sort(i.second.records.begin(), i.second.records.end());
    for (auto i : mp)
    {
        int sum = 0, valid = 0;
        for (int j = 0; j < i.second.records.size() - 1;)
        {
            if (i.second.records[j + 1].online == false && i.second.records[j].online == true)
            {
                if (!valid)
                {
                    printf("%s %02d\n", i.first.c_str(), i.second.mon);
                    valid = 1;
                }
                int t = i.second.records[j + 1].minute - i.second.records[j].minute, tmp = 0;
                tmp = solveprice(i.second.records[j + 1]) - solveprice(i.second.records[j]);
                sum += tmp;
                printf("%s %s", i.second.records[j].T.c_str(), i.second.records[j + 1].T.c_str());
                printf(" %d $%.2f\n", t, tmp * 1.0 / 100);
                j += 2;
            }
            else
                j++;
        }
        if (valid)
            printf("Total amount: $%.2f\n", sum * 1.0 / 100);
    }
    return 0;
}