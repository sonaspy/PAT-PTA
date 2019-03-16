// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<iostream>
#include<vector>
#include<algorithm>
#define test() freopen("in","r",stdin)
using namespace std;
#define _INF_ 99999999
struct Player
{
    int arrive, use_time, start;
    bool served, isVIP;      
};
int cmp1(Player &a, Player &b) {return a.arrive < b.arrive ;}
int cmp2(Player &a, Player &b){return a.start < b.start;} 
struct Table
{
    int endtime = 8*3600, serve_cnt = 0; 
    bool isVIP = false;         
};
vector<Player> players; 
vector<Table> tables;  

int findvip(int index, int before)
{
    for (int i = index; i < players.size() && players[i].arrive <= before; i++){if (!players[i].served && players[i].isVIP) return i;}
    return -1;
}

void update(int pla_id, int tb_id)
{
    players[pla_id].start = max(players[pla_id].arrive, tables[tb_id].endtime);players[pla_id].served = 1;
    tables[tb_id].endtime = players[pla_id].start + players[pla_id].use_time; tables[tb_id].serve_cnt++;
}

int main()
{
    //test();
    int n, m, k, t_id;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int h, m, s, use_time, isVIP, arrive;
        scanf("%d:%d:%d%d%d", &h, &m, &s, &use_time, &isVIP);
        arrive = h * 3600 + m * 60 + s;
        use_time = use_time > 120 ? 7200 : use_time * 60;
        players.push_back({arrive, use_time, 0, 0, isVIP > 0});
    }
    sort(players.begin(), players.end(), cmp1);
    cin >> m >> k;
    tables.resize(m);
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &t_id);
        tables[t_id - 1].isVIP = 1;
    }
    for (int i = 0; i < players.size();)
    {
        int minEndTime = _INF_, minEndIndex;
        for (int j = 0; j < m; j++)
        {
            if (tables[j].endtime < minEndTime) 
            {
                minEndTime = tables[j].endtime;
                minEndIndex = j;
            }
        }
        if (21 * 3600 <= minEndTime || 21 * 3600 <= players[i].arrive ) break;
        int pla_id = i, tb_id = minEndIndex; // pla_id : player's id(soon will be served ) .tb_id : Table's id (that will serve the player).
        if ( players[i].arrive <= minEndTime)
        {
            if (tables[tb_id].isVIP)
            {
                int vipid = findvip(pla_id, minEndTime);
                pla_id = (vipid != -1) ? vipid : pla_id;
            }
            else if (players[i].isVIP)
            {
                for (int j = 0; j < m; j++)
                    if (tables[j].isVIP && tables[j].endtime <= players[pla_id].arrive){tb_id = j;break;}
            }
        }
        else
        {
            for (int j = 0; j < m; j++)
            {
                if (tables[j].endtime <= players[pla_id].arrive){tb_id = j;break;}
            }
            if (players[pla_id].isVIP)
                for (int j = 0; j < m; j++)
                {
                    if (tables[j].isVIP && tables[j].endtime <= players[pla_id].arrive){tb_id = j;break;}
                }
        }
        update(pla_id, tb_id);
        while (i < players.size() && players[i].served)i++;
    }
    sort(players.begin(), players.end(), cmp2);
    for (int i = 0; i < players.size(); i++)
    {
        if (players[i].served)
        {
            int wait = players[i].start - players[i].arrive;
            printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", players[i].arrive / 3600, players[i].arrive % 3600 / 60, players[i].arrive % 60,
                   players[i].start / 3600, players[i].start % 3600 / 60, players[i].start % 60, (int)(1.0 * wait / 60 + 0.5));
        }
    }
    for (int i = 0; i < m; i++)
        printf("%d%c", tables[i].serve_cnt, i == m - 1 ? '\n' : ' ');
    return 0;
}