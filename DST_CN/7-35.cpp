// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <list>
using namespace std;

#define test() freopen("in", "r", stdin)

#define INFINITY 999999

int city[502][502];
int cnt[502], vis[502] = {0}, team_num[502], acum_team_n[502], pre[502];

int N, M, S, D;

void Dijkstra()
{
    cnt[S] = 1;
    vis[S] = 1;
    for (int i = 0; i < 1; i++)
    {
        int min = INFINITY, next = -1;
        for (int j = 0; j < N; j++)
        {
            if (!vis[j] && city[S][j] < min)
            {
                min = city[S][j];
                next = j;
            }
        }
        if (next == -1)
            continue;
        else
            vis[next] = 1;
        for (int j = 0; j < N; j++)
        {
            if (!vis[j] && city[S][j] > city[S][next] + city[next][j])
            {
                city[S][j] = city[S][next] + city[next][j];
                pre[j] = next;
                cnt[j] = cnt[next];
                acum_team_n[j] = acum_team_n[next] + team_num[j];
            }
            else if (!vis[j] && city[S][j] == city[S][next] + city[next][j])
            {
                cnt[j] += cnt[next];
                if (acum_team_n[j] < acum_team_n[next] + team_num[j])
                {
                    pre[j] = next;
                    acum_team_n[j] = acum_team_n[next] + team_num[j];
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    /* code */

    cin >> N >> M >> S >> D;

    for (int i = 0; i < N; i++)
    {
        cin >> team_num[i];
        cnt[i] = 1;
        acum_team_n[i] = team_num[i];
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (i != j)
                city[i][j] = city[j][i] = INFINITY;

    for (int i = 0; i < M; i++)
    {
        int c1, c2, dis;
        cin >> c1 >> c2 >> dis;
        city[c1][c2] = city[c2][c1] = dis;
    }
    Dijkstra();
    cout << cnt[D] << " " << team_num[S] + acum_team_n[D] << endl;
    int tmp = D;
    list<int> path;
    list<int>::iterator pt;
    while (pre[tmp])
    {
        path.push_front(pre[tmp]);
        tmp = pre[tmp];
    }
    cout << S;
    for (pt = path.begin(); pt != path.end(); pt++)
    {
        cout << " " << *pt;
    }
    cout << " " << D;
    return 0;
}