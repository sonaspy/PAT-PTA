// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
int n, m, k;
struct Student
{
    int ge = 0, gi, choice[5], id;
    double g = 0.0;
    bool operator<(const Student &b) const { return g != b.g ? g > b.g : ge > b.ge; }
    bool operator==(const Student &b) const { return g == b.g && ge == b.ge; }
} stus[40001];
struct School
{
    int quota;
    Student last;
    vector<int> stu;
} sch[100];

inline void DealWith(int id)
{
    for (int i = 0; i < k; i++)
    {
        int sch_id = stus[id].choice[i];
        if (stus[id] == sch[sch_id].last)
        {
            sch[sch_id].quota--;
            sch[sch_id].stu.push_back(stus[id].id);
            return;
        }
        else if (sch[sch_id].quota > 0)
        {
            sch[sch_id].quota--;
            sch[sch_id].last = stus[id];
            sch[sch_id].stu.push_back(stus[id].id);
            return;
        }
    }
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
        scanf("%d", &sch[i].quota);
    for (int i = 0; i < n; i++)
    {
        stus[i].id = i;
        scanf("%d%d", &stus[i].ge, &stus[i].gi);
        stus[i].g = (stus[i].ge + stus[i].gi) / 2;
        for (int j = 0; j < k; j++)
            scanf("%d", stus[i].choice + j);
    }
    sort(stus, stus + n);
    for (int i = 0; i < n; i++)
        DealWith(i);
    for (int i = 0; i < m; i++)
    {
        sort(sch[i].stu.begin(), sch[i].stu.end());
        for (int j = 0; j < sch[i].stu.size(); j++)
        {
            if (j != 0)
                cout << " ";
            cout << sch[i].stu[j];
        }
        cout << endl;
    }
    return 0;
}