// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define test() freopen("in", "r", stdin)
using namespace std;
struct Course
{
    int stu_num;
    vector<string> names;
} table[2502];
int main(int argc, char const *argv[])
{
    // test();
    int N, K, num, tmp;
    char s[5];
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++)
    {
        scanf("%s%d", s, &num);
        for (int j = 0; j < num; j++)
        {
            scanf("%d", &tmp);
            table[tmp].names.push_back(s);
            table[tmp].stu_num += 1;
        }
    }
    for (int i = 1; i <= K; i++)
    {
        sort(table[i].names.begin(), table[i].names.end());
        printf("%d %d\n", i, table[i].stu_num);
        for (auto iter : table[i].names)
            printf("%s\n", iter.c_str());
    }
    return 0;
}