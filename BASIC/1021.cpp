// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<iostream>
#include<map>
#include<string>
#define test() freopen("in","r",stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
  //test();
    map<char,int> mp;
    string s;
    cin >> s;
    for(auto iter : s){
        mp[iter] += 1;
    }
    for(auto iter: mp){
        printf("%c:%d\n",iter.first,iter.second);
    }
    return 0;
}