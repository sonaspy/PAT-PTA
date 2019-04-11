// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <vector>
#include <cmath>
#define test() freopen("in", "r", stdin)
#define RADIUS (7.5)
using namespace std;
struct Node
{
    int x = 0, y = 0, vis = 0;
} center;
int n, d, _min_step = 1 << 30, tmp_step = 1;
vector<Node> croc, firstjump, ansPath, tmpPath;
bool could = false, resstart = false;

inline double getDist(Node a, Node b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void DFS(Node &i)
{
    if (resstart)
    {
        resstart = false;
        tmpPath.clear();
        tmp_step = 1;
    }
    i.vis = 1;
    tmp_step++;
    tmpPath.push_back(i);
    if (50 - abs(i.x) <= d || 50 - abs(i.y) <= d)
    {
        could = true;
        if (tmp_step < _min_step)
        {
            _min_step = tmp_step;
            ansPath = tmpPath;
        }
        else if (tmp_step == _min_step && getDist(tmpPath.front(), center) < getDist(ansPath.front(), center))
            ansPath = tmpPath;
        return;
    }
    for (auto &j : croc)
        if (!j.vis && getDist(i, j) <= d)
        {
            DFS(j);
            tmp_step--;
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
        croc.push_back(tmp);
    }
    if (d + RADIUS >= 50)
    {
        cout << 1;
        return 0;
    }
    for (auto &i : croc)
    {
        if (getDist(i, center) <= d + RADIUS)
            firstjump.push_back(i);
    }
    for (auto &i : firstjump)
    {
        if (!i.vis)
        {
            resstart = true;
            DFS(i);
        }
    }
    if (!could)
    {
        cout << 0;
        return 0;
    }
    cout << _min_step << endl;
    for (auto i : ansPath)
        cout << i.x << " " << i.y << endl;
    return 0;
}