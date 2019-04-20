// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
int id, t, hh, mm, sum_times;
double aver;
char op;
struct Node
{
    int id, t, rent;
    bool operator<(const Node &b) const
    {
        return id < b.id;
    }
};
vector<Node> v;
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    while (scanf("%d %c %d:%d", &id, &op, &hh, &mm) && id != -1)
    {
        if (id == 0)
        {
            int n = v.size();
            stable_sort(v.begin(), v.end());
            for (int i = 0; i < n - 1; i++)
            {
                if (v[i].id == v[i + 1].id && v[i].rent == 1 && v[i + 1].rent == 0)
                {
                    sum_times++;
                    aver += v[i + 1].t - v[i].t;
                    i++;
                }
            }
            int var = sum_times == 0 ? 0 : (aver * 1.0 / sum_times) + 0.5;
            printf("%d %d\n", sum_times, var);
            v.clear();
            aver = 0;
            sum_times = 0;
            continue;
        }
        if (op == 'S')
            v.push_back({id, hh * 60 + mm, 1});
        else
            v.push_back({id, hh * 60 + mm, 0});
    }

    return 0;
}