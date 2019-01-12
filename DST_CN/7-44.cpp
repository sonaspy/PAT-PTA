// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <set>
#include <string>
#define test() freopen("in", "r", stdin)
#define MAXN 1111
using namespace std;

void solve(string &s, set<string> &f_content)
{
    for (int i = s.size() - 1; i > -1; i--)
    {
        if (isalpha(s[i]))
        {
            s.erase(i + 1, s.size());
            break;
        }
    }
    s.push_back('!'); // add a non-alpha guard.
    while (s.size() != 1)
    {
        int i;
        for (i = 0; i < s.size(); i++)
        {
            if (isalpha(s[i]))
            {
                s.erase(0, i);
                break;
            }
        }
        if (i == s.size() && !isalpha(s[i - 2])) // above for loop's break does not implement. the string has no alpha.
            return;
        for (i = 0; i < s.size(); i++)
        {
            if (!isalpha(s[i]))
            {
                string tmp = s.substr(0, i);
                if (i > 10)
                    tmp = tmp.substr(0, 10);
                if (i > 2)
                    f_content.insert(tmp);
                s.erase(0, i);
                break;
            }
            else
                s[i] = towlower(s[i]);
        }
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    test();
    int N, M;
    cin >> N;
    set<string> f_content[MAXN];
    for (int i = 1; i <= N; i++)
    {
        while (true)
        {
            string s;
            cin >> s;
            if (s == "#" && s.size() == 1)
                break;
            solve(s, f_content[i]);
        }
    }
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int f1, f2, share = 0;
        scanf("%d%d", &f1, &f2);
        for (auto ptr : f_content[f1])
        {
            if (f_content[f2].count(ptr))
                share++;
        }
        printf("%.1f%%\n", share * 100.0 / (f_content[f1].size() + f_content[f2].size() - share));
    }
    return 0;
}