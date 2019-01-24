// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct node
{
    int x = 0, y = 0, vis = 0;
}tmp;
node ori;
vector<node> cayman;
int n, d;
inline double distance(node a, node b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
void dfs(int i)
{
    cayman[i].vis = 1;
    if (50 - abs(cayman[i].x) <= d || 50 - abs(cayman[i].y) <= d)
    {
        printf("Yes");
        exit(0);
    }
    for (int j = 0; j < n; j++)
        if (!cayman[j].vis && distance(cayman[i], cayman[j]) <= d)
            dfs(j);
}
int main()
{
    vector<int> firstJump;
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &tmp.x, &tmp.y);
        cayman.push_back(tmp);
    }
    if (7.5 + d >= 50)
    {
        printf("Yes");
        return 0;
    }
    for (int i = 0; i < n; i++)
        if (distance(cayman[i], ori) <= d + 7.5)
            firstJump.push_back(i); // first jump
    for (int i = 0; i < firstJump.size(); i++)
        if (!cayman[firstJump[i]].vis)
            dfs(firstJump[i]);
    printf("No");
    return 0;
}