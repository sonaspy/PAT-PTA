// author -  newguo@sonaspy.cn
// coding - utf_8

#include<iostream>
#include<algorithm>
#define test() freopen("in","r",stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int N, M, richer[1000001];
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        scanf("%d",&richer[i]);
    sort(richer,richer+N,greater<int>());
    printf("%d",richer[0]);
    if(N >= M)
        {
            for(int i = 1; i < M; i++)
                printf(" %d", richer[i]);
        }
    else
        {
            for (int i = 1; i < N; i++)
                printf(" %d", richer[i]);
        }
    return 0;
}