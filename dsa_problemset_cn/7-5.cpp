// author -sonaspy@outlook.com
// coding - utf_8

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //freopen("in","r",stdin);
    int N, M, idx, var, flag;
    cin >> N >> M;
    vector<int> minheap(N);
    for (int i = 0; i < N; i++)
    {
        cin >> minheap[i];
        make_heap(minheap.begin(), minheap.begin() + i + 1, greater<int>());
    }
    while (M--)
    {
        flag = 1;
        cin >> idx;
        idx--;
        for (; true; idx = (idx - 1) / 2)
        {
            if (flag)
            {
                cout << minheap[idx];
                flag = 0;
            }
            else
                cout << " " << minheap[idx];
            if (idx == 0)
                break;
        }
        cout << endl;
    }
    return 0;
}