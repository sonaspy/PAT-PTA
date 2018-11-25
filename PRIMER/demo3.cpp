#include <stdio.h>
#include <stack>
#include <iostream>
using namespace std;
int main()
{
  int a, n;
  cin >> a >> n;
  if (n == 0) //测试点最小A和N
  {
    cout << 0 << endl;
    return 0;
  }
  stack<int> cnt; //栈用来存储要输出的位
  int flag = 0;   //保存输出以后还剩的余数
  for (int i = n; i >= 1; i--)
  {
    int temp = flag + a * i;
    cnt.push(temp % 10);
    flag = temp / 10;
  }

  if (flag != 0)
    cout << flag;
  while (!cnt.empty())
  {
    cout << cnt.top();
    cnt.pop();
  }
  cout << endl;
  return 0;
}