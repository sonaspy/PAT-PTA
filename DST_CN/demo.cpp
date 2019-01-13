// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */  
    string s = "fgh22";
    string t;
    for(auto iter: s){
        if(isalpha(iter)){
            t.push_back(towlower(iter));
        }
    }
    cout << t;

    return 0;
}
