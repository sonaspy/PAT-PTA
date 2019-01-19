// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#define test() freopen("in","r",stdin)

using namespace std;
int main(int argc, char const *argv[])
{
    /* code */
  //test();
    set<char> set1;
    string s1, s2;
    cin >> s1 >> s2;
    transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
    transform(s2.begin(), s2.end(), s2.begin(), ::toupper);
    for(auto iter : s1)
        set1.insert(iter);
    for(auto iter : s2)
        if(set1.count(iter))
            set1.erase(iter);
    for(auto i : s1)
        if(set1.count(i)){
            cout << i;
            set1.erase(i);
        }
    return 0;
}