// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

#define test() freopen("in", "r", stdin)

using namespace std;

unordered_map<string, vector<int>> table;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int N, K, s_num, c_id, course_num;
    cin >> N >> K;
    char tmp_name[5];
    for (int i = 1; i < K + 1; i++)
    {
        scanf("%d%d", &c_id, &s_num);
        for (int j = 0; j < s_num; j++)
        {
            scanf("%s", tmp_name);
            table[tmp_name].push_back(c_id);
        }
    }
    for (int i = 0; i < N; i++)
    {
        scanf("%s", tmp_name);
        vector<int> &c = table[tmp_name];
        sort(c.begin(), c.end());
        course_num = table[tmp_name].size();
        printf("%s %d", tmp_name, course_num);
        for (auto iter : c)
            printf(" %d", iter);
        printf("\n");
    }
    return 0;
}