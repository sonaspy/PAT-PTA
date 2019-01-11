// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <algorithm>
#define test() freopen("in", "r", stdin)

using namespace std;

struct Country
{
    int id;
    int gold;
    int medal;
    int population;
    double av_g;
    double av_m;
    int range[4];
} countries[300];

struct Top
{
    int G[300],
        M[300],
        AV_G[300],
        AV_M[300];
} board;

bool cmp1(struct Country A, struct Country B)
{
    if(A.gold == B.gold)
        return A.id < B.id;
    return A.gold > B.gold;
}
bool cmp2(struct Country A, struct Country B)
{
    if(A.medal == B.medal)
        return A.id < B.id;
    return A.medal > B.medal;
}
bool cmp3(struct Country A, struct Country B)
{
    return A.av_g > B.av_g;
}
bool cmp4(struct Country A, struct Country B)
{
    return A.av_m > B.av_m;
}
bool cmp5(struct Country A, struct Country B)
{
    return A.id < B.id;
}
int main(int argc, char const *argv[])
{
    /* code */
    test();
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        countries[i].id = i;
        scanf("%d%d%d", &countries[i].gold, &countries[i].medal, &countries[i].population);
        countries[i].av_g = countries[i].gold * 1.0 / countries[i].population;
        countries[i].av_m = countries[i].medal * 1.0 / countries[i].population;
    }
    
    sort(countries, countries + N, cmp1);
    for (int i = 0; i < N; i++)
        board.G[i] = countries[i].id;
    sort(countries, countries + N, cmp2);
    for (int i = 0; i < N; i++)
        board.M[i] = countries[i].id;
    sort(countries, countries + N, cmp3);
    for (int i = 0; i < N; i++)
        board.AV_G[i] = countries[i].id;
    sort(countries, countries + N, cmp4);
    for (int i = 0; i < N; i++)
        board.AV_M[i] = countries[i].id;

    sort(countries, countries + N, cmp5);
    for (int i = 0; i < N; i++)
    {
        int walk;
        for (walk = 0; countries[i].id != board.G[walk]; walk++)
            ;
        countries[i].range[0] = walk+1;
        for (walk = 0; countries[i].id != board.M[walk]; walk++)
            ;
        countries[i].range[1] = walk+1;
        for (walk = 0; countries[i].id != board.AV_G[walk]; walk++)
            ;
        countries[i].range[2] = walk+1;
        for (walk = 0; countries[i].id != board.AV_M[walk]; walk++)
            ;
        countries[i].range[3] = walk+1;
    }

    int q, res, min_ , flag = 1;
    for (int i = 0; i < M; i++){
        scanf("%d", &q);
        min_ = 999;
        for(int j = 0; j < 4; j++){
            if(countries[q].range[j] < min_){
                min_ = countries[i].range[j];
                res = j+1;
            }
        }
        if(flag) {
            printf("%d:%d",min_,res);
            flag = 0;
        }
        else
            printf(" %d:%d",min_,res);
    }
    
    return 0;
}