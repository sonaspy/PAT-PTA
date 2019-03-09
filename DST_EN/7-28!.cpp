// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int H, N, t0, totalMinutes, totalTime, INF = 1000000000, t[9], d[9], minTime;
string names[9];
bool solved[9];
vector<int> tmpOrder, solvedOrder;
inline int debugtime(int currentTime)
{
    if (currentTime <= 60)
        return 0;
    else if (currentTime > 60 && currentTime <= 120)
        return 1;
    else if (currentTime > 120 && currentTime <= 180)
        return 2;
    else if (currentTime > 180 && currentTime <= 240)
        return 3;
    else if (currentTime > 240 && currentTime <= 300)
        return 4;
}
void dfs(int currentTime, int penaltyTime, int totalTime)
{
    if ((tmpOrder.size() > solvedOrder.size()) ||
            (tmpOrder.size() == solvedOrder.size() && totalTime + penaltyTime * 20 < minTime))
        {
            solvedOrder = tmpOrder;
            minTime = totalTime + penaltyTime * 20;
        }
    for (int i = 0; i < N; i++)
        if (!solved[i])
            {
                int dtime = debugtime(currentTime + t[i]), now = currentTime + t[i] + dtime * d[i];
                if (now <= totalMinutes)
                    {
                        solved[i] = true;
                        tmpOrder.push_back(i);
                        dfs(now, penaltyTime + dtime, totalTime + now);
                        solved[i] = false;
                        tmpOrder.pop_back();
                    }
            }
}
int main()
{
    while (true)
        {
            scanf("%d", &H);
            if (H < 0)
                break;
            scanf("%d %d", &N, &t0);
            for (int i = 0; i < N; i++)
                cin >> names[i] >> t[i] >> d[i];
            totalMinutes = H * 60;
            minTime = INF;
            solvedOrder.clear();
            fill(solved, solved + N, false);
            dfs(t0, 0, 0);
            printf("Total Time = %d\n", minTime);
            for (int i = 0; i < solvedOrder.size(); i++)
                printf("%s\n", names[solvedOrder[i]].c_str());
        }
    return 0;
}