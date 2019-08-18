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

inline double getDist(Node a, Node b) { return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)); }

void DFS(Node &id)
{
    id.vis = 1;
    if (50 <= d + abs(id.x) || 50 <= d + abs(id.y))
    {
        printf("Yes");
        exit(0);
    }
    for (auto &w : croc)
        if (!w.vis && getDist(id, w) <= d)
            DFS(w);
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cin >> n >> d;
    croc.resize(n);
    for (int id = 0; id < n; id++)
        cin >> croc[id].x >> croc[id].y;
    if (d + RADIUS >= 50)
    {
        printf("Yes\n");
        return 0;
    }
    for (auto &id : croc)
    {
        if (getDist(id, center) <= d + RADIUS)
            firstjump.push_back(id);
    }
    for (auto &id : firstjump)
        if (!id.vis)
            DFS(id);
    printf("No");
    return 0;
}