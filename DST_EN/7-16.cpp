// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>

#define test() freopen("in", "r", stdin)

using namespace std;

int n, t, cnt = 0, a[100002];
int main(int argc, char const *argv[])
{
    /* code */
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&t);
        a[t] = i;
    }
    for (int i = 0; i < n; i++)
        while (i != a[i])
        {
            while (a[0] != 0)
            {
                swap(a[0], a[a[0]]);
                cnt++;
            }
            if (i != a[i])
            {
                swap(a[0], a[i]);
                cnt++;
            }
        }
    cout << cnt;
    return 0;
}