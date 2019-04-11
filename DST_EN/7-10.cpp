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
int n, d;
vector<Node> croc, firstjump;

inline double getDist(Node a, Node b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void DFS(Node &i)
{
    i.vis = 1;
    if (50 - abs(i.x) <= d || 50 - abs(i.y) <= d)
    {
        printf("Yes");
        exit(0);
    }
    for (auto &j : croc)
        if (!j.vis && getDist(i, j) <= d)
            DFS(j);
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cin >> n >> d;
    croc.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> croc[i].x >> croc[i].y;
    }
    if (d + RADIUS >= 50)
    {
        printf("Yes\n");
        return 0;
    }
    for (auto &i : croc)
    {
        if (getDist(i, center) <= d + RADIUS)
            firstjump.push_back(i);
    }
    for (auto &i : firstjump)
        if (!i.vis)
            DFS(i);
    printf("No");
    return 0;
}