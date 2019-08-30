// author - sonaspy@outlook.com
// coding - utf_8

#include<iostream>
#include<vector>
#include <algorithm>
#include<string.h>
#define test() freopen("in","r",stdin)

using namespace std;

struct Node
{
    int id = 0, total = 0;
} nodes[1001];

bool cmp(struct Node A, struct Node B)
{
    return A.total > B.total;
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, score, id;
    cin >>n;
    const char *sep  = "-";
    char s[10], *s1;
    for(int i = 0; i < n ; i++)
        {
            scanf("%s%d",s,&score);
            s1 = strtok(s, sep);
            id = atoi(s1);
            nodes[id].id = id;
            nodes[id].total += score;
        }
    sort(nodes, nodes+1001,cmp);
    cout << nodes[0].id << " " << nodes[0].total;
    return 0;
}