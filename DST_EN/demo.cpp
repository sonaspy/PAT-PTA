// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include<string.h>
#include<algorithm>
#include<vector>
#include<regex>
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
    

    return 0;
}