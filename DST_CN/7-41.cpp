// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <cstring>
#include <algorithm>
#define test() freopen("in", "r", stdin)
using namespace std;
typedef struct node
{
    char id[15];
    int rank_all;
    int score;
    int center_id;
    int rank_in;
} Students;
int cmp(Students a, Students b)
{
    if (a.score != b.score)
        return a.score > b.score;
    else
        return strcmp(a.id,b.id) < 0;
}

int main(int argc, char const *argv[])
{
    /* code */
    test();
    int N, x = 0;
    cin >> N;
    Students _stu[30001];
    for (int j = 1; j <= N; j++)
    {
        int K;
        cin >> K;
        for (int i = 0; i < K; i++)
        {
            scanf("%s%d",_stu[x+i].id, &_stu[x+i].score);
            _stu[x + i].center_id = j;
        }
        sort(_stu + x, _stu + x + K, cmp);
        _stu[x].rank_in = 1;
        for (int i = 1; i < K; i++)
        {
            if (_stu[x + i].score == _stu[x + i - 1].score)
                _stu[x + i].rank_in = _stu[x + i - 1].rank_in;
            else
                _stu[x + i].rank_in = i + 1;
        }
        x += K;
    }
    sort(_stu, _stu + x, cmp);
    _stu[0].rank_all = 1;
    cout << x << endl;
    for (int i = 1; i < x; i++)
    {
        if (_stu[i].score == _stu[i - 1].score)
            _stu[i].rank_all = _stu[i - 1].rank_all;
        else
            _stu[i].rank_all = i + 1;
    }
    for (int i = 0; i < x; i++)
        printf("%s %d %d %d\n", _stu[i].id, _stu[i].rank_all, _stu[i].center_id, _stu[i].rank_in);
}