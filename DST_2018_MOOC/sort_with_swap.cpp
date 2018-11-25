#include <iostream>
using namespace std;
int main()
{
    int i, t, n, a[100000];
    int circle = 0, flag = 0, count = 0;
    cin >> n;
    for (i = 0; i < n; i++)
     cin >> a[i];
    if (a[0] == 0)
        flag = 1; //判断0是否在某一个环内

    for (i = 0; i < n; i++)
        if (a[i] != i)
        {
            circle++; //环的数量（不包括仅有一个元素的环）
            while (a[i] != i)
            {
                t = a[i];
                a[i] = i;
                i = t;
                count++; //所有环的元素数量和
            }
        }
        
    if (flag)
        cout << circle + count;
    else
        cout <<  circle - 1 + count - 1;
    return 0;
}