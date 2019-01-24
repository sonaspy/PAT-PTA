// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <algorithm>
#define test() freopen("in", "r", stdin)

using namespace std;

int arr[1111], CBT[1111], ind = 0, n;

void inOrder(int root)
{
    if (n < root)
        return;
    inOrder(root * 2);
    CBT[root] = arr[ind++];
    inOrder(root * 2 + 1);
}

int main(int argc, char const *argv[])
{
    /* code */
    test();
    cin >> n;
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    sort(arr, arr + n);
    inOrder(1);
    for(int i =1; i <= n; i++)
    {
        cout << CBT[i];
        if(i != n) cout << " ";
    }
    return 0;
}