// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)
#define START 0
using namespace std;
int n, myheap[1111];
vector<int> heapPath;
inline void output()
{
    for (int i = 0; i < heapPath.size(); i++)
        printf("%d%c", heapPath[i], i == heapPath.size() - 1 ? '\n' : ' ');
}
bool order(int id)
{
    if (n - 1 < id)
        return false;
    heapPath.push_back(myheap[id]);
    bool f1 = order(id * 2 + 2), f2 = order(id * 2 + 1);
    if (!f1 && !f2)
        output();
    heapPath.pop_back();
    return true;
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cin >> n;
    for (int i = 0; i < n; i++)
        scanf("%d", myheap + i);
    order(START);
    if (is_heap(myheap, myheap + n, greater<int>()))
        printf("Min Heap\n");
    else if (is_heap(myheap, myheap + n, less<int>()))
        printf("Max Heap\n");
    else
        printf("Not Heap\n");
    return 0;
}