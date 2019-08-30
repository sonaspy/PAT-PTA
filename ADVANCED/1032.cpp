// author -sonaspy@outlook.com
// coding - utf_8

#include <iostream>

#define test() freopen("in", "r", stdin)

using namespace std;

struct Node
{
    int next, vis = 0;
} node[100000];

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int src1, src2, n, pre, next;
    char c;
    cin >> src1 >> src2 >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %c %d", &pre, &c, &next);
        node[pre].next = next;
    }
    for (int i = src1; i != -1; i = node[i].next)
        node[i].vis = 1;
    for (int i = src2; i != -1; i = node[i].next)
        if (node[i].vis == 1)
        {
            printf("%05d", i);
            return 0;
        }
    cout << -1;
    return 0;
}