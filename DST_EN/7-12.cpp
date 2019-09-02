// author - sonaspy@outlook.com
// coding - utf_8

#include <iostream>
#include <queue>
#define test() freopen("in", "r", stdin)
#define MAXNUM 99999999
using namespace std;
struct Node
{
    int id, indegree = 0, total = 0;
} nodesArr[111];

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, m, map[300][300], maxTotal = 0, count = 0, a1, a2, a3;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            map[i][j] = MAXNUM;
    for (int i = 0; i < n; i++)
        nodesArr[i].id = i;
    for (int i = 0; i < m; i++)
    {
        cin >> a1 >> a2 >> a3;
        map[a1][a2] = a3;
        nodesArr[a2].indegree++;
    }
    queue<Node> Q;
    for (int i = 0; i < n; i++)
        if (nodesArr[i].indegree == 0)
            Q.push(nodesArr[i]);
    while (Q.size())
    {
        Node tmp = Q.front();
        Q.pop();
        count++;
        for (int i = 0; i < n; i++)
        {
            if (map[tmp.id][i] != MAXNUM)
            {
                nodesArr[i].total = max(nodesArr[i].total, nodesArr[tmp.id].total + map[tmp.id][i]);
                if (--nodesArr[i].indegree == 0)
                    Q.push(nodesArr[i]);
            }
        }
    }
    if (count < n)
        cout << "Impossible";
    else
    {
        for (int i = 0; i < n; i++)
            if (maxTotal < nodesArr[i].total)
                maxTotal = nodesArr[i].total;
        cout << maxTotal;
    }
    return 0;
}