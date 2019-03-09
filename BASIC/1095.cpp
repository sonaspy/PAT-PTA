// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define test() freopen("in", "r", stdin)

using namespace std;

struct Node
{
    string id;
    int point;
};
bool cmp(struct Node a, struct Node b)
{
    if (a.point == b.point)
        return a.id < b.id;
    return a.point > b.point;
}
struct ExamRoom
{
    int stu_num = 0, total = 0, id;
};
bool cmp1(struct ExamRoom a, struct ExamRoom b)
{
    if (a.stu_num == b.stu_num)
        return a.id < b.id;
    return a.stu_num > b.stu_num;
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int N, M;
    cin >> N >> M;
    unordered_map<char, vector<Node>> instruction1_map;
    unordered_map<int, ExamRoom> instruction2_map;
    unordered_map<string, unordered_map<int, ExamRoom>> instruction3_map_meta;
    unordered_map<string, vector<ExamRoom>> instruction3_map;
    for (int i = 0; i < N; i++)
        {
            struct Node node;
            string s;
            int point;
            cin >> s >> point;
            node.id = s;
            node.point = point;
            instruction1_map[s[0]].push_back(node);
            int room = stoi(s.substr(1, 3));
            instruction2_map[room].stu_num += 1;
            instruction2_map[room].total += point;
            string date = s.substr(4, 6);
            instruction3_map_meta[date][room].stu_num += 1;
            instruction3_map_meta[date][room].total += point;
            instruction3_map_meta[date][room].id = room;
        }
    for (auto i : instruction1_map)
        sort(instruction1_map[i.first].begin(), instruction1_map[i.first].end(), cmp);
    for (auto i : instruction3_map_meta)
        {
            for (auto j : i.second)
                instruction3_map[i.first].push_back(j.second);
        }
    for (auto i : instruction3_map)
        sort(instruction3_map[i.first].begin(), instruction3_map[i.first].end(), cmp1);
    for (int i = 1; i <= M; i++)
        {
            int ins;
            cin >> ins;
            if (ins == 1)
                {
                    char c;
                    cin >> c;
                    printf("Case %d: 1 %c\n", i, c);
                    if (!instruction1_map.count(c))
                        printf("NA\n");
                    else
                        for (auto iter : instruction1_map[c])
                            printf("%s %d\n", iter.id.c_str(), iter.point);
                }
            else if (ins == 2)
                {
                    int id;
                    cin >> id;
                    printf("Case %d: 2 %d\n", i, id);
                    if (!instruction2_map.count(id))
                        printf("NA\n");
                    else
                        printf("%d %d\n", instruction2_map[id].stu_num, instruction2_map[id].total);
                }
            else
                {
                    string date;
                    cin >> date;
                    printf("Case %d: 3 %s\n", i, date.c_str());
                    if (!instruction3_map.count(date))
                        printf("NA\n");
                    else
                        for (auto iter : instruction3_map[date])
                            printf("%d %d\n", iter.id, iter.stu_num);
                }
        }
    return 0;
}