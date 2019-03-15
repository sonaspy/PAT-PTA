// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>

#define test() freopen("in", "r", stdin)

using namespace std;

struct Node
{
    int next, flag = 0;
} node[100000];

int main(int argc, char const *argv[])
{
    /* code */
    test();
    int st1, st2, n, pre, next;
    char c;
    cin >> st1 >> st2 >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %c %d",&pre,&c,&next);
        node[pre].next = next;
    }
    for(int i = st1; i != -1; i = node[i].next)
        node[i].flag = 1;
    for(int i = st2; i != -1; i = node[i].next)
        if(node[i].flag == 1){
            printf("%05d",i);
            return 0;
        }
    cout << -1;
    return 0;
}