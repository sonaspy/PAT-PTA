// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)
using namespace std;
const int MAX_N = 10010;
struct Car
{
    char id[8], status[4];
    int Time;
} all_record[MAX_N];
int f_num = 0;
map<string, int> parkTime;
inline int convert(int hh, int mm, int ss) { return hh * 3600 + mm * 60 + ss; }
bool cmp(const Car &a, const Car &b) { return strcmp(a.id, b.id) ? strcmp(a.id, b.id) < 0 : a.Time < b.Time; }

struct CMP
{
    bool operator()(const Car &a, const Car &b) const { return a.Time > b.Time; }
};
priority_queue<Car, vector<Car>, CMP> pq;
int main()
{
    //test();
    int n, k, hh, mm, ss;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d:%d:%d %s", all_record[i].id, &hh, &mm, &ss, all_record[i].status);
        all_record[i].Time = convert(hh, mm, ss);
    }
    sort(all_record, all_record + n, cmp);
    int maxTime = -1;
    for (int i = 0; i < n - 1; i++)
    {
        if (!strcmp(all_record[i].id, all_record[i + 1].id) && !strcmp(all_record[i].status, "in") && !strcmp(all_record[i + 1].status, "out"))
        {
            pq.push(all_record[i]), pq.push(all_record[i + 1]);
            parkTime[all_record[i].id] += all_record[i + 1].Time - all_record[i].Time;
            maxTime = max(maxTime, parkTime[all_record[i].id]);
        }
    }
    int numCar = 0, Time;
    for (int i = 0; i < k; i++)
    {
        scanf("%d:%d:%d", &hh, &mm, &ss);
        Time = convert(hh, mm, ss);
        while (pq.size() && pq.top().Time <= Time)
        {
            !strcmp(pq.top().status, "in") ? numCar++ : numCar--;
            pq.pop();
        }
        printf("%d\n", numCar);
    }
    for (auto it : parkTime)
    {
        if (it.second == maxTime)
            printf("%s ", it.first.c_str());
    }
    printf("%02d:%02d:%02d\n", maxTime / 3600, maxTime % 3600 / 60, maxTime % 60);
    return 0;
} // attention