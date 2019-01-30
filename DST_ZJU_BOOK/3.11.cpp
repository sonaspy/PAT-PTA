// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <stack>
#include <cmath>
#include <unordered_map>
#define test() freopen("in", "r", stdin)

using namespace std;
stack<int> oprand;
stack<char> oprator;
stack<int> number;
int getNum()
{
    int expr = 0, num = 0;
    while (number.size())
    {
        num += number.top() * pow(10, expr);
        number.pop();
        expr++;
    }
    return num;
}
int main(int argc, char const *argv[])
{
    /* code */
    test();
    string s, expression;
    unordered_map<char, int> mp;
    mp['+'] = 1, mp['-'] = 1, mp['/'] = 2, mp['*'] = 2, mp['('] = 3, mp[')'] = 0;
    cin >> s, s.push_back('!');
    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]))
        {
            number.push(s[i] - '0');
            continue;
        }
        else
        {
            if (number.size())
                expression += to_string(getNum()) + " ";
            if (i == s.size() - 1)
                break;
            if (oprator.size() && mp[s[i]] < mp[oprator.top()])
            {
                if(s[i] == ')') mp['('] = 3;
                while (oprator.size())
                {
                    if (oprator.top()!= '(')
                        expression.push_back(oprator.top()), expression.push_back(' ');
                    oprator.pop();
                }
            }
            else
            {
                if (s[i] == '(')
                    mp['('] = 0;
                oprator.push(s[i]);
            }
        }
    }
    while (oprator.size())
    {
        expression.push_back(oprator.top());
        expression.push_back(' ');
        oprator.pop();
    }
    expression.pop_back();
    cout << expression;


    return 0;
}