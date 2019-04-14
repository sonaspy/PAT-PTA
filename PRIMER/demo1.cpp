// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
void knuth(int n, int m)
{
    srand((unsigned int)time(0));
    for (int i = 0; i < n; i++)
    {
        int num = rand() % (n - i);
        if (num < m)
        {
            cout << i << endl;
            (m--);
        }
    }
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int *p1 = new int[10];
    int *p2 = new int[10]();
    knuth(1000, 10);
    return 0;
}