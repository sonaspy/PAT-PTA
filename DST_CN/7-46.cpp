// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <set>
#include <string>
#include <map>
#include <algorithm>
#define test() freopen("in", "r", stdin)

using namespace std;
struct topic
{
    string t_name;
    int times;
} records[100000];

bool cmp(struct topic A, struct topic B)
{
    if (A.times == B.times)
        return A.t_name < B.t_name;
    return A.times > B.times;
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int N;
    string s;
    set<string> result, meta;
    map<string, int> mp;
    scanf("%d\n", &N);
    for (int i = 0; i < N; i++)
        {
            getline(cin, s);
            s.push_back('!');
            int len = s.size();
            meta.clear();
            for (int j = 0; j < len; j++)
                {
                    if (s[j] == '#')
                        {
                            while (s[j] == '#')
                                j++;
                            string tmp, t;
                            int p;
                            for (p = j; p < len; p++)
                                {
                                    if (s[p] == '#')
                                        break;
                                }
                            if (p - 1 - j > 0)
                                {
                                    tmp = s.substr(j, p - j);
                                    j = p;
                                    int flag = 1;
                                    for (auto iter : tmp)
                                        {
                                            if (isalpha(iter))
                                                {
                                                    t.push_back(tolower(iter));
                                                    flag = 1;
                                                }
                                            else if (isdigit(iter))
                                                t.push_back(iter);
                                            else if (iter == ' ')
                                                {
                                                    if (flag)
                                                        {
                                                            t.push_back(iter);
                                                            flag = 0;
                                                        }
                                                }
                                        }
                                    meta.insert(t);
                                }
                        }
                }
            for (auto iter : meta)
                {
                    mp[iter]++;
                    result.insert(iter);
                }
        }
    int x = 0;
    for (auto iter : result)
        {
            records[x].t_name = iter;
            records[x].times = mp[iter];
            x++;
        }
    string s1 = records[0].t_name;
    int t1 = records[0].times, t2 = 0, j = 1;
    while(j < x && records[j].times == records[j-1].times)
        {
            t2++,j++;
        }
    s1[0] = toupper(s1[0]);
    cout << s1 << endl;
    cout << t1 << endl;
    if(t2)printf("And %d more ...\n",t2);
    return 0;
}