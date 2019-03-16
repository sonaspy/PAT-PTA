// author -  newguo@sonaspy.cn
// coding - utf_8

#include<iostream>
#include<vector>
#include<cmath>
#define test() freopen("in","r",stdin)

using namespace std;
struct Node
{
    int x = 0, y = 0, vis = 0;
} tmp, o;
int n, d;
vector<int> firstjump;
vector<Node> cayman;

inline double distance( Node a, Node b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void DFS(int i)
{
    cayman[i].vis =1;
    if (50 - abs(cayman[i].x) <= d || 50 - abs(cayman[i].y) <= d)
        {
            printf("Yes");
            exit(0);
        }
    for(int j = 0; j < n; j++)
        if(!cayman[j].vis && distance(cayman[i], cayman[j]) <= d)
            DFS(j);
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cin >> n >> d;
    for(int i = 0; i < n; i++)
        {
            cin >> tmp.x >> tmp.y;
            cayman.push_back(tmp);
        }
    if(d+7.5 >= 50)
        {
            printf("Yes\n");
            return 0;
        }
    for (int i = 0; i < n; i++)
        if(distance(o, cayman[i]) <= 7.5 + d)
            firstjump.push_back(i);
    for(int i = 0; i < firstjump.size(); i++)
        if(!cayman[firstjump[i]].vis)
            DFS(firstjump[i]);
    printf("No");
    return 0;
}