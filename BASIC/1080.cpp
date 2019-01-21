// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#define test() freopen("in", "r", stdin)

using namespace std;

struct Student
{
    string id;
    int Gp = -1, Gm = -1, Gf = -1;
    double G;
};

bool cmp(struct Student a, struct Student b)
{
    if (a.G == b.G)
        return a.id < b.id;
    return a.G > b.G;
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int P, M, N, point;
    cin >> P >> M >> N;
    unordered_map<string, Student> mp;
    vector<Student> vec;
    string s;
    for (int i = 0; i < P; i++)
    {
        cin >> s >> point;
        mp[s].Gp = point;
        mp[s].id = s;
    }
    for (int i = 0; i < M; i++)
    {
        cin >> s >> point;
        mp[s].Gm = point;
        mp[s].id = s;
    }
    for (int i = 0; i < N; i++)
    {
        cin >> s >> point;
        mp[s].Gf = point;
        mp[s].id = s;
    }
    for (auto iter : mp)
    {
        if (iter.second.Gp < 200)
            continue;
        if (iter.second.Gm > iter.second.Gf)
            mp[iter.first].G = int(iter.second.Gf * 0.6 + iter.second.Gm * 0.4 + .5);
        else
            mp[iter.first].G = iter.second.Gf;
        if (mp[iter.first].G >= 60)
        {
            struct Student tmp;
            tmp = mp[iter.first];
            vec.push_back(tmp);
        }
    }

    sort(vec.begin(), vec.end(), cmp);
    for (auto i : vec)
        cout << i.id << " " << i.Gp << " " << i.Gm << " " << i.Gf << " " << i.G << endl;
    return 0;
}