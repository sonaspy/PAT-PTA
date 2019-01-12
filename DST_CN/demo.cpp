// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */  
    string s = "fgh";
    string d = s.substr(s.size() - 3);
    cout << int(d[0]);
    
    return 0;
}
