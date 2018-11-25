#include <stdio.h> //无权图 bfs也可以
#include <queue>
#include <stack>
#include <math.h>
#include <vector>
#include <algorithm>
#define inf 9999999
using namespace std;
int head;
int n, d, flag, flag2 = 0;
int inq[101];
int path[101];
int layer[101];
struct node
{
    int x;
    int y;
} stu[101];
double dis(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}
void init()
{
    int i;
    flag = 0;
    for (i = 0; i < n; i++)
    {
        inq[i] = 0;
        path[i] = -1;
        layer[i] = 0;
    }
}
void bfs(int s)
{
    int i;
    inq[s] = 1;
    path[s] = -2;
    queue<int> q;
    q.push(s);
    layer[s] = 1;
    while (!q.empty())
    {
        head = q.front();
        q.pop();
        if (50 - abs(stu[head].x) <= d || 50 - abs(stu[head].y) <= d)
        {
            layer[head]++;
            flag = 1;
            flag2 = 1;
            break;
        }
        for (i = 0; i < n; i++)
        {
            if (inq[i] == 0 && dis(stu[head].x, stu[head].y, stu[i].x, stu[i].y) <= d)
            {
                path[i] = head;
                layer[i] = layer[head] + 1;
                inq[i] = 1;
                q.push(i);
            }
        }
    }
}
int main()
{
    int i;
    scanf("%d %d", &n, &d);
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &stu[i].x, &stu[i].y);
    }
    if (d >= 50 - 7.5)
    {
        printf("1");
        return 0;
    }
    int firstjump[n];
    int coufirst = 0;
    for (i = 0; i < n; i++)
    { //寻找第一跳
        if (d + 7.5 >= dis(stu[i].x, stu[i].y, 0, 0))
        {
            firstjump[coufirst++] = i;
        }
    }
    if (coufirst == 0)
    {
        printf("0");
        return 0;
    }
    int min = inf;
    vector<int> coumin;
    for (i = 0; i < coufirst; i++)
    {
        init();
        bfs(firstjump[i]);
        if (flag == 1)
        {
            if (layer[head] < min)
            {
                min = layer[head];
                coumin.clear();
                coumin.push_back(firstjump[i]);
            }
            else if (layer[head] == min)
            {
                coumin.push_back(firstjump[i]);
            }
        }
    }
    if (coumin.empty())
    {
        printf("0");
        return 0;
    }
    min = inf;
    int minindex;
    for (i = 0; i < coumin.size(); i++)
    {
        int index = coumin[i];
        if (min > dis(stu[index].x, stu[index].y, 0, 0) - 7.5)
        {
            min = dis(stu[index].x, stu[index].y, 0, 0) - 7.5;
            minindex = index;
        }
    }
    init();
    bfs(minindex);
    printf("%d\n", layer[head]);
    stack<int> s;
    do
    {
        s.push(head);
        head = path[head];
    } while (head != -2);
    while (!s.empty())
    {
        int temp = s.top();
        s.pop();
        printf("%d %d\n", stu[temp].x, stu[temp].y);
    }
}