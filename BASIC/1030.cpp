// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <algorithm>

#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
  //test();
    long n, p, num, a[100001];
    cin >> n >> p;
    for (int i = 0; i < n; i++)
        scanf("%ld", &a[i]);
    sort(a, a + n);
    int i = 0, j = n - 1;
    while(i!=j)
    {
        if (a[j] <= a[i] * p)
            break;
        if (a[i + 1] *a[j-1] > a[j] *a[i])
            i++;
        else j--;
    }
    cout << j-i+1;
    return 0;
}