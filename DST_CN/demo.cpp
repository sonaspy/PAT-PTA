// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */  
    string s = "fgh22";
    for(int i = 2; i > -1; i++){
        if(isalpha(s[i])){
            s.erase(i + 1, s.size());
            break;
        }
    }
    cout << s;
    
    return 0;
}
