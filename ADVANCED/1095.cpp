// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>
#define EQUAL !strcmp
#define test() freopen("in", "r", stdin)
using namespace std;
const int MAX_N = 10010;
typedef struct Car *ptrOfCar;
struct Car
{
    char id[8], status[4];
    int Time;
} AllRecords[MAX_N];
int f_num = 0;
map<string, int> parkTime;
inline int convert(int hh, int mm, int ss) { return hh * 3600 + mm * 60 + ss; }
bool cmp(const Car &a, const Car &b) { return strcmp(a.id, b.id) ? strcmp(a.id, b.id) < 0 : a.Time < b.Time; }

struct CMP
{
    bool operator()(const ptrOfCar &a, const ptrOfCar &b) const { return a->Time > b->Time; }
};
priority_queue<ptrOfCar, vector<ptrOfCar>, CMP> pq;
int main()
{
    //test();
    int n, k, hh, mm, ss;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d:%d:%d %s", AllRecords[i].id, &hh, &mm, &ss, AllRecords[i].status);
        AllRecords[i].Time = convert(hh, mm, ss);
    }
    sort(AllRecords, AllRecords + n, cmp);
    int maxParkTime = -1;
    for (int i = 0; i < n - 1; i++)
    {
        if (EQUAL(AllRecords[i].id, AllRecords[i + 1].id) && EQUAL(AllRecords[i].status, "in") && EQUAL(AllRecords[i + 1].status, "out"))
        {
            pq.push(AllRecords + i), pq.push(AllRecords + i + 1);
            parkTime[AllRecords[i].id] += AllRecords[i + 1].Time - AllRecords[i].Time;
            maxParkTime = max(maxParkTime, parkTime[AllRecords[i].id]);
        }
    }
    int numCar = 0, Time;
    for (int i = 0; i < k; i++)
    {
        scanf("%d:%d:%d", &hh, &mm, &ss);
        Time = convert(hh, mm, ss);
        while (pq.size() && pq.top()->Time <= Time)
        {
            EQUAL(pq.top()->status, "in") ? numCar++ : numCar--;
            pq.pop();
        }
        printf("%d\n", numCar);
    }
    for (auto it : parkTime)
    {
        if (it.second == maxParkTime)
            printf("%s ", it.first.c_str());
    }
    printf("%02d:%02d:%02d\n", maxParkTime / 3600, maxParkTime % 3600 / 60, maxParkTime % 60);
    return 0;
}