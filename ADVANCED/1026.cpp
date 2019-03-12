// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <functional>
#include <cstdio>
#define test() freopen("in", "r", stdin)

using namespace std;
struct Table
{
    int served = 0;
    bool isVIP = false;
} table[102];
struct Player
{
    int arriveTime, useMinutes;
    bool isVIP;
    Player(int p, int tu, bool v) : arriveTime(p), useMinutes(tu), isVIP(v) {}
    bool operator<(const Player &b) const {return arriveTime < b.arriveTime;}
};
bool operator<(const pair<int, int> &a, const pair<int, int> &b){return a.first < b.first;}

set<Player> waitingQ;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> usedTables;
set<int> freeTables;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, tableNum, tableVipNum, tableVipRemain, a, b, c, p, vip, nowTime = 8 * 3600;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d:%d:%d %d %d", &a, &b, &c, &p, &vip);
        p = min(p, 120);
        waitingQ.insert(Player(a * 3600 + b * 60 + c, p, vip == 1));
    }
    scanf("%d%d", &tableNum, &tableVipNum);
    for (int i = 0; i < tableNum; ++i)
        freeTables.insert(i);
    for (int i = 0; i < tableVipNum; ++i)
    {
        scanf("%d", &vip);
        table[--vip].isVIP = true;
    }
    tableVipRemain = tableVipNum;
    while (waitingQ.size() && nowTime < 21 * 3600)
    {
        int arrive_t = waitingQ.begin()->arriveTime;
        if (freeTables.size() && arrive_t <= nowTime)
        {
            if (tableVipRemain > 0)
            {
                set<Player>::iterator it = waitingQ.begin();
                while (it != waitingQ.end() && it->arriveTime <= nowTime)
                {
                    if (it->isVIP) break;
                    it++;
                }
                if (it != waitingQ.end() && it->arriveTime <= nowTime)
                {
                    tableVipRemain--;
                    arrive_t = it->arriveTime;
                    set<int>::iterator iter = freeTables.begin();
                    for (; !table[(*iter)].isVIP; iter++)
                        ;
                    table[*iter].served++;
                    usedTables.push(make_pair(nowTime + it->useMinutes * 60, *iter));
                    freeTables.erase(*iter);
                    waitingQ.erase(*it);
                    printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", arrive_t / 3600, arrive_t % 3600 / 60, arrive_t % 60, nowTime / 3600, nowTime % 3600 / 60, nowTime % 60, (nowTime - arrive_t + 30) / 60);
                    continue;
                }
            }
            printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", arrive_t / 3600, arrive_t % 3600 / 60, arrive_t % 60, nowTime / 3600, nowTime % 3600 / 60, nowTime % 60, (nowTime - arrive_t + 30) / 60);
            table[*freeTables.begin()].served++;
            usedTables.push(make_pair(nowTime + waitingQ.begin()->useMinutes * 60, *freeTables.begin()));
            if (table[*freeTables.begin()].isVIP)
                tableVipRemain--;
            freeTables.erase(*freeTables.begin());
            waitingQ.erase(*waitingQ.begin());
            continue;
        }
        else
        {
            if (usedTables.empty() || (freeTables.size() && arrive_t <= usedTables.top().first))
                nowTime = arrive_t;
            else
            {
                if (nowTime < usedTables.top().first)
                    nowTime = usedTables.top().first;
                while (usedTables.size() && nowTime >= usedTables.top().first)
                {
                    freeTables.insert(usedTables.top().second);
                    if (table[usedTables.top().second].isVIP)
                        tableVipRemain++;
                    usedTables.pop();
                }
            }
        }
    }//attention
    cout << table[0].served;
    for (int i = 1; i < tableNum; i++)
        cout << " " << table[i].served;
    return 0;
}