// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
int n, myheap[1111] = {0};
vector<int> path;
inline void output()
{
    for (int i = 0; i < path.size(); i++)
        printf("%d%c", path[i], i == path.size() - 1 ? '\n' : ' ');
}
bool order(int id)
{
    if (id >= n) return false;
    path.push_back(myheap[id]);
    bool f1 = order(id * 2 + 2), f2 = order(id * 2 + 1);
    if (!f1 && !f2) output();
    path.pop_back();
    return true;
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cin >> n;
    for (int i = 0; i < n; i++)
        scanf("%d", myheap + i);
    order(0);
    if (is_heap(myheap, myheap + n, greater<int>()))
        printf("Min Heap\n");
    else if (is_heap(myheap, myheap + n, less<int>()))
        printf("Max Heap\n");
    else
        printf("Not Heap\n");
    return 0;
}