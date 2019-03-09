#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include<list>
using namespace std;
string str, tmp;
stack<int> s;
list<int> ls;
int flag = 0;
int main()
{
    getline(cin, str);
    istringstream it(str);
    bool isfirst = true;
    int idx = str.size() - 2;
    while (it >> tmp)
        {
            if(tmp == ".")flag = 1;
            s.push(tmp.size());
        }
    while (!s.empty())
        {
            if (isfirst)
                {
                    isfirst = false;
                    if(flag == 1)
                        {
                            s.pop();
                            ls.push_front(s.top());
                        }
                    else
                        {
                            ls.push_front(s.top()-1);
                        }
                }
            else
                ls.push_front(s.top());
            s.pop();
        }
    cout << ls.front();
    ls.pop_front();
    list<int>::iterator p ;
    for( p =ls.begin(); p != ls.end(); p++)
        cout << " " << *p;
    return 0;
}
