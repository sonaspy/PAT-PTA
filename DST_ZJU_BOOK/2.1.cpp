// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <stack>
#include <string>
#include<cmath>
#define test() freopen("in", "r", stdin)

using namespace std;
stack<int> oprand;
stack<char> oprator;
stack<int> number;
int getNum()
{
    int expr = 0, num = 0;
    while(number.size()){
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
    string s;
    cin >> s;
    for (auto iter : s)
    {
        if (!(isdigit(iter) || iter == '-' || iter == '+'|| iter == '*' || iter == '=' || iter == '/'))
        {
            cout << "ERROR";
            return 0;
        }
        if (isdigit(iter))
            number.push(iter - '0');
        else
        {
            oprand.push(getNum());
            if(oprator.size() && oprand.size() == 2){
                char c = oprator.top();
                oprator.pop();
                int a1, a2, res;
                a1 = oprand.top();oprand.pop();
                a2 = oprand.top(); oprand.pop();
                if(c == '+') res = a1 + a2;
                else if(c == '-') res = a2 - a1;
                else if(c == '/') {
                    if(a1 == 0){
                        cout << "ERROR";
                        return 0;
                    }
                    res = a2 / a1;
                    }
                else if(c == '*') res = a2 * a1;
                oprand.push(res);
            }
            oprator.push(iter);
        }
    }
    cout << oprand.top();
    return 0;
}