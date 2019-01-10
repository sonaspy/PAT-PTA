// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <cstring>
#include <algorithm>

#define test() freopen("in", "r", stdin)
#define MAXN 100001
using namespace std;

struct Student
{
    char id[10];
    char name[10];
    int score;
};

Student Arr[MAXN];

bool cmp_1(Student A, Student B)
{
    return strcmp(A.id, B.id) < 0;
}
bool cmp_2(Student A, Student B)
{
    if (strcmp(A.name, B.name) != 0)
        return strcmp(A.name, B.name) < 0;
    else
        return strcmp(A.id, B.id) < 0;
}
bool cmp_3(Student A, Student B)
{
    if (A.score != B.score)
        return A.score < B.score;
    else
        return strcmp(A.id, B.id) < 0;
}

int main(int argc, char const *argv[])
{
    /* code */
    test();
    int N, C;
    cin >> N >> C;
    for (int i = 0; i < N; i++)
        scanf("%s%s%d", Arr[i].id, Arr[i].name, &Arr[i].score);
    switch (C)
    {
    case 1:
        sort(Arr, Arr + N, cmp_1);
        break;
    case 2:
        sort(Arr, Arr + N, cmp_2);
        break;
    case 3:
        sort(Arr, Arr + N, cmp_3);
        break;
    }
    for (int i = 0; i < N; i++)
        printf("%.6s %s %d\n", Arr[i].id, Arr[i].name, Arr[i].score);
    return 0;
}