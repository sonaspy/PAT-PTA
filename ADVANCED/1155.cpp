// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)
#define ROOT 0
using namespace std;
int n, arr[1111];
vector<int> path;
bool traversal(int id)
{
    if (n - 1 < id)
        return false;
    path.push_back(arr[id]);
    bool f1 = traversal(id * 2 + 2), f2 = traversal(id * 2 + 1);
    if (!f1 && !f2)
        for (int i = 0; i < path.size(); i++)
            printf("%d%c", path[i], i == path.size() - 1 ? '\n' : ' ');
    path.pop_back();
    return true;
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cin >> n;
    for (int i = 0; i < n; i++)
        scanf("%d", arr + i);
    traversal(ROOT);
    if (is_heap(arr, arr + n, greater<int>()))
        printf("Min Heap\n");
    else if (is_heap(arr, arr + n, less<int>()))
        printf("Max Heap\n");
    else
        printf("Not Heap\n");
    return 0;
}