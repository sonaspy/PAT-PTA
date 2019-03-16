// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <vector>
#define test() freopen("in", "r", stdin)

using namespace std;

struct Campus
{
    string name;
    int total = 0, stu_num = 0, b_p = 0, a_p = 0, t_p = 0;
};

bool cmp(struct Campus a, struct Campus b)
{
    if (a.total == b.total)
        {
            if (a.stu_num == b.stu_num)
                return a.name < b.name;
            return a.stu_num < b.stu_num;
        }
    return a.total > b.total;
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n;
    unordered_map<string, Campus> mp;
    cin >> n;
    vector<Campus> vec;
    for (int i = 0; i < n; i++)
        {
            string s, s2;
            int p;
            cin >> s >> p >> s2;
            transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
            mp[s2].stu_num += 1;
            mp[s2].name = s2;
            if (s[0] == 'B')
                mp[s2].b_p += p;
            else if (s[0] == 'A')
                mp[s2].a_p += p;
            else
                mp[s2].t_p += p;
        }
    for (auto i : mp)
        {
            mp[i.first].total = int(i.second.b_p / 1.5 + i.second.a_p + i.second.t_p * 1.5);
            vec.push_back(mp[i.first]);
        }
    sort(vec.begin(), vec.end(), cmp);
    cout << vec.size() << endl;
    int rank = 1;
    printf("%d %s %d %d\n", rank, vec[0].name.c_str(), vec[0].total, vec[0].stu_num);
    for (int i = 1; i < vec.size(); i++)
        {
            if (vec[i].total != vec[i - 1].total)
                rank = i + 1;
            printf("%d %s %d %d\n", rank, vec[i].name.c_str(), vec[i].total, vec[i].stu_num);
        }
    return 0;
}