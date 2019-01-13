// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <map>
#include <string>
#define test() freopen("in", "r", stdin)

using namespace std;

map<string, int> table;

int main(int argc, char const *argv[])
{
    /* code */
    test();
    int N, K, M, tmp;
    char s[16];
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++)
    {
        scanf("%s%d",s, &tmp);
        tmp = tmp < K ? K : tmp;
        table[s] += tmp;
    }
    scanf("%d", &M);
    for(int i = 0; i < M; i++){
        scanf("%s",s);
        if(!table.count(s))
            printf("No Info\n");
        else printf("%d\n",table[s]);
    }

    return 0;
}