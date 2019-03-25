// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <queue>
#include <numeric>

#define test() freopen("in", "r", stdin)
#define MAX_DATA 1 << 24
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, m, tmp, max = -1, res = 0;
    unordered_map<int, int> image;
    cin >> n >> m;
    for (int i = 0; i < n * m; i++)
    {
        scanf("%d", &tmp);
        if (tmp < MAX_DATA)
            ++image[tmp];
    }
    for (auto i : image)
    {
        if (i.second > max)
        {
            max = i.second;
            res = i.first;
        }
    }
    cout << res;
    return 0;
}