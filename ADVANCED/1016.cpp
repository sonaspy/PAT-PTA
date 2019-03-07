// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#define test() freopen("in", "r", stdin)

using namespace std;

int unicost[25], n, hour = 60, day = hour * 24;
struct node
{
    int m, arr[4];
    string T;
    bool on;
};
struct Node
{
    vector<node> time;
    int mon;
};
bool cmp(node a, node b)
{
    return a.m < b.m;
}

inline int cal(node &n)
{
    int sum = 0;
    sum += n.arr[2] * unicost[n.arr[1]] + unicost[24] * 60 * n.arr[0];
    for (int i = 0; i < n.arr[1]; i++)
        sum += unicost[i] * 60;
    return sum;
}

int main(int argc, char const *argv[])
{
    /* code */
    test();
    map<string, Node> mp;
    for (int i = 0; i < 24; i++)
    {
        cin >> unicost[i];
        unicost[24] += unicost[i];
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s, t, s1;
        char str[9];
        int M, D, h, m;
        cin >> s;
        scanf("%d:%d:%d:%d", &M, &D, &h, &m);
        cin >> s1;
        sprintf(str, "%02d:%02d:%02d", D, h, m);
        t = str;
        node tmp;
        tmp.m = m + h * hour + day * D, tmp.T = t, tmp.on = (s1[1] == 'n') ? true : false, tmp.arr[0] = D, tmp.arr[1] = h, tmp.arr[2] = m;
        mp[s].mon = M;
        mp[s].time.push_back(tmp);
    }
    for (auto i : mp)
        sort(mp[i.first].time.begin(), mp[i.first].time.end(), cmp);
    for (auto i : mp)
    {
        int sum = 0, flag = 0;
        for (int j = 0; j < i.second.time.size() - 1;)
        {
            if (i.second.time[j + 1].on == false && i.second.time[j].on == true)
            {
                if(!flag){printf("%s %02d\n", i.first.c_str(), i.second.mon);flag = 1;}
                int t = i.second.time[j + 1].m - i.second.time[j].m, index = 0, tmp = 0;
                tmp = cal(i.second.time[j + 1]) - cal(i.second.time[j]);
                sum += tmp;
                cout << i.second.time[j].T << " " << i.second.time[j + 1].T;
                printf(" %d $%.2f\n", t, tmp * 1.0 / 100);
                j += 2;
            }
            else j++;
        }
        if(flag)printf("Total amount: $%.2f\n", sum * 1.0 / 100);
    }
    return 0;
}