// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
typedef struct Student *pstu;
struct Student
{
    string name, id;
    int grade;
    Student(char *n, char *i, int g) : name(n), id(i), grade(g) {}
};
bool cmp(const pstu a, const pstu b)
{
    return a->grade > b->grade;
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, g1, g2, g;
    cin >> n;
    vector<pstu> stus, res;
    for (int i = 0; i < n; i++)
    {
        char name[12], id[12];
        scanf("%s %s %d", name, id, &g);
        stus.push_back(new Student(name, id, g));
    }
    cin >> g1 >> g2;
    for (auto i : stus)
    {
        if (i->grade >= g1 && i->grade <= g2)
            res.push_back(i);
    }
    if (res.empty())
    {
        cout << "NONE";
        return 0;
    }
    sort(res.begin(), res.end(), cmp);
    for (auto i : res)
        printf("%s %s\n", i->name.c_str(), i->id.c_str());

    return 0;
}