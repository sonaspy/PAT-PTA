#include <iostream>
#include <string>
#include <sstream>
#include <stack>
using namespace std;
string str, tmp;
stack<string> s;
int main()
{
  getline(cin, str);
  istringstream it(str);
  bool isfirst = true;
  while (it >> tmp)
  {
    s.push(tmp);
  }
  while (!s.empty())
  {
    if (isfirst)
    {
      isfirst = false;
      cout << s.top();
    }
    else
    {
      cout << " " << s.top();
    }
    s.pop();
  }
  return 0;
}
