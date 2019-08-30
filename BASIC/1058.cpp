// author - sonaspy@outlook.com
// coding - utf_8

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define test() freopen("in", "r", stdin)

using namespace std;

struct Q
{
    int id = 0, point, items, fail_times;
    string ans;
} ques[101];

bool cmp(struct Q a, struct Q b)
{
    if (a.fail_times == b.fail_times)
        return a.id < b.id;
    return a.fail_times > b.fail_times;
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, m;
    cin >> n >> m;
    scanf("\n");
    for (int i = 0; i < m; i++)
        {
            string s;
            getline(cin, s);
            ques[i].id = i + 1;
            ques[i].point = s[0] - '0';
            ques[i].items = s[2] - '0';
            ques[i].ans = s.substr(4, s.size() - 4);
        }
    for (int i = 1; i <= n; i++)
        {
            string s;
            getline(cin, s);
            int sum = 0, c1, k = 0;
            for (int j = 0; j < s.size(); j++)
                {
                    if (s[j] == '(')
                        c1 = j;
                    else if (s[j] == ')')
                        {
                            if (s.substr(c1 + 1, j - c1 - 1) == ques[k].ans)
                                sum += ques[k].point;
                            else
                                ques[k].fail_times++;
                            k++;
                        }
                }
            cout << sum << endl;
        }
    sort(ques, ques + m, cmp);
    if (ques[0].fail_times == 0)
        cout << "Too simple";
    else
        {
            cout << ques[0].fail_times << " " << ques[0].id;
            for (int i = 1; i < m; i++)
                {
                    if (ques[i].fail_times == ques[0].fail_times)
                        cout << " " << ques[i].id;
                    else
                        break;
                }
        }
    return 0;
}