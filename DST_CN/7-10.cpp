// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <map>
#define test() freopen("in", "r", stdin)

using namespace std;
int N, M, totalCost;
struct Edge
{
    int v1, v2, cost;
};
int unionset[1111];
multimap<int, Edge> mp;
void Build()
{
    cin >> N >> M;
    Edge e;
    fill(unionset, unionset + 1111, -1);
    for (int i = 0; i < M; i++)
    {
        scanf("%d%d%d", &e.v1, &e.v2, &e.cost);
        mp.insert(make_pair(e.cost, e));
    }
}
int findroot(int ele)
{
    return unionset[ele] == -1 ? ele : unionset[ele] = findroot(unionset[ele]);
}
inline void Unite(int a, int b)
{
    int ra = findroot(a), rb = findroot(b);
    unionset[rb] = ra;
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    Build();
    Edge E;
    int cnt = 0;
    for (auto &it : mp)
    {
        E = it.second;
        M--;
        int a = findroot(E.v1), b = findroot(E.v2);
        if (a != b)
            cnt++, Unite(a, b), totalCost += E.cost;
    }
    if (cnt < N - 1)
        cout << "-1";
    else
        cout << totalCost;
    return 0;
}