// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>

#define test() freopen("in", "r", stdin)

using namespace std;

struct Question
{
    int point, all;
    unordered_set<char> ans;
};

struct Node
{
    int fail_t;
    string fix;
};

bool cmp(struct Node a, struct Node b)
{
    if (a.fail_t == b.fail_t)
        return a.fix < b.fix;
    return a.fail_t > b.fail_t;
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int stu_n, que_n, a1, a2, a3;
    char c;
    cin >> stu_n >> que_n;
    unordered_map<string, int> mp;
    vector<Node> vec;
    struct Question ques[que_n + 1];
    for (int i = 1; i <= que_n; i++)
    {
        cin >> a1 >> a2 >> a3;
        struct Question tmp;
        tmp.point = a1, tmp.all = a2;
        for (int j = 0; j < a3; j++)
        {
            cin >> c;
            tmp.ans.insert(c);
        }
        ques[i] = tmp;
    }
    getchar();
    for (int i = 1; i <= stu_n; i++)
    {
        string s, s1;
        getline(cin, s);
        int c1, k = 1;
        double total = 0.0;
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == '(')
                c1 = j;
            else if (s[j] == ')')
            {
                string ss = s.substr(c1 + 1, j - c1 - 1);
                unordered_set<char> s1;
                bool flag = true;
                for (int i = 0; i < ss.size(); i++)
                    if (ss[i] != ' ' && !isdigit(ss[i]))
                        s1.insert(ss[i]);
                for (auto iter : s1)
                {
                    if (!(ques[k].ans.count(iter)))
                    {
                        flag = false;
                        string s2;
                        s2.push_back((k + '0'));
                        s2.push_back('-');
                        s2.push_back(iter);
                        mp[s2] += 1;
                    }
                }
                for (auto iter : ques[k].ans)
                {
                    if (!(s1.count(iter)))
                    {
                        if(s1.size() >= ques[k].ans.size())
                            flag = false;
                        string s2;
                        s2.push_back((k + '0'));
                        s2.push_back('-');
                        s2.push_back(iter);
                        mp[s2] += 1;
                    }
                }
                if (flag == true)
                    total += (s1.size() == ques[k].ans.size() ? ques[k].point * 1.0 : ques[k].point * 0.5);
                k++;
            }
        }
        printf("%.1lf\n", total);
    }
    for (auto i : mp)
    {
        struct Node tp;
        tp.fail_t = i.second;
        tp.fix = i.first;
        vec.push_back(tp);
    }
    if (vec.size() == 0)
    {
        cout << "Too simple" << endl;
    }
    else
    {
        sort(vec.begin(), vec.end(), cmp);
        for (int i = 0; i < vec.size(); i++)
        {
            if (vec[i].fail_t != vec[0].fail_t)
                break;
            else
                cout << vec[i].fail_t << " " << vec[i].fix << endl;
        }
    }
    return 0;
}