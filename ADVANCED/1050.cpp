// author -sonaspy@outlook.com 
// coding - utf_8 

#include<iostream>
#include<string>
#include<unordered_map>
#define test() freopen("in","r",stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    string s1,s2;
    getline(cin, s1);
    getline(cin, s2);
    unordered_map<char,int> mp;
    for(auto i : s2) {++mp[i];}
    for(auto j : s1) {if(!mp[j]) cout << j;}
    return 0;
}