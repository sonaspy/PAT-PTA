
// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#define test() freopen("in", "r", stdin)
using namespace std;
int main(int argc, char const *argv[])
{
    /* code */
    int arr[200005], n, m, temp, current_rank = -1;
    cin >> n;
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    arr[n] = 1 << 30;
    cin >> m;
    int midpos = (n + m - 1) / 2, arr_cur = 0;
    for (int j = 0; j < m; j++)
    {
        scanf("%d", &temp);
        while (arr[arr_cur] < temp)
        {
            current_rank++;
            if (current_rank == midpos)
                cout << arr[arr_cur];
            arr_cur++;
        }
        current_rank++;
        if (current_rank == midpos)
            cout << temp;
    }
    while (arr_cur < n)
    {
        current_rank++;
        if (current_rank == midpos)
            cout << arr[arr_cur];
        arr_cur++;
    }
    return 0;
}