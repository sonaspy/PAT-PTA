// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <string>
#include <list>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
  //test();
    list<string> container;
    string s;
    int flag = 1;
    while(cin >> s)
        container.push_front(s);
    for(auto iter : container){
        if (flag)
        {
            flag = 0;
            cout << iter;
        }
        else
            cout << " " << iter;
    }
    return 0;
}