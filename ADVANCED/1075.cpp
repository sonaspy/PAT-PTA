// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
struct Student
{
    int id, total, scores[10], perfect;
    Student()
    {
        id = 0, total = 0, perfect = 0;
        fill(scores, scores + 10, -2);
    }
    bool operator<(const Student &b) const
    {
        return total != b.total ? total > b.total : perfect != b.perfect ? perfect > b.perfect : id < b.id;
    }
};

int n, m, k, scores[10], user_id, pro_id, p_s;
void output(Student &p)
{
    for (int i = 1; i <= k; i++)
    {
        if (p.scores[i] == -2)
            printf(" -");
        else if (p.scores[i] == -1)
            printf(" 0");
        else
            printf(" %d", p.scores[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    unordered_map<int, Student> mp;
    cin >> n >> k >> m;
    vector<Student> v;
    for (int i = 1; i <= k; i++)
        cin >> scores[i];
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &user_id, &pro_id, &p_s);
        mp[user_id].id = user_id;
        if (p_s > mp[user_id].scores[pro_id])
            mp[user_id].scores[pro_id] = p_s;
    }
    for (auto i : mp)
    {
        bool valid = false;
        for (int j = 1; j <= k; j++)
        {
            if (i.second.scores[j] > -1)
            {
                i.second.total += i.second.scores[j];
                valid = true;
            }
            if (i.second.scores[j] == scores[j])
                i.second.perfect++;
        }
        if (valid)
            v.push_back(i.second);
    }
    sort(v.begin(), v.end());
    int rank = 1;
    printf("%d %05d %d", rank, v[0].id, v[0].total);
    output(v[0]);
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i].total != v[i - 1].total)
            rank = i + 1;
        printf("%d %05d %d", rank, v[i].id, v[i].total);
        output(v[i]);
    }
    return 0;
}