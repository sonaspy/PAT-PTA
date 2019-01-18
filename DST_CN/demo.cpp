// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <string>
#include<sstream>
#include<algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    string s = "3 4 2 a c";
    s = s.substr(4,s.size()-4);
    cout << s;
    return 0;
}
