// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct node
{
    double x = 0, y = 0;
    int vis = 0;
};
node ori;
vector<node> map_cro;
int n;
double d;
double fdis(node a, node b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
void dfs(int i)
{
    map_cro[i].vis = 1;
    if (50 - abs(map_cro[i].x) <= d || 50 - abs(map_cro[i].y) <= d)
    {
        puts("Yes");
        exit(0);
    }
    for (int j = 0; j < n; j++)
        if (!map_cro[j].vis && fdis(map_cro[i], map_cro[j]) <= d)
            dfs(j);
}
int main()
{
    node nd;
    vector<int> vid;
    scanf("%d%lf", &n, &d);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf%lf", &nd.x, &nd.y);
        nd.vis = 0;
        map_cro.push_back(nd);
    }
    if (7.5 + d >= 50)
    {
        puts("Yes");
        return 0;
    }
    for (int i = 0; i < n; i++)
        if (fdis(map_cro[i], ori) <= d + 7.5)
            vid.push_back(i); // first jump
    for (int i = 0; i < vid.size(); i++)
        if (!map_cro[vid[i]].vis)
            dfs(vid[i]);
    puts("No");
    return 0;
}