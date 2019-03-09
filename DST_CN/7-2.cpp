// author -  newguo@sonaspy.cn
// coding - utf_8

#include<iostream>

#define test() freopen("in","r",stdin)

using namespace std;



#include <iostream>
#include <map>
#include <set>
using namespace std;
map<int, int> ExpAndNumA, ExpAndNumB, result;
set<int> ExpA, ExpB, resultSet;
void input(map<int, int> &SomeoneMap, set<int> &SomeoneSet, int N)
{
    for (int i = 0; i < N; i++)
        {
            int num, exp;
            cin >> num >> exp;
            SomeoneMap[exp] = num;
            SomeoneSet.insert(exp);
        }
}
void add()
{
    for (auto it = ExpA.begin(); it != ExpA.end(); it++)
        {
            resultSet.insert(*it);
            result[*it] = ExpAndNumA[*it];
        }
    for (auto it = ExpB.begin(); it != ExpB.end(); it++)
        {
            if (!result.count(*it))
                {
                    resultSet.insert(*it);
                    result[*it] = ExpAndNumB[*it];
                }
            else
                result[*it] += ExpAndNumB[*it];
        }
}
void multi()
{
    for (auto it = ExpA.begin(); it != ExpA.end(); it++)
        {
            for (auto it2 = ExpB.begin(); it2 != ExpB.end(); it2++)
                {
                    int newExp = *it + *it2;
                    int newNum = ExpAndNumA[*it] * ExpAndNumB[*it2];
                    if (result.count(newExp) == 0)
                        {
                            resultSet.insert(newExp);
                            result[newExp] = newNum;
                        }
                    else
                        result[newExp] += newNum;
                }
        }
}
void output()
{
    bool flag = 0;
    for (auto rit = resultSet.rbegin(); rit != resultSet.rend(); rit++)
        {
            if (result[*rit] != 0)
                {
                    flag = 1;
                    if (rit == resultSet.rbegin())
                        {
                            cout << result[*rit] << " " << *rit;
                        }
                    else
                        {
                            cout << " " << result[*rit] << " " << *rit;
                        }
                }
        }
    if (!flag)
        cout << "0 0";
}
int main(int argc, char const *argv[])
{
    /* code */
    int N1, N2;
    cin >> N1;
    input(ExpAndNumA, ExpA, N1);
    cin >> N2;
    input(ExpAndNumB, ExpB, N2);
    result.clear();
    resultSet.clear();
    multi();
    output();
    cout << endl;
    result.clear();
    resultSet.clear();
    add();
    output();
    return 0;
}
