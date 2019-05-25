// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <algorithm>
#include <cstring>
#define test() freopen("in", "r", stdin)

using namespace std;

struct Student
{
    int id, grade;
    char name[20];
};
bool cmp1(Student a, Student b) { return a.id < b.id; }
bool cmp2(Student a, Student b) { return strcmp(a.name, b.name) == 0 ? a.id < b.id : strcmp(a.name, b.name) < 0; }
bool cmp3(Student a, Student b) { return a.grade == b.grade ? a.id < b.id : a.grade < b.grade; }

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, m;
    Student list[100001];
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        scanf("%d%s%d", &list[i].id, list[i].name, &list[i].grade);
    m == 1 ? (sort(list, list + n, cmp1)) : m == 2 ? (sort(list, list + n, cmp2)) : (sort(list, list + n, cmp3));
    for (int i = 0; i < n; i++)
        printf("%06d %s %d\n", list[i].id, list[i].name, list[i].grade);
    return 0;
}