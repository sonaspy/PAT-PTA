// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<iostream>
#include<stack>
#include<string>
#include<sstream>
#include<algorithm>
#define test() freopen("in","r",stdin)

using namespace std;

stack<double> operand;

int main(int argc, char const *argv[])
{
    /* code */
    test();
    bool error = false;
    string Exp, op;
    getline(cin, Exp);
    reverse(Exp.begin(), Exp.end());
    istringstream it(Exp);
    while(it >> op){
      if(op == "/" || op == "*" || op == "+" || op == "-"){
        int v1, v2, newop;
        v1 = operand.top();operand.pop();
        v2 = operand.top();operand.pop();
        if(op == "/"){
          if(v2 == 0){error = true;break;}
          newop = v1 * 1.0 / v2;
        }
        else if(op == "*") newop = v1 * v2 * 1.0;
        else if(op == "+") newop = v1 + v2 + 0.0;
        else newop  = v1 - v2 + 0.0;
        operand.push(newop);
      } 
      else{
          reverse(op.begin(),op.end());
          double var;istringstream ss(op);
          ss >> var;
          operand.push(var);
      }
    }
    if(error) cout << "ERROR" ;
    else printf("%.1f", operand.top());
    return 0;
}