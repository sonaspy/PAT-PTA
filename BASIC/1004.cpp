// author -  newguo@sonaspy.cn
// coding - utf_8

#include<iostream>
#include<string>
#include<algorithm>
#define test freopen("in","r",stdin)

using namespace std;

struct Student
{
    char name[12];
    char id[12];
    int score;
} low, high;

bool cmp(struct Student A, struct Student B)
{
    return  A.score > B.score;
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n;
    cin >> n;
    Student records[n];
    for(int i = 0; i < n; i++)
        scanf("%s%s%d",records[i].name,records[i].id,&records[i].score);
    sort(records, records+n, cmp);
    printf("%s %s\n",records[0].name,records[0].id);
    printf("%s %s",records[n-1].name,records[n-1].id);
    return 0;
}