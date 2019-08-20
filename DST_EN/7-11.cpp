// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)
#define RADIUS (7.5)
using namespace std;
struct Node
{
    int x = 0, y = 0, vis = 0;
} center;
int n, d, minstep = INT_MAX, step;
vector<Node> Crocs, firstjump, ansPath, tmpPath;
bool soluable = false;

inline double getDist(Node &a, Node &b) { return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)); }

void DFS(Node &i)
{
    i.vis = 1;
    step++;
    tmpPath.push_back(i);
    if (50 - abs(i.x) <= d || 50 - abs(i.y) <= d)
    {
        soluable = true;
        if (step < minstep)
        {
            minstep = step;
            ansPath = tmpPath;
        }
        else if (step == minstep && getDist(tmpPath.front(), center) < getDist(ansPath.front(), center))
            ansPath = tmpPath;
        return;
    }
    for (auto &j : Crocs)
        if (!j.vis && getDist(i, j) <= d)
        {
            DFS(j);
            step--;
            tmpPath.pop_back();
            j.vis = 0;
        }
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cin >> n >> d;
    for (int i = 0; i < n; i++)
    {
        Node tmp;
        cin >> tmp.x >> tmp.y;
        Crocs.push_back(tmp);
    }
    if (d + RADIUS >= 50)
    {
        cout << 1;
        return 0;
    }
    for (auto &i : Crocs)
    {
        if (getDist(i, center) <= d + RADIUS)
            firstjump.push_back(i);
    }
    for (auto &i : firstjump)
    {
        if (!i.vis)
        {
            tmpPath.clear();
            step = 1;
            DFS(i);
        }
    }
    if (!soluable)
    {
        cout << 0;
        return 0;
    }
    cout << minstep << endl;
    for (auto i : ansPath)
        cout << i.x << " " << i.y << endl;
    return 0;
}