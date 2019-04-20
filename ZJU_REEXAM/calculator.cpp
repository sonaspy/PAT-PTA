// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

string s, s1;
double ans;
vector<string> v;
unordered_map<char, int> mp;

inline void func()
{
    stringstream ss(s);
    stack<string> sk;
    stack<double> nums;
    v.clear();
    while (ss >> s1)
    {
        if (isdigit(s1[0]))
        {
            v.push_back(s1);
        }
        else
        {
            if (sk.empty() || (mp[s1[0]] > mp[sk.top()[0]]))
            {
                sk.push(s1);
            }
            else
            {
                while (sk.size() && mp[sk.top()[0]] >= mp[s1[0]])
                {
                    v.push_back(sk.top());
                    sk.pop();
                }
                sk.push(s1);
            }
        }
    }
    while (sk.size())
    {
        v.push_back(sk.top());
        sk.pop();
    }
    for (auto i : v)
    {
        if (isdigit(i[0]))
            nums.push(stod(i));
        else
        {
            double n1 = nums.top();
            nums.pop();
            double n2 = nums.top();
            nums.pop();
            if (i == "+")
                nums.push(n1 + n2);
            else if (i == "-")
                nums.push(n2 - n1);
            else if (i == "*")
                nums.push(n1 * n2);
            else if (i == "/")
                nums.push(n2 * 1.0 / n1);
        }
    }
    ans = nums.top();
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    mp['-'] = 1, mp['+'] = 1, mp['*'] = 2, mp['/'] = 2;
    while (getline(cin, s) && s != "0")
    {
        func();
        printf("%.2f\n", ans);
    }
    return 0;
}