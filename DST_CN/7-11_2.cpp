#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <algorithm>

int **input; //The input order of the activity v -> w, using in the compare function

bool compare(pair<int, int> a, pair<int, int> b)
{
    return  a.first != b.first ? \
            a.first < b.first : \
            input[a.first][a.second] > input[b.first][b.second];
}

void top_sort(int **time, int *inDegree, int *outDegree, int n)
{
    queue<int> q;
    int count = 0;
    for (int i = 0; i < n; i++)
        if (!inDegree[i])
        {
            q.push(i);
            count++;
        }
    int *earliest = new int[n]; //The earliest starting time of each vertex 每个顶点的最早开始时间
    fill(earliest, earliest + n, 0);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int w = 0; w < n; w++)
            if (time[v][w] != -1)
            { //An activity of v-> w exists
                /* If the earliest starting time of v + time[v][w] larger than the starting time of
                w, then w can not start so early. */
                if (earliest[v] + time[v][w] > earliest[w])
                    earliest[w] = earliest[v] + time[v][w];
                if (--inDegree[w] == 0){
                    count++;
                    q.push(w);
                }
            }
    }
    if (count != n)
    { //loop exists
        cout << 0 << endl;
        return;
    }
    int max = 0;
    for (int v = 0; v < n; v++)
        if (earliest[v] > max)
            max = earliest[v];
    cout << max << endl;
    vector<pair<int, int> > keyActivies;
    int *latest = new int[n]; //The latest ending time of each vertex 每个顶点的最晚结束时间
    fill(latest, latest + n, max);
    for (int v = 0; v < n; v++)
        if (!outDegree[v])
            q.push(v);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int w = 0; w < n; w++)
            if (time[w][v] != -1)
            { //Activity of w -> v exists
                /*If the latest ending time of v - time[w][v] smaller than the ending time of
                w, then w can not end so late. */
                int val = latest[v] - time[w][v];
                if (val < latest[w])
                    latest[w] = val;
                if (val  == earliest[w])
                    keyActivies.push_back({w, v}); //w->v is a key activity
                if (--outDegree[w] == 0)
                    q.push(w);
            }
    }
    sort(keyActivies.begin(), keyActivies.end(), compare);
    for (auto it = keyActivies.begin(); it != keyActivies.end(); it++)
        printf("%d->%d\n", it->first + 1, it->second + 1);
}

int main()
{
    int n, m;
    cin >> n >> m;
    //AOE graph 活动在边上
    int *inDegree = new int[n];  //入度
    int *outDegree = new int[n]; //出度
    int **time = new int *[n];   //The lasting time of the activity v -> w
    input = new int *[n];        //The input order of the activity v -> w
    for (int i = 0; i < n; i++)
    {
        inDegree[i] = outDegree[i] = 0;
        time[i] = new int[n];
        input[i] = new int[n];
        for (int j = 0; j < n; j++)
            time[i][j] = input[i][j] = -1; //Initialize
    }
    for (int i = 0; i < m; i++)
    { //Inserts Edge(activities)
        int v, w, t;
        cin >> v >> w >> t;
        v--;w--;
        time[v][w] = t;
        input[v][w] = i; //Input order 输入顺序，输出时需要此顺序
        inDegree[w]++;
        outDegree[v]++;
    }
    top_sort(time, inDegree, outDegree, n);
    return 0;
}
