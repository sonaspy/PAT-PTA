// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<iostream>
#include<stack>
#include<map>
#define test() freopen("in","r",stdin)

using namespace std;
stack<char> OP;

int main(int argc, char const *argv[])
{
  test();
  map<char, int> priority;
  string Expr;
  cin >> Expr;
  bool flag1st = true;
  priority['-'] = 1, priority['+'] = 1;
  priority['*'] = 2, priority['/'] = 2;
  priority['('] = 3, priority[')'] = 3;
  for (int i = 0; i < Expr.size(); i++)
  {
    if (((i == 0 || Expr[i - 1] == '(') && (Expr[i] == '+' || Expr[i] == '-')) || (Expr[i] >= '0' && Expr[i] <= '9'))
    {
      if (!flag1st)
        cout << " ";
      if (Expr[i] != '+')
        cout << Expr[i];
      while (Expr[i + 1] == '.' || (Expr[i + 1] >= '0' && Expr[i + 1] <= '9'))
      {
        i++;
        cout << Expr[i];
      }
      flag1st = false;
    }
    else
    {
      if (OP.empty() || priority[Expr[i]] > priority[OP.top()]){
        if(Expr[i] == '('){
          priority['('] = 0, priority[')'] = 0;
        }
        OP.push(Expr[i]);
      }
      else if (priority[Expr[i]] <= priority[OP.top()]){
        if(Expr[i] == ')'){
          priority['('] = 3, priority[')'] = 3;
        }
        while(!OP.empty()){
          if(OP.top() != '(')
            cout << " " << OP.top();
          OP.pop();
        }
      }
    }
  }
  while (!OP.empty())
  {
    cout << ' ' << OP.top();
    OP.pop();
  }
  return 0;
}