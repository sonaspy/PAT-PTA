// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include<string.h>
#include<algorithm>
#define test() freopen("in", "r", stdin)

using namespace std;

void insert(int *&a, int data, int cur)
{
    if (a[cur] == 0)
    {
        a[cur] = data;
        return;
    }
    if (data < a[cur])
        insert(a, data, 2 * cur + 1);
    if (data > a[cur])
        insert(a, data, 2 * cur + 2);
}

int main(int argc, char const *argv[])
{
    /* code */
    int *a = new int[10];
    fill(a, a+10,0);
    a[0] = 10;
    insert(a, 100, 0);
    cout << a[2];
    return 0;
}